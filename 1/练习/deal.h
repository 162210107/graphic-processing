#pragma once
using namespace std;//ʹ�ñ�׼�����ռ�
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<graphics.h>
#include<math.h>

#include"bmp.h"
#include"bmp2.h"
#include"bmp3.h"
#include"bmp1.h"
#include"bmp4.h"
#include"help.h"
#include"sss.h"
class deal
{
	int m_EmpNum;//����

	bmp** m_EmArray;//ͼ������ָ��
public:
	//���캯��
	deal();

	//��ʾ�˵�
	void showMenu();

	//button����
	void button(int x, int y, int w, int h, TCHAR* text);

	//��ֵ��ͼ��
	void binaryimage();

	//��ȡͼ��
	void readimagebox();

	//��תͼ��
	void ImageInvert();

	//ģ��ͼ��
	void Imagemuhu();
	
	//��ȡͼ��
	void Imageintercept();

	//����ͼ��
	void ImageOver();

	//����ͼ��
	void ImageBig();

	//��תͼ��
	void ImageTurn();

	//�Ҷ�ͼƬ
	void ImageGray();

	//����
	void closeImage();

	//���ͼ��
	void ImageAdd();

	//��ⷽ�̵�k,bֵ
	void function_line(double x1, double y1, double x2, double y2, double& k, double& b);

	//����ֱ�ߵ�y
	double solve_y(double k, double b, double x);

	//����ֱ�ߵ�x
	double solve_x(double k, double b, double y);

	//����----��С��������
	void sort_min_to_max(double suitable_x[], int n);

	//�������Ԫ��ֵ
	double find_max(double elem[], int N);

	//�����С��Ԫ��ֵ
	double find_min(double elem[], int N);

	//�ҳ�ɨ������߽��ཻ�ĵ㣬��������suitable_x[]�У����ཻ�ĵ���������n��
	void Suitable_x(double x[], double y[], int N, double now_y, double suitable_x[], int& n);

	//��������
	void quick_sort(double s[], int l, int r);

	//�رմ���
	void close();

	//չʾ����
	void showall();

	//��������
	~deal();
};