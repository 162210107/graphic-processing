#pragma once
#include"bmp.h"
//����16λͼ
class bmp3 :public bmp
{
public:
	char* rgb_mask;
	//������
	char* imagebuf;//ʵ������ֵ
	char* bmpbuf;//������ֵ

	bmp3();
	bmp3(const bmp3& obj);//��������
	virtual void readPic(char fileName[]);
	virtual void writePic(void (*myMethod)(int, int, RGBTriple*), char* outFileName);
	virtual void ShowImage(int i);
	friend ostream& operator<<(ostream& out, bmp& obj);
	~bmp3();
};