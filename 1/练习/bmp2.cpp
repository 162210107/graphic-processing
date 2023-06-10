#include "bmp2.h"

bmp2::bmp2()
{

}
//��������
bmp2::bmp2(const bmp2& obj)
{
    fileHeader = obj.fileHeader;
    fileInFoHeader = obj.fileInFoHeader;

    int width = obj.fileInFoHeader.biWidth;
    int height = obj.fileInFoHeader.biHeight;
    surface = new RGBTriple[width * height];
    surface = obj.surface;

    rgbQuad = new RGBQUAD[256];
    rgbQuad = obj.rgbQuad;

    offset = obj.offset;
    success = obj.success;

    mfilename = new char[20];
    mfilename = obj.mfilename;
}
//��������
void bmp2::readPic(char fileName[])
{
    ifstream ifs;
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
        cout << "Can't open the file." << endl;
        success = 0;
        return;
    }
    ifs.read((char*)&fileHeader, sizeof(BmpFileHeader));
    // �ж��ļ��Ƿ��ȡ�ɹ�
    if (ifs.fail())
    {
        cout << "��ȡ�ļ�ͷ����" << endl;
        success = 0;//��¼ʧ�����
        return;
    }
    //�ж�bfType��ʽ�Ƿ���ȷ
    if (fileHeader.bfType != BMPTYPE)
    {
        cout << "type error!" << endl;
        success = 0;
        return ;
    }
    ifs.read((char*)&fileInFoHeader, sizeof(BmpFileInFoHeader));
    // �ж��ļ��Ƿ��ȡ�ɹ�
    if (ifs.fail())
    {
        cout << "��ȡ��Ϣͷ����" << endl;
        success = 0;
        return ;
    }
    //�ж��Ƿ�Ϊ8λͼ
    if (fileInFoHeader.biBitCount != 8) 
    {
        cout << "invalid!���ǰ�λͼ��" << endl;
        success = 0;
        return ;
    }
    ifs.read((char *)rgbQuad, fileInFoHeader.biClrUsed * sizeof(RGBQUAD));
    unsigned char* c;
    c = (unsigned char*)malloc((fileInFoHeader.biWidth + 3) / 4 * 4);

    surface = new RGBTriple[fileInFoHeader.biHeight * fileInFoHeader.biWidth];
    for (int i = fileInFoHeader.biHeight - 1; i >= 0; i--) //���µ��ϣ������Ҵ�������
    {
        for (int j = 0; j < ((fileInFoHeader.biWidth * 3 + 3) / 4 * 4); j++) 
        {//����ÿ����ÿ���ֽڵ�ѭ��
            ifs.read((char*)c + j, 1);//��Դͼÿ�е�ÿһ���ֽڶ������a��ָ����ڴ�ռ�
        }
        for (int j = 0; j < fileInFoHeader.biWidth; j++)
        {
            (surface + (i * fileInFoHeader.biWidth + j))->blue = c[j];
            (surface + (i * fileInFoHeader.biWidth + j))->green = c[j];
            (surface + (i * fileInFoHeader.biWidth + j))->red = c[j];
        }
    }
    ifs.close();
    success = 1;
}
//��ȡ
typedef unsigned char BYTE;
//��λͼ�񱣴�  ��BYTE���ݱ����Ϊͼ��ͼ��·����filename
void bmp2::writePic(void (*myMethod)(int, int, RGBTriple*), char* strFileName)
{
    myMethod(fileInFoHeader.biHeight, fileInFoHeader.biWidth, surface);

    FILE* fp;
    int i;

    BYTE p[4];//��ɫ��

    //�洢ͼ�����ݣ�ÿ���ֽ���Ϊ4�ı���
    //���� + 3���³��ֲ�����4�ı�����������������4�ı��������Ͳ� + 3�Ľ����һ���ģ��������4�ı���������1λ
    //  /4*4�������ڳ������ǰ����ݹ�Ϊ4�ı�����
    offset = (fileInFoHeader.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    // Open File
    if ((fp = fopen(strFileName, "w+b")) == NULL)
    {
        success = 0;
        return;
    }

    if (fwrite((char*)&fileHeader, 1, 14, fp) != 14)
    {
        fclose(fp);
        remove(strFileName);
        success = 0;
        return;
    }
    if (fwrite((char*)&fileInFoHeader, 1, 40, fp) != 40)
    {
        fclose(fp);
        remove(strFileName);
        success = 0;
        return;
    }

    // д���ɫ��
    for (i = 0, p[3] = 0; i < 256; i++)
    {
      //��������ѡ�񱣴��ͼ����ɫ�պû���
        p[0] = p[1] = p[2] =i; // blue,green,red;
    
        if (fwrite((char*)p, 1, 4, fp) != 4)
        {
           success = 0;
           return;
        }
    }

    //write data ͼ������ ���µ��ϱ���
    for (int i = fileInFoHeader.biHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < fileInFoHeader.biWidth; j++)
        {
            if (fwrite((char*)(surface + (i * fileInFoHeader.biWidth + j)), 1, sizeof(RGBTriple), fp) != sizeof(RGBTriple))
            {
                fclose(fp);
                remove(strFileName);
                success = 0;
                return;
            }
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if ((fread(&ign, 1, sizeof(char), fp) != sizeof(char)))
                {
                    // �ж��ļ��Ƿ��ȡ�ɹ�
                    cout << "����ֽڲ������" << endl;
                     success = 0;
                     return;
                }
            }
        }
    }
    fclose(fp);
    success = 1;
}
//�洢
void bmp2::ShowImage(int i)
{
    IMAGE mage;
    loadimage(&mage, mfilename);
    putimage(80, 70 + 400 * i, &mage);//���λ��
}
//��ʾ
bmp2::~bmp2()
{
    success = 0;
    offset = 0;
    delete[]rgbQuad;
    delete[]surface;
    delete[]mfilename;
}
//��������