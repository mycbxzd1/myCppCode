#define     _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <fstream> 

#include <iostream>
#pragma once

using namespace std;




class �ֽڼ�
{
public:
	int ����;
	byte* ����;
	int ȡָ���ַ();	
	bool �Ƿ�Ϊ��();
};

�ֽڼ� �����ļ�(const char* �ļ���);
void д���ļ�(const char* �ļ���, �ֽڼ� ��д������);
�ֽڼ� �ı����ֽڼ�(LPCWSTR �ı�);//ע���������


byte* ���ڴ��ֽڼ�(int Pid, int address, int length);
BOOL д�ڴ��ֽڼ�(int Pid, int address, byte data[], int length);

