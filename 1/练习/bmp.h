#pragma once
using namespace std;//ʹ�ñ�׼�����ռ�
#define _CRT_SECURE_NO_WARNINGS
#define BMPTYPE 19778
#include<fstream>
#include<iostream>
#include<conio.h>
#include <wtypes.h>
#include <wingdi.h>
#include <graphics.h>
#include"sss.h"
//�����
class bmp 
{
public:
    virtual void readPic(char fileName[]) = 0;//���ļ�
    virtual void writePic(void (*myMethod)(int, int, RGBTriple*), char* outFileName)=0;
    //���ڱ��������д����洢��outfilename���ͼ����
    virtual void ShowImage(int i) = 0;
    //ָ����������ʾͼ��
    friend ostream& operator<<(ostream& out, bmp& obj);
    //���������

    int success=0;
    //��¼�Ƿ�ɹ���ȡ�ʹ洢
    int offset=0;
    //�ڴ�ƫ����
    RGBTriple* surface;
    //ָ�򴢴����صĿռ�
    BmpFileHeader fileHeader;
    //�ļ�ͷ
    BmpFileInFoHeader fileInFoHeader;
    //��Ϣͷ
    char* mfilename;
    //ͼ������
};