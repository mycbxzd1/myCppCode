#include"file2mem.h"




int �ֽڼ�::ȡָ���ַ()
{	
	
	return (int)����;
	
		
}
bool �ֽڼ�::�Ƿ�Ϊ��() {
	if (����==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void д���ļ�(const char* �ļ���,�ֽڼ� ��д������)

{
	byte* buffer=(byte*)(void*)��д������.����;

	ofstream ofs(�ļ���, ios::binary);

	copy(buffer, buffer + ��д������.����, ostream_iterator<char>(ofs));

	ofs.close();

}


�ֽڼ� �ı����ֽڼ�(LPCWSTR �ı�)
{
	char sourceBuf[200];
	�ֽڼ� ��������;
	��������.���� = new byte[200];


	memset(��������.����, 0, sizeof(��������.����));//��ʼ��
	memcpy(��������.����, �ı�, wcslen(�ı�) + 1);
	��������.���� = wcslen(�ı�) + 1;
	return ��������;

}




�ֽڼ� �����ļ�(const char* filename) 
{
	�ֽڼ� data;
	FILE* file;
	unsigned long fsize,i;
	unsigned char* buffer = NULL;
	file = fopen(filename, "rb");
	if (!file) {
		

		printf( "can't open file\n" );

		data.���� = NULL;
		data.���� = 0;
		return(data);
	}

	fseek(file, 0, SEEK_END);
	fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	

	buffer = (byte*)malloc(fsize + 1);

	if (!buffer) {
		printf("Memory error!\n" );
		fclose(file);
		data.���� = NULL;
		data.���� = 0;
		return(data);
		

	}

	fread(buffer, 1, fsize + 1, file);

	fclose(file);
	data.���� = buffer;
	data.���� = fsize;
	//for (i = 0; i < fsize; i++) {
		

		//printf("%d ", buffer[i]);
		//if (i % 32 == 31)printf("\n");
		//if (i % 4 == 3)printf(" ");
	//}
	printf("fsize == %ld\n", fsize);
	
	return(data);
}


byte* ���ڴ��ֽڼ�(int Pid, int address, int length)
{
	HANDLE hProcess;
	//fhbyte = {};
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //�򿪵�ǰ����
	}
	else
	{
		//hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)����ID);//PROCESS_VM_READ
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, Pid);
	}


	byte* p = new byte[length];//ȡ�հ��ֽڼ������洢������
	memset(p, 0, length);//�������Ļ�����
	ReadProcessMemory(hProcess, (LPCVOID)address, p, length, NULL);


	CloseHandle(hProcess);//�رն���


	return p;//���ﷵ�ض�ȡ�����ֽڼ����׵�ַ




}


BOOL д�ڴ��ֽڼ�(int Pid, int address, byte data[], int length)
{
	HANDLE hProcess;
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //�򿪵�ǰ����
	}
	else
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)Pid);//PROCESS_VM_READ


	}


	BOOL a = WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)data, length, 0);
	CloseHandle(hProcess);//�رն���
	return a;
}








