#include"file2mem.h"




int 字节集::取指针地址()
{	
	
	return (int)数据;
	
		
}
bool 字节集::是否为空() {
	if (长度==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void 写到文件(const char* 文件名,字节集 欲写入内容)

{
	byte* buffer=(byte*)(void*)欲写入内容.数据;

	ofstream ofs(文件名, ios::binary);

	copy(buffer, buffer + 欲写入内容.长度, ostream_iterator<char>(ofs));

	ofs.close();

}


字节集 文本到字节集(LPCWSTR 文本)
{
	char sourceBuf[200];
	字节集 返回数据;
	返回数据.数据 = new byte[200];


	memset(返回数据.数据, 0, sizeof(返回数据.数据));//初始化
	memcpy(返回数据.数据, 文本, wcslen(文本) + 1);
	返回数据.长度 = wcslen(文本) + 1;
	return 返回数据;

}




字节集 读入文件(const char* filename) 
{
	字节集 data;
	FILE* file;
	unsigned long fsize,i;
	unsigned char* buffer = NULL;
	file = fopen(filename, "rb");
	if (!file) {
		

		printf( "can't open file\n" );

		data.数据 = NULL;
		data.长度 = 0;
		return(data);
	}

	fseek(file, 0, SEEK_END);
	fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	

	buffer = (byte*)malloc(fsize + 1);

	if (!buffer) {
		printf("Memory error!\n" );
		fclose(file);
		data.数据 = NULL;
		data.长度 = 0;
		return(data);
		

	}

	fread(buffer, 1, fsize + 1, file);

	fclose(file);
	data.数据 = buffer;
	data.长度 = fsize;
	//for (i = 0; i < fsize; i++) {
		

		//printf("%d ", buffer[i]);
		//if (i % 32 == 31)printf("\n");
		//if (i % 4 == 3)printf(" ");
	//}
	printf("fsize == %ld\n", fsize);
	
	return(data);
}


byte* 读内存字节集(int Pid, int address, int length)
{
	HANDLE hProcess;
	//fhbyte = {};
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		//hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)进程ID);//PROCESS_VM_READ
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, Pid);
	}


	byte* p = new byte[length];//取空白字节集以做存储缓冲区
	memset(p, 0, length);//清空申请的缓存区
	ReadProcessMemory(hProcess, (LPCVOID)address, p, length, NULL);


	CloseHandle(hProcess);//关闭对象


	return p;//这里返回读取到的字节集的首地址




}


BOOL 写内存字节集(int Pid, int address, byte data[], int length)
{
	HANDLE hProcess;
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)Pid);//PROCESS_VM_READ


	}


	BOOL a = WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)data, length, 0);
	CloseHandle(hProcess);//关闭对象
	return a;
}








