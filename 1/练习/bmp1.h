#pragma once
using namespace std;//ʹ�ñ�׼�����ռ�
#include"bmp.h"
//����24λͼ
class bmp1:public bmp
{
public:
	bmp1();
	bmp1(const bmp1& obj);//��������
	virtual void readPic(char fileName[]);
	virtual void writePic(void (*myMethod)(int, int, RGBTriple*),char* outFileName);
	virtual void ShowImage(int i);
	friend ostream& operator<<(ostream& out, bmp& obj);
	~bmp1();
};
