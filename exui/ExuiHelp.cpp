#include "ExuiHelp.h"

EX_UI_CMDINFO

#ifdef _WIN64
#define POINTER_TYPE ULONGLONG
#else
#define POINTER_TYPE DWORD
#endif


typedef   BOOL(__stdcall * ProcDllMain)(HINSTANCE, DWORD, LPVOID);
HINSTANCE WINAPI 	MemLoadLibrary(const BYTE * data, int DataLength)
{
	PIMAGE_DOS_HEADER dos_header; // DOS头
	PIMAGE_NT_HEADERS old_header; // PE头
	unsigned char *code, *headers;
	SIZE_T locationDelta;
	BOOL successfull;

	// 获取DOS头指针，并检查DOS头
	dos_header = (PIMAGE_DOS_HEADER)data;
	if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) { return NULL; }
	// 获取PE头指针，并检查PE头
	old_header = (PIMAGE_NT_HEADERS)&((const unsigned char *)(data))[dos_header->e_lfanew];
	if (old_header->Signature != IMAGE_NT_SIGNATURE) { return NULL; }
	// 在"PEHeader.OptionalHeader.ImageBase"处预定"PEHeader.OptionalHeader.SizeOfImage"字节的空间
	code = (unsigned char *)VirtualAlloc((LPVOID)(old_header->OptionalHeader.ImageBase), old_header->OptionalHeader.SizeOfImage, MEM_RESERVE, PAGE_READWRITE);

	if (code == NULL) {
		// try to allocate memory at arbitrary position
		code = (unsigned char *)VirtualAlloc(NULL, old_header->OptionalHeader.SizeOfImage, MEM_RESERVE, PAGE_READWRITE);
		if (code == NULL) { return NULL; }
	}

	// 在进程的默认堆上分配"sizeof(MEMORYMODULE)"字节的空间用于存放MEMORYMODULE结构体
	// 方便函数末尾将该结构体指针当作返回值返回
	unsigned char *codeBase = code;

	HMODULE * modules = NULL;	int numModules = 0;

	// 一次性从code地址处将整个映像所需的内存区域都分配
	VirtualAlloc(code, old_header->OptionalHeader.SizeOfImage, MEM_COMMIT, PAGE_READWRITE);
	headers = code;
	// 拷贝DOS头 + DOS STUB + PE头到headers地址处
	memcpy(headers, dos_header, dos_header->e_lfanew + old_header->OptionalHeader.SizeOfHeaders);
	PIMAGE_NT_HEADERS  result_headers = (PIMAGE_NT_HEADERS)&((const unsigned char *)(headers))[dos_header->e_lfanew];
	// 更新"MEMORYMODULE.PIMAGE_NT_HEADERS"结构体中的基地址
	result_headers->OptionalHeader.ImageBase = (POINTER_TYPE)code;
	// 从dll文件内容中拷贝每个section（节）的数据到新的内存区域

	//CopySections(data, old_header, &result);
	{
		int i, size;
		unsigned char *dest;
		PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(result_headers);
		for (i = 0; i < result_headers->FileHeader.NumberOfSections; i++, section++) {
			if (section->SizeOfRawData == 0) {
				// section doesn't contain data in the dll itself, but may define
				// uninitialized data
				size = old_header->OptionalHeader.SectionAlignment;
				if (size > 0) {
					dest = (unsigned char *)VirtualAlloc(codeBase + section->VirtualAddress, size, MEM_COMMIT, PAGE_READWRITE);
					section->Misc.PhysicalAddress = (POINTER_TYPE)dest;
					memset(dest, 0, size);
				}
				// section is empty
				continue;
			}
			// commit memory block and copy data from dll
			dest = (unsigned char *)VirtualAlloc(codeBase + section->VirtualAddress, section->SizeOfRawData, MEM_COMMIT, PAGE_READWRITE);
			memcpy(dest, data + section->PointerToRawData, section->SizeOfRawData);
			section->Misc.PhysicalAddress = (POINTER_TYPE)dest;
		}
	}

	// 检查加载到进程地址空间的位置和之前PE文件中指定的基地址是否一致，如果不一致，则需要重定位
	locationDelta = (SIZE_T)(code - old_header->OptionalHeader.ImageBase);
	if (locationDelta != 0) {
		//PerformBaseRelocation(&result, locationDelta);
		{
			DWORD i;
			PIMAGE_DATA_DIRECTORY directory = &result_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
			if (directory->Size > 0) {
				PIMAGE_BASE_RELOCATION relocation = (PIMAGE_BASE_RELOCATION)(codeBase + directory->VirtualAddress);
				for (; relocation->VirtualAddress > 0; ) {
					unsigned char *dest = codeBase + relocation->VirtualAddress;
					unsigned short *relInfo = (unsigned short *)((unsigned char *)relocation + sizeof(IMAGE_BASE_RELOCATION));
					for (i = 0; i < ((relocation->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / 2); i++, relInfo++)
					{
						DWORD *patchAddrHL;
#ifdef _WIN64
						ULONGLONG *patchAddr64;
#endif
						int type, offset;

						// the upper 4 bits define the type of relocation
						type = *relInfo >> 12;
						// the lower 12 bits define the offset
						offset = *relInfo & 0xfff;

						switch (type)
						{
						case IMAGE_REL_BASED_ABSOLUTE:
							// skip relocation
							break;

						case IMAGE_REL_BASED_HIGHLOW:
							// change complete 32 bit address
							patchAddrHL = (DWORD *)(dest + offset);
							*patchAddrHL += locationDelta;
							break;

#ifdef _WIN64
						case IMAGE_REL_BASED_DIR64:
							patchAddr64 = (ULONGLONG *)(dest + offset);
							*patchAddr64 += delta;
							break;
#endif
						default:			break;
						}
					}
					// advance to next relocation block
					relocation = (PIMAGE_BASE_RELOCATION)(((char *)relocation) + relocation->SizeOfBlock);
				}
			}
		}
	}

	// 加载依赖dll，并构建"PEHeader.OptionalHeader.DataDirectory.Image_directory_entry_import"导入表
	//BuildImportTable(&result)
	{
		PIMAGE_DATA_DIRECTORY directory = &result_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
		if (directory->Size > 0)
		{
			PIMAGE_IMPORT_DESCRIPTOR importDesc = (PIMAGE_IMPORT_DESCRIPTOR)(codeBase + directory->VirtualAddress);
			for (; !IsBadReadPtr(importDesc, sizeof(IMAGE_IMPORT_DESCRIPTOR)) && importDesc->Name; importDesc++) {
				POINTER_TYPE *thunkRef;		FARPROC *funcRef;
				HMODULE handle = LoadLibraryA((LPCSTR)(codeBase + importDesc->Name));
				if (handle == NULL) {
					VirtualFree((LPVOID)codeBase, 0, MEM_RELEASE);
					return NULL;
					break;
				}
				modules = (HMODULE *)realloc(modules, (numModules + 1)*(sizeof(HMODULE)));
				if (modules == NULL)
				{
					VirtualFree((LPVOID)codeBase, 0, MEM_RELEASE);
					return NULL;
					break;
				}
				modules[numModules++] = handle;
				if (importDesc->OriginalFirstThunk)
				{
					thunkRef = (POINTER_TYPE *)(codeBase + importDesc->OriginalFirstThunk);
					funcRef = (FARPROC *)(codeBase + importDesc->FirstThunk);
				}
				else 
				{
					// no hint table
					thunkRef = (POINTER_TYPE *)(codeBase + importDesc->FirstThunk);
					funcRef = (FARPROC *)(codeBase + importDesc->FirstThunk);
				}

				for (; *thunkRef; thunkRef++, funcRef++) {
					if (IMAGE_SNAP_BY_ORDINAL(*thunkRef)) 
					{
						*funcRef = (FARPROC)GetProcAddress(handle, (LPCSTR)IMAGE_ORDINAL(*thunkRef));
					}
					else
					{
						PIMAGE_IMPORT_BY_NAME thunkData = (PIMAGE_IMPORT_BY_NAME)(codeBase + (*thunkRef));
						*funcRef = (FARPROC)GetProcAddress(handle, (LPCSTR)&thunkData->Name);
					}

					if (*funcRef == 0) 
					{
						VirtualFree((LPVOID)codeBase, 0, MEM_RELEASE);
						return NULL;
						break;
					}
				}


			}
		}
	}


	// 根据每个Section的"PEHeader.Image_Section_Table.Characteristics"属性来设置内存页的访问属性；
	// 如果被设置为"discardable"属性，则释放该内存页

	//FinalizeSections(&result);
	{
		int i;
		PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(result_headers);
#ifdef _WIN64
		POINTER_TYPE imageOffset = (module->headers->OptionalHeader.ImageBase & 0xffffffff00000000);
#else
#define imageOffset 0
#endif

		// loop through all sections and change access flags
		for (i = 0; i < result_headers->FileHeader.NumberOfSections; i++, section++) {
			DWORD protect, oldProtect, size;
			int executable = (section->Characteristics & IMAGE_SCN_MEM_EXECUTE) != 0;
			int readable = (section->Characteristics & IMAGE_SCN_MEM_READ) != 0;
			int writeable = (section->Characteristics & IMAGE_SCN_MEM_WRITE) != 0;

			if (section->Characteristics & IMAGE_SCN_MEM_DISCARDABLE) {
				// section is not needed any more and can safely be freed
				VirtualFree((LPVOID)((POINTER_TYPE)section->Misc.PhysicalAddress | imageOffset), section->SizeOfRawData, MEM_DECOMMIT);
				continue;
			}

			// determine protection flags based on characteristics

			static int ProtectionFlags[2][2][2] = {
	{
					// not executable
					{PAGE_NOACCESS, PAGE_WRITECOPY},
					{PAGE_READONLY, PAGE_READWRITE},
				}, {
					// executable
					{PAGE_EXECUTE, PAGE_EXECUTE_WRITECOPY},
					{PAGE_EXECUTE_READ, PAGE_EXECUTE_READWRITE},
				},
			};

			protect = ProtectionFlags[executable][readable][writeable];

			if (section->Characteristics & IMAGE_SCN_MEM_NOT_CACHED) {
				protect |= PAGE_NOCACHE;
			}

			// determine size of region
			size = section->SizeOfRawData;
			if (size == 0) {
				if (section->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) {
					size = result_headers->OptionalHeader.SizeOfInitializedData;
				}
				else if (section->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) {
					size = result_headers->OptionalHeader.SizeOfUninitializedData;
				}
			}
			if (size > 0)
			{
				// change memory access flags
				VirtualProtect((LPVOID)((POINTER_TYPE)section->Misc.PhysicalAddress | imageOffset), size, protect, &oldProtect);
			}
		}

#ifndef _WIN64
#undef imageOffset
#endif
	}
	// 获取DLL的入口函数指针，并调用
	if (result_headers->OptionalHeader.AddressOfEntryPoint != 0) 
	{

		ProcDllMain	DllEntry = (ProcDllMain)(code + result_headers->OptionalHeader.AddressOfEntryPoint);
		if (DllEntry == 0)
		{
			VirtualFree((LPVOID)codeBase, 0, MEM_RELEASE);
			return NULL;
		}

		// notify library about attaching to process
		successfull = (*DllEntry)((HINSTANCE)code, DLL_PROCESS_ATTACH, 0);
		if (!successfull)
		{
			(*DllEntry)((HINSTANCE)code, DLL_PROCESS_DETACH, 0);
			VirtualFree((LPVOID)codeBase, 0, MEM_RELEASE);
			return NULL;
		}

	}
	return (HINSTANCE)codeBase;
}

FARPROC WINAPI   MemGetProcAddress(HINSTANCE  MemDll, LPCSTR lpProcName)
{

	if (!MemDll) { return NULL; }
	//新的dos头
	PIMAGE_DOS_HEADER	pDosHeader = (PIMAGE_DOS_HEADER)MemDll;
	//新的pe头地址
	PIMAGE_NT_HEADERS	pNTHeader = (PIMAGE_NT_HEADERS)((int)MemDll + (pDosHeader->e_lfanew));
	

	if (pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress == 0 || pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size == 0) { return NULL; }
	DWORD OffsetStart = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	DWORD Size = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

	PIMAGE_EXPORT_DIRECTORY pExport = (PIMAGE_EXPORT_DIRECTORY)((DWORD)MemDll + pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
	int iBase = pExport->Base;
	int iNumberOfFunctions = pExport->NumberOfFunctions;
	int iNumberOfNames = pExport->NumberOfNames; //<= iNumberOfFunctions
	LPDWORD pAddressOfFunctions = (LPDWORD)(pExport->AddressOfFunctions + (int)MemDll);
	LPWORD  pAddressOfOrdinals = (LPWORD)(pExport->AddressOfNameOrdinals + (int)MemDll);
	LPDWORD pAddressOfNames = (LPDWORD)(pExport->AddressOfNames + (int)MemDll);

	int iOrdinal = -1;
	if (((DWORD)lpProcName & 0xFFFF0000) == 0) { iOrdinal = (DWORD)lpProcName & 0x0000FFFF - iBase; } //IT IS A ORDINAL!
	else     //use name
	{
		int iFound = -1;
		for (int i = 0; i < iNumberOfNames; i++)
		{
			if (strcmp((char *)(pAddressOfNames[i] + (int)MemDll), lpProcName) == 0) { iFound = i; break; }
		}
		if (iFound >= 0) { iOrdinal = (int)(pAddressOfOrdinals[iFound]); }
	}

	if (iOrdinal < 0 || iOrdinal >= iNumberOfFunctions) { return NULL; }
	else
	{
		DWORD pFunctionOffset = pAddressOfFunctions[iOrdinal];
		if (pFunctionOffset > OffsetStart && pFunctionOffset < (OffsetStart + Size)) { return NULL; }//maybe Export Forwarding
		else { return (FARPROC)(pFunctionOffset + (int)MemDll); }
	}

}

void WINAPI MemFreeDll(HINSTANCE *   MemDll)
{
	if (MemDll) {
		//新的dos头
		PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)MemDll;
		//新的pe头地址
		PIMAGE_NT_HEADERS  pNTHeader = (PIMAGE_NT_HEADERS)((int)MemDll + (pDosHeader->e_lfanew));
		ProcDllMain  pDllMain = (ProcDllMain)(pNTHeader->OptionalHeader.AddressOfEntryPoint + (DWORD)MemDll);
		if (pDllMain) { pDllMain((HINSTANCE)MemDll, DLL_PROCESS_DETACH, 0); }
		VirtualFree((LPVOID)MemDll, 0, MEM_RELEASE);
	}
}

























//此下为通用函数
BinEx_P dtp(字节集  ebin)
{
	int tmp[]{ (int)ebin.取指针地址(), ebin.长度 };
	return 	CreateBinEx(tmp, -10);
}

//CVolMem ptd(BinEx_P  ebin)
//{
//	return  ebin ? CVolMem((int*)ebin + 2, *((int*)ebin + 1)) : NULL;
//}

/*---------------------------------------------------------------------------*/

BinEx_P rtp(int  rid)
{
	printf("读入失败");
	int tmp[]{1,8,rid,2019};
	
	return  CreateBinEx(tmp, -2);
}

//
BinEx_P dtpdv(字节集  ebin,int rid)
{
	return	ebin.是否为空() ? rtp(rid) : dtp(ebin);
}
//
//ImageEX_P atimage(CVolMem  ebin)
//{
//	return 	(ImageEX_P)dtp(ebin);
//
//}

ImageEX_P atimage(int  ebin)
{

	return 	(ImageEX_P)ebin;

}



BOOL RETURN_BOOL(int p)
{
	return  (BOOL)p;
}

int RETURN_INT(int p)
{
	return  p;
}



 /*CVolMem RETURN_CVolMem(int p)
{
	if (p &&  (*((int*)p) == 5)) { p = (int)GetImageData((ImageEX_P)p); }
	return  p? CVolMem((int*)p + 2, *((int*)p + 1)): NULL;
}*/

 StrEx_P stp(LPCWSTR  estr)
 {
	 return 	CreateBinEx((StrEx_P)estr, -6);
 }

 LPCWSTR pts(StrEx_P  estr)
 {
	 return  estr ? LPCWSTR((wchar_t*)estr +4) : NULL;
 }
 LPCWSTR RETURN_String(int p)
 {
	 return  p ? LPCWSTR((wchar_t*)p + 4) : NULL;
 }
 

 //…………………………………………………………………………………………此下为窗口_win组件函数&……………………………………………………………………………………………………………………………………………………
 INT WindowBoxEx::Create(INT 模式, INT 位置, INT 左边, INT 顶边, INT 宽度, INT 高度, void* 回调函数 , BOOL 可视, BOOL 禁止, LPCSTR 图标, LPCWSTR 标题, BOOL 总在最前, BOOL 任务栏显示, BOOL 退出键关闭, LPCWSTR 类名, INT 类风格, INT 扩展风格, INT 窗口风格, INT 标识值)
 {
	 int InitAttr[4]{ (int)&control,(int)回调函数,(int)this,标识值 };
	 control = (int)Create_WindowBoxEx(模式, 位置, (HWND)0, 左边, 顶边, 宽度, 高度, -1, 可视, 禁止, dtpdv(读入文件(图标), Rc_Skin_LogoEx), stp(标题), 总在最前, 任务栏显示, 退出键关闭, stp(类名), 类风格, 扩展风格, 窗口风格, (int)InitAttr); 
	 return control;
 }
 /*INT CALLBACK WindowBoxEx::Eventpro_WindowBoxEx(INT hwnd, INT msg, INT wParam, INT lParam)
 {	
	 printf("testcallback");
	 WindowBoxEx* WinExthis = ((WindowBoxEx*)GetProp((HWND)hwnd, TEXT("ExuiWindow_BindThis")));
	 return (0);
	 
	 }*/
	 
 INT WindowBoxEx::GetControlType() {
	 return 100;

 }
 
 //HANDLE 堆栈句柄;
 //
 //LPVOID 申请内存块(INT len) {
	// 
	// if (堆栈句柄 == 0) {
	//	 堆栈句柄 = GetProcessHeap();
	// }
	// return(HeapAlloc(堆栈句柄, 8, len));

 //}
 //void 释放内存块(LPVOID addr) {
	// 
	// if (堆栈句柄==0) {
	//	 堆栈句柄 = GetProcessHeap();
	// }
	// HeapFree(堆栈句柄, 0, addr);
 //
 //}

 

 

 字节集 PackFontEx(FontInfo FontInfo) {
	 HANDLE 堆栈句柄= GetProcessHeap();
	 LPVOID 内存指针 = HeapAlloc(堆栈句柄, 8, 84);
	 byte 字体字节集[84];
	 byte* 数组指针;
	 字节集 字体数据;
	 
	 
	 
	 
	

	 RtlMoveMemory(内存指针, FontInfo.名称.数据, FontInfo.名称.长度);
	 RtlMoveMemory((LPVOID)((INT)内存指针 + 64), &FontInfo.大小, 20);
	 
	 
	 数组指针 = (byte*)内存指针;
	 
	 for (int i = 0; i < 84; i++)
	 {
		 字体字节集[i] = 数组指针[i];
	 }

	 字体数据.数据 = 字体字节集;
	 字体数据.长度 = 84;
	 HeapFree(堆栈句柄, HEAP_ZERO_MEMORY, 内存指针);
	 return(字体数据);
	 
 }
 
 char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)

 {

	 LPSTR pszOut = NULL;

	 try

	 {

		 if (lpwszStrIn != NULL)

		 {

			 int nInputStrLen = wcslen(lpwszStrIn);

			 // Double NULL Termination 

			 int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;

			 pszOut = new char[nOutputStrLen];

			 if (pszOut)

			 {

				 memset(pszOut, 0x00, nOutputStrLen);

				 WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);

			 }

		 }

	 }

	 catch (std::exception e)

	 {

	 }

	 return pszOut;

 }
 


 字节集 生成字体Ex(LPCWSTR 字体名称, INT 字体大小, int 字体风格, int 绘画模式, int 渲染参数, int 渲染参数1, int 渲染参数2) {
	 字节集 返回字体;
	 FontInfo 字体数据;
	 

	 字体数据.名称 = 文本到字节集(字体名称);
	 

	 
	 字体数据.大小 = 字体大小;
	 字体数据.风格 = 字体风格;
	 字体数据.渲染模式 = 绘画模式;
	 字体数据.渲染模式1 = 渲染参数1;
	 字体数据.渲染模式2 = 渲染参数2;

	 返回字体 = PackFontEx(字体数据);
	 
	 return (返回字体);



 }


 INT 组件居中取左(int 父组件宽度, INT 组件宽度) {

	 INT 组件左边 =(父组件宽度 - 组件宽度)/2;
	 
	 return 组件左边;

 
 
 }

 








 //…………………………………………………………………………………………此下为窗口EX组件函数&……………………………………………………………………………………………………………………………………………………

 int WindowEx:: Create(BaseEx& 父级组件, INT 左边, INT 顶边, INT 宽度, INT 高度, BOOL 可视, BOOL 禁止, void* 回调函数, INT 透明度, INT 穿透模式, INT 焦点权重, LPCSTR 鼠标光标, INT 标识值, LPCSTR 皮肤, LPCSTR 图标, LPCWSTR 标题, LPCSTR 字体, INT 字体色, INT 分层透明, INT 拖动模式, INT 尺寸调整模式, INT 最大化模式, LPCSTR 控制钮, INT 控制钮动画参数, LPCSTR 扩展元素, LPCSTR 布局器) {
	 int InitAttr[4]{ (int)&control,(int)回调函数,(int)this,标识值 };
	 int control_;
	 /*if (父级组件.GetControlType() != ControlType_WindowBoxEx) {
		 control_ = 父级组件.control;
	 }
	 else
	 {
		 control_ = 0;

	 }*/


	 control = (int)CreateControl_WindowEx((void*)(父级组件.GetControlType() != ControlType_WindowBoxEx ? 父级组件.control : 0), (HWND)(父级组件.GetControlType() == ControlType_WindowBoxEx ? 父级组件.control : 0), 左边, 顶边, 宽度, 高度, (void*)-1, 0, 可视, 禁止, 透明度, 穿透模式, 焦点权重, dtpdv(读入文件(鼠标光标), Rc_Cur_WindowEx), (int)InitAttr, dtpdv(读入文件(皮肤), Rc_Skin_WindowEx), dtpdv(读入文件(图标), 0), stp(标题), dtp(读入文件(字体)), 字体色, 分层透明, 拖动模式, 尺寸调整模式, 最大化模式, dtpdv(读入文件(控制钮), Rc_Skin_WindowExBtn), 控制钮动画参数, dtp(读入文件(扩展元素)), dtp(读入文件(布局器)));
	 return  control;

 }

 LPCWSTR WindowEx::Gettittle()
 {

	 return pts((void*)GetAttribute_WindowEx((void*)control, WindowEx_Attr_Text));
	 
 }
 //…………………………………………………………………………………………此下为分组框EX组件函数&……………………………………………………………………………………………………………………………………………………

 int MinutesboxEx::Create(BaseEx& 父级组件, INT 左边, INT 顶边, INT 宽度, INT 高度, BOOL 可视, BOOL 禁止, void* 回调函数, INT 透明度, INT 穿透模式, INT 焦点权重, LPCSTR 鼠标光标, INT 标识值, LPCSTR 皮肤, LPCSTR 图标, INT 图标宽,INT 图标高,LPCWSTR 标题, INT 标题对齐方式,字节集 字体, INT 字体色,   LPCSTR 扩展元素, LPCSTR 布局器)
 {
	 int InitAttr[4]{ (int)&control,(int)回调函数,(int)this,标识值 };
	 control = (int)CreateControl_MinutesboxEx((void*)(父级组件.GetControlType() != ControlType_WindowBoxEx ? 父级组件.control : 0), (HWND)(父级组件.GetControlType() == ControlType_WindowBoxEx ? 父级组件.control : 0), 左边, 顶边, 宽度, 高度, (void*)-1, 0, 可视, 禁止, 透明度, 穿透模式, 焦点权重, dtp(读入文件(鼠标光标)), (int)InitAttr, dtpdv(读入文件(皮肤), Rc_Skin_MinutesboxEx), dtp(读入文件(图标)), 图标宽, 图标高, stp(标题), 标题对齐方式, dtp(字体), 字体色, dtp(读入文件(扩展元素)), dtp(读入文件(布局器)));
	 return  control;
 }
 int MinutesboxEx::GetHeight() {

	 return ControlGetHeight((void*)control);

 }
 void MinutesboxEx::SetHeight(int high) {

	 return ControlSetHeight((void*)control, high);

 }


 void MinutesboxEx::SetWidth(int width) {

	 return ControlSetWidth((void*)control, width);

 }

 int MinutesboxEx::GetWidth() {

	 return ControlGetWidth((void*)control);
 }
 //…………………………………………………………………………………………此下为标签EX组件函数&……………………………………………………………………………………………………………………………………………………

 int LabelEx::Create(BaseEx& 父级组件, INT 左边, INT 顶边, INT 宽度, INT 高度, BOOL 可视, BOOL 禁止, void* 回调函数, INT 透明度, INT 穿透模式, INT 焦点权重, LPCSTR 鼠标光标, INT 标识值, LPCWSTR 标题, INT 对齐方式, INT 背景色, LPCSTR 字体, INT 字体色, INT 旋转角度, LPCSTR 扩展元素, LPCSTR 布局器)

 {
	 int InitAttr[4]{ (int)&control,(int)回调函数,(int)this,标识值 };
	 control = (int)CreateControl_LabelEx((void*)(父级组件.GetControlType() != ControlType_WindowBoxEx ? 父级组件.control : 0), (HWND)(父级组件.GetControlType() == ControlType_WindowBoxEx ? 父级组件.control : 0), 左边, 顶边, 宽度, 高度, (void*)-1, 0, 可视, 禁止, 透明度, 穿透模式, 焦点权重, dtp(读入文件(鼠标光标)), (int)InitAttr, stp(标题), 对齐方式, 背景色, dtp(读入文件(字体)), 字体色, 旋转角度, dtp(读入文件(扩展元素)), dtp(读入文件(布局器)));
	 return  control;
 }
 //…………………………………………………………………………………………此下为图片框EX组件函数&……………………………………………………………………………………………………………………………………………………

 int PictureBoxEx::Create(BaseEx& 父级组件, INT 左边, INT 顶边, INT 宽度, INT 高度, BOOL 可视, BOOL 禁止, void* 回调函数, INT 透明度, INT 穿透模式, INT 焦点权重, LPCSTR 鼠标光标, INT 标识值, LPCSTR 皮肤, LPCSTR 图片, INT 底图方式, INT 圆角度, BOOL 播放动画, INT 总帧数, INT 当前帧, INT 旋转角度, LPCSTR 扩展元素, LPCSTR 布局器)
 {
	 int InitAttr[4]{ (int)&control,(int)回调函数,(int)this,标识值 }; 
	 control = (int)CreateControl_PictureBoxEx((void*)(父级组件.GetControlType() != ControlType_WindowBoxEx ? 父级组件.control : 0), (HWND)(父级组件.GetControlType() == ControlType_WindowBoxEx ? 父级组件.control : 0), 左边, 顶边, 宽度, 高度, (void*)-1, 0, 可视, 禁止, 透明度, 穿透模式, 焦点权重, dtp(读入文件(鼠标光标)), (int)InitAttr, dtpdv(读入文件(皮肤), Rc_Skin_PictureBoxEx), dtp(读入文件(图片)), 底图方式, 圆角度, 播放动画, 总帧数, 当前帧, 旋转角度, dtp(读入文件(扩展元素)), dtp(读入文件(布局器)));
	 return  control;
 }

 int PictureBoxEx::GetHeight() {

	 return ControlGetHeight((void*)control);

 }
 void PictureBoxEx::SetHeight(int high) {

	 return ControlSetHeight((void*)control,high);

 }
 

 void PictureBoxEx::SetWidth(int width) {

	 return ControlSetWidth((void*)control, width);

 }

 int PictureBoxEx::GetWidth() {

	 return ControlGetWidth((void*)control);

 }