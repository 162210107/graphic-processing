#include"help.h"
//ˮƽ��ת
void rowReverse(int height, int width, RGBTriple* image)
{
    int ured = 0, ugreen = 0, ublue = 0;  
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < k; j++, k--)
        {
            ured = (image + (i * width + j))->red;
            (image + (i * width + j))->red = (image + (i * width + k))->red;
            (image + (i * width + k))->red = ured;
            ugreen = (image + (i * width + j))->green;
            (image + (i * width + j))->green = (image + (i * width + k))->green;
            (image + (i * width + k))->green = ugreen;
            ublue = (image + (i * width + j))->blue;
            (image + (i * width + j))->blue = (image + (i * width + k))->blue;
            (image + (i * width + k))->blue = ublue;
           
        }
        
    }
}
//��3x3��������Ķ�׼ͼƬÿһ������
//��ȡ�串���������ص��rgb��ƽ��ֵ
//�µ�rgb����ƣ�����������Ⱦ
void makeBlur(int height, int width, RGBTriple* image)
{
    RGBTriple* temp = new RGBTriple[height * width];
    int ured = 0;
    int ugreen = 0;
    int ublue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //����ʵ�ʸ��ǵ���������
            int total = 0;
            for (int y = i - 1, myCount = 0; myCount < 3; y++, myCount++)//ÿ�����ص�ǰһ��
             //mycout���ڼ�¼3*3���񳤶ȣ����ȡ����
            {
                if (y >= 0 && y < height)//��֤3*3���������ǵ����ص���ͼ����
                {
                    for (int x = j - 1, myCount1 = 0; myCount1 < 3; x++, myCount1++)
                    {
                        if (x >= 0 && x < width)
                        {
                            ured += (image + (y * width + x))->red;
                            ugreen += (image + (y * width + x))->green;
                            ublue += (image + (y * width + x))->blue;
                            total++;
                        }
                    }
                }
            }
            (temp + (i * width + j))->red = (ured / total);
            (temp + (i * width + j))->green = (ugreen / total);
            (temp + (i * width + j))->blue = (ublue / total);
            ured = ugreen = ublue = 0;//��ʼ��һ��
        }
    }
   //����ֵ
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            (image + (i * width + j))->blue = (temp + (i * width + j))->blue;
            (image + (i * width + j))->green = (temp + (i * width + j))->green;
            (image + (i * width + j))->red = (temp + (i * width + j))->red;
        }
    }
    delete[] temp;//�ͷ���ʱ����
}
void makeGary(int height, int width, RGBTriple* image) 
{
    for (int i =0; i < height; i++) 
    {
        for (int j =0; j < width; j++) 
        {
            int aver = ((image + (i * width + j))->blue + (image + (i * width + j))->green + (image + (i * width + j))->red) / 3;
           (image + (i * width + j))->blue = (image + (i * width + j))->green = (image + (i * width + j))->red = aver;
        }
    }
}