#define     _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <fstream> 

#include <iostream>
#pragma once

using namespace std;




class 字节集
{
public:
	int 长度;
	byte* 数据;
	int 取指针地址();	
	bool 是否为空();
};

字节集 读入文件(const char* 文件名);
void 写到文件(const char* 文件名, 字节集 欲写入内容);
字节集 文本到字节集(LPCWSTR 文本);//注意编码类型


byte* 读内存字节集(int Pid, int address, int length);
BOOL 写内存字节集(int Pid, int address, byte data[], int length);

