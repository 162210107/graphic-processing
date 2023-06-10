#pragma once
using namespace std;//ʹ�ñ�׼�����ռ�
#include"bmp1.h"

bmp1::bmp1()
{

}

bmp1::bmp1(const bmp1& obj)
{
    fileHeader = obj.fileHeader;
    fileInFoHeader = obj.fileInFoHeader;

    int width = obj.fileInFoHeader.biWidth;
    int height = obj.fileInFoHeader.biHeight;
    surface = new RGBTriple[width * height];
    surface = obj.surface;

    offset = obj.offset;
    success = obj.success;

    mfilename = new char[20];
    mfilename = obj.mfilename;
}

void bmp1::readPic(char fileName[])
{
    ifstream ifs;//�ļ������
    cout << fileName<<endl;
    mfilename = new char[20];
    int i = 0;
    while (fileName[i] != '\0')
    {
        *(mfilename + i) = fileName[i];
        i++;
    }
    *(mfilename + i) = '\0';
    //���ļ��������Ʒ�ʽ�򿪶�
    ifs.open(fileName, ios::in | ios::binary);
    //�ж��ļ��Ƿ�򿪳ɹ�
    if (!ifs.is_open()) 
    {
        cout <<"Can't open the file." << endl;
        success = 0;//��¼ʧ�����
        return;
    }
    ifs.read((char*)&fileHeader,sizeof(BmpFileHeader));
    // �ж��ļ��Ƿ��ȡ�ɹ�
    if (ifs.fail())
    {
        cout << "�ļ�ͷ��ȡ����" << endl;
        success = 0;
        return;
    }
    //�ж�bfType��ʽ�Ƿ���ȷ
    if (fileHeader.bfType != BMPTYPE) 
    {
        cout <<"type error!" << endl;
        success = 0;
        return;
    }
    ifs.read((char*)&fileInFoHeader,sizeof(BmpFileInFoHeader));
    // �ж��ļ��Ƿ��ȡ�ɹ�
    if (ifs.fail())
    {
        cout << "��Ϣͷ��ȡ����" << endl;
        success = 0;
        return;
    }
    //�ж��Ƿ�Ϊ24λͼ
    if (fileInFoHeader.biBitCount !=24)
    {
        cout <<"invalid!λͼ��ʽ����" << endl;
        success = 0;
        return;
    }
    //�ڴ�������ƫ�ƣ�4�ı���
    offset = (fileInFoHeader.biWidth *3) %4;
    if (offset !=0) 
    {
        offset =4 - offset;
    }
    //�洢�������ݵ�����
    surface =new RGBTriple[fileInFoHeader.biHeight * fileInFoHeader.biWidth];
    for (int i = fileInFoHeader.biHeight- 1; i >=0; i--) //���µ��ϣ������Ҵ�������
    {
        for (int j =0; j < fileInFoHeader.biWidth; j++) 
        {
            ifs.read((char*)(surface + (fileInFoHeader.biWidth * i + j)), sizeof(RGBTriple));
        }
        //ÿ�ж��������ƫ��
        if (offset !=0)
        {
            char ign;
            for (int k =0; k < offset; k++) 
            {
                ifs.read(&ign,sizeof(char));
            }
        }
    }
    ifs.close();
    success = 1;//�ɹ���־
}

void bmp1::writePic(void (*myMethod)(int, int, RGBTriple*), char* outFileName) //����ָ��
{ 
    myMethod(fileInFoHeader.biHeight, fileInFoHeader.biWidth, surface);
    //create a new bmp����������

    ofstream ofs;
    ofs.open(outFileName, ios::out | ios::binary);
    // �ж��ļ��Ƿ��
    if (!ofs.is_open())
    {
        cout << "file open is error!" << endl;
        return;
    }
    ofs.write((char*)&fileHeader,sizeof(BmpFileHeader));
    // �ж��ļ��Ƿ�д��ɹ�
    if (ofs.fail())
    {
        cout << "�ļ�ͷд��ʧ�ܣ�" << endl;
        return;
    }
   
    ofs.write((char*)&fileInFoHeader,sizeof(BmpFileInFoHeader));
    // �ж��ļ��Ƿ�д��ɹ�
    if (ofs.fail())
    {
        cout << "��Ϣͷд��ʧ�ܣ�" << endl;
        return;
    }

    //rewrite
    for (int i = fileInFoHeader.biHeight -1; i >=0; i--) 
    {
        for (int j =0; j < fileInFoHeader.biWidth; j++) 
        {
            ofs.write((char*)(surface + (i * fileInFoHeader.biWidth + j)),sizeof(RGBTriple));
            // �ж��ļ��Ƿ�д��ɹ�
            if (ofs.fail())
            {
                cout << "д������ʧ�ܣ�" << endl;
                return;
            }
        }
        //�ȶ�һ�У�����ÿ�к����0����
        if (offset !=0) 
        {
            char ign = 0;
            for (int k =0; k < offset; k++) 
            {
                ofs. write(&ign,sizeof(char));//�ڴ����
                // �ж��ļ��Ƿ�д��ɹ�
                if (ofs.fail())
                {
                    cout << "ƫ�����洢����" << endl;
                    return;
                }
            }
        }
    }
    delete[] surface;
    ofs. close();
}

void bmp1::ShowImage(int i)
{
	/*int r, g, b, pix;
	HWND wnd=CreateWindow(EDIT,TEXT("ͼƬ")��WS_POPUP|WS_SIZEBOX,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,NULL,NULL,hInstance,NULL);                                 //���ھ��
	HDC dc;
	wnd = GetForegroundWindow();               //��ȡ���ھ��
	dc = GetDC(wnd);                           //��ȡ��ͼ�豸
	int x = 10;
	int y = 10;
	
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			b = *p++; g = *p++; r = *p++;
			
			pix = RGB(r, g, b);
			
			int ret=SetPixel(dc, i+x , 150+height-j, pix);
			cout << ret;
			system("pause");//����̨û�취��ʾ��redraw����
		}
	}*/
	IMAGE mage;
	loadimage(&mage,mfilename);
	putimage(80, 70+400*i, &mage);//���λ��
}

bmp1::~bmp1()
{
    success = 0;
    offset = 0;
    delete[]surface;
    delete[]mfilename;
}