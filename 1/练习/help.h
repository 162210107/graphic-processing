#pragma once
using namespace std;//ʹ�ñ�׼�����ռ�
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<graphics.h>
#include"bmp.h"
#include"bmp1.h"
#include"sss.h"
//***********���ı��С�Ĺ��ܣ�ֻ�ı�����ֵ**********
//ˮƽ��ת
void rowReverse(int height, int width, RGBTriple* image);
//ģ����
void makeBlur(int height, int width, RGBTriple* image); 
//�ҶȻ�
void makeGary(int height, int width, RGBTriple* image);