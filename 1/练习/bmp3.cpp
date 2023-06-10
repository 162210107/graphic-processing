#include "bmp3.h"

bmp3::bmp3()
{

}

bmp3::bmp3(const bmp3& obj)
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

    rgb_mask = new char[12];
    rgb_mask = obj.rgb_mask;

    int dst_widsize = ((fileInFoHeader.biWidth * 16 + 31) >> 5) << 2;
    imagebuf = new char[dst_widsize* fileInFoHeader.biHeight];//ʵ������
    imagebuf = obj.imagebuf;

    int a = ((fileInFoHeader.biWidth * fileInFoHeader.biBitCount + 31) >> 5) << 2;
    bmpbuf = new char[a];
    bmpbuf = obj.bmpbuf;
}

void bmp3::readPic(char fileName[])
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
        return;
    }
    ifs.read((char*)&fileInFoHeader, sizeof(BmpFileInFoHeader));
    // �ж��ļ��Ƿ��ȡ�ɹ�
    if (ifs.fail())
    {
        cout << "��ȡ��Ϣͷ����" << endl;
        success = 0;
        return;
    }
    //�ж��Ƿ�Ϊ16λͼ
    if (fileInFoHeader.biBitCount != 16)
    {
        cout << "invalid!����ʮ��λͼ��" << endl;
        success = 0;
        return;
    }

    rgb_mask = new char[12];
    ifs.read((char*)rgb_mask, sizeof(char) * 12);
    if (ifs.fail())
    {
        cout << "��ȡ���������" << endl;
        success = 0;
        return;
    }

    ifs.seekg((long)fileHeader.bfOffBits, SEEK_SET);

    int src = ((fileInFoHeader.biWidth * fileInFoHeader.biBitCount + 31) >> 5) << 2;
    char* bmpbuf = new char[src];//�������Ӧ������
    int dst_widsize = ((fileInFoHeader.biWidth * 16 + 31) >> 5) << 2;
    imagebuf = (char*)malloc(dst_widsize * fileInFoHeader.biHeight);//ʵ������

    //�洢�������ݵ�����
    surface = new RGBTriple[fileInFoHeader.biHeight * fileInFoHeader.biWidth];
    short d;
    for (short k = fileInFoHeader.biHeight-1, n = 0; k >=0; k--)
    {
        //��ȡͼƬ��������
        ifs.read((char*)bmpbuf, sizeof(char)*src);
        for (short q = 0; q < fileInFoHeader.biWidth; q++) 
        {
            //����������д���
            d = ((short)(bmpbuf[3 * q + 2] >> 3) << 11)//R G B
                + ((short)(bmpbuf[3 * q + 1] >> 2) << 5)
                + (short)(bmpbuf[3 * q + 0] >> 3);
            (surface + (fileInFoHeader.biWidth * k + q))->blue = bmpbuf[3 * q + 0] >> 3;
            (surface + (fileInFoHeader.biWidth * k + q))->green = (bmpbuf[3 * q + 1] >> 2) << 5;
            (surface + (fileInFoHeader.biWidth * k + q))->red = (bmpbuf[3 * q + 2] >> 3) << 11;
            imagebuf[n++] = d & 0xff;
            imagebuf[n++] = d >> 8;
        }
        while (n % dst_widsize != 0) 
            imagebuf[n++] = 0x00;
    }
}
//дΪ24λͼ
void bmp3::writePic(void (*myMethod)(int, int, RGBTriple*), char* outFileName)
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
    ofs.write((char*)&fileHeader, sizeof(BmpFileHeader));
    // �ж��ļ��Ƿ�д��ɹ�
    if (ofs.fail())
    {
        cout << "�ļ�ͷд��ʧ�ܣ�" << endl;
        return;
    }
    ofs.write((char*)&fileInFoHeader, sizeof(BmpFileInFoHeader));
    // �ж��ļ��Ƿ�д��ɹ�
    if (ofs.fail())
    {
        cout << "��Ϣͷд��ʧ�ܣ�" << endl;
        return;
    }
    
    for (int i = fileInFoHeader.biHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < fileInFoHeader.biWidth; j++)
        {
            ofs.write((char*)(surface + (i * fileInFoHeader.biWidth + j)), sizeof(RGBTriple));
            // �ж��ļ��Ƿ�д��ɹ�
            if (ofs.fail())
            {
                cout << "д������ʧ�ܣ�" << endl;
                return;
            }
        }
        //�ȶ�һ�У�����ÿ�к����0����
        if (offset != 0)
        {
            char ign = 0;
            for (int k = 0; k < offset; k++)
            {
                ofs.write(&ign, sizeof(char));//�ڴ����
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
    ofs.close();
}

void bmp3::ShowImage(int i)
{
    IMAGE mage;
    loadimage(&mage, mfilename);
    putimage(80, 70 + 400 * i, &mage);//���λ��
}

bmp3::~bmp3()
{
    success = 0;
    offset = 0;
    delete[]rgb_mask;
    delete[]imagebuf;
    delete[]bmpbuf;
    delete[]surface;
    delete[]mfilename;
}