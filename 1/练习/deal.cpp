#include"deal.h"
//����ʹͼ������ռ�ֽ���Ϊ4byte�ı���
#define   WIDTHBYTES(bits) (((bits)+31)/32*4)
//����PI
#define PI 3.14
//���캯��
deal::deal()
{
    this->m_EmpNum = 0;
    //��ʼ������
    this->m_EmArray = NULL;
    //��ʼ������ָ��
}
//��ť�ؼ�
void deal:: button(int x, int y, int w, int h, TCHAR* text)
{
    setbkmode(TRANSPARENT);
    setfillcolor(YELLOW);
    fillroundrect(x, y, x + w, y + h, 10, 10);
    // ����ַ�����MBCS �ַ�����
    TCHAR s1[] = "����";
    settextstyle(30, 0, s1);
    TCHAR s[50] = "hello";

    int tx = x + (w - textwidth(text)) / 2;
    int ty = y + (h - textheight(text)) / 2;

    outtextxy(tx, ty, text);

}
//չʾ�˵�
void deal::showMenu()          
{
	initgraph(850, 850);
    HWND a = GetHWnd();
    SetWindowText(a, "С�˵���ͼ���");
	setbkcolor(WHITE);//����ɫ
	cleardevice();
    settextcolor(BLACK);
    TCHAR s0[] = "����";
    settextstyle(30, 0, s0);
    outtextxy(140, 30, _TEXT(" ����С�˵���ͼ�������"));
    TCHAR s[20] = "��ת";
    TCHAR s1[20] = "���";
    TCHAR s2[20] = "����";
    TCHAR s3[20] = "ģ��";
    TCHAR s4[20] = "��ȡ";
    TCHAR s5[20] = "��ȡ";
    TCHAR s8[20] = "����";
    TCHAR s6[10] = "�˳�";
    TCHAR s7[10] = "����";
    TCHAR s9[20] = "��ת";
    TCHAR s10[20] = "�Ѷ�";
    TCHAR s11[20] = "�Ҷ�";
    TCHAR s12[20] = "��ֵ";
    button(775, 100, 75, 20, s5);
    button(775, 160, 75, 20, s1);
    button(775, 220, 75, 20, s2);
    button(775, 280, 75, 20, s);
    button(775, 340, 75, 20, s4);
    button(775, 400, 75, 20, s3);
    button(775, 460, 75, 20, s8);
    button(775, 520, 75, 20, s9);
    button(700, 820, 40, 20, s7);
    button(775, 640, 75, 20, s11);
    button(775, 700, 75, 20, s12);
    button(775, 820, 40, 20, s6);
    button(775, 580, 75, 20, s10);
    ExMessage msg;
    while (true) 
    {
        if (peekmessage(&msg, EM_MOUSE)) 
        {

            switch (msg.message)
            {
            case WM_LBUTTONDOWN:
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 100 && msg.y <= 100 + 20)
                {
                    cout << s5;
                    readimagebox();
                    //outtextxy(2, 2, s5); //д��һ��չʾ���ֵ�Ч�����൱���ǲ���,ʵ��ʹ��ʱ����ɾ��
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 160 && msg.y <= 160 + 20)
                {
                    cout << s1;
                    //outtextxy(2, 20, s1);
                    //��������㷨-�ǵݹ���ʽ��ɨ�����Ż���
                    ImageAdd();
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 220 && msg.y <= 220 + 20)
                {
                    cout << s2;
                    //outtextxy(2, 200, s2);
                    ImageOver();
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 280 && msg.y <= 280 + 20)
                {
                    cout << s;
                    ImageInvert();
                    //outtextxy(2, 300, s);
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 340 && msg.y <= 340 + 20)
                {
                    cout << s4;
                    //outtextxy(2, 400, s4);
                    Imageintercept();
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 400 && msg.y <= 400 + 20)
                {
                    cout << s3;
                    //outtextxy(2, 500, s3);
                    Imagemuhu();
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 460 && msg.y <= 460 + 20)
                {
                    cout << s8;
                    //˫���Բ�ֵ�㷨
                    ImageBig();
                }
                if (msg.x >= 775 && msg.x <= 775 + 75 && msg.y >= 520 && msg.y <= 520 + 20)
                {
                    cout << s9;
                    //˫���Բ�ֵ�㷨+��ת
                    ImageTurn();
                }
                if (msg.x >= 775 && msg.x <= 775 + 40 && msg.y >= 580 && msg.y <=580 + 20)
                {
                    cout << s10;
                    //չʾ���ж�ȡ����ͼ��
                    showall();
                }
                if (msg.x >= 775 && msg.x <= 775 + 40 && msg.y >= 640 && msg.y <= 640 + 20)
                {
                    cout << s11;
                    //�ҶȻ�
                    ImageGray();
                }
                if (msg.x >= 775 && msg.x <= 775 + 40 && msg.y >= 700 && msg.y <= 700 + 20)
                {
                    cout << s12;
                    //��ֵ
                    binaryimage();
                }
                if (msg.x >= 700 && msg.x <= 700 + 75 && msg.y >= 820 && msg.y <= 820 + 20)
                {
                    cout << s7<<endl;
                    //outtextxy(2, 500, s3);
                    closeImage();
                }
                if (msg.x >= 775 && msg.x <= 775+ 40 && msg.y >= 820 && msg.y <=   820   + 20)
                {
                    close();
                }
                break;
            default:
                 break;
            }
        }

    }
	closegraph();
}
//��ȡ
void deal::readimagebox()
{
    char filename[20];
    cout << "��ȡͼ������:";
    cin >> filename;

    cout << "1.��λͼ��2.8λͼ��3.24λͼ��4.16λͼ"<<endl;
    int am=0;//ѡ��
    cin >> am;
    
    switch (am)
    {
    case 1:
    {
        bmp* a1 = new bmp4;
        a1->readPic(filename);
        if (a1->success == 1)
        {
            a1->ShowImage(m_EmpNum);

            bmp** newspace1 = new bmp * [m_EmpNum + 1];
            if (this->m_EmArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    newspace1[i] = this->m_EmArray[i];
                }
            }
            newspace1[this->m_EmpNum] = a1;
            m_EmpNum++;
            //�ͷ�ԭ�пռ�
            delete[]this->m_EmArray;

            //�����¿ռ��ָ��
            this->m_EmArray = newspace1;
        }
        else
        {
            cout << "����ѡ���Ҳ๦��" << endl;
        }
        break;
    }
    case 2:
    {
        bmp* a2 = new bmp2;
        a2->readPic(filename);
        if (a2->success == 1)
        {
            a2->ShowImage(m_EmpNum);

            bmp** newspace2 = new bmp * [m_EmpNum + 1];
            if (this->m_EmArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    newspace2[i] = this->m_EmArray[i];
                }
            }
            newspace2[this->m_EmpNum] = a2;
            m_EmpNum++;
            //�ͷ�ԭ�пռ�
            delete[]this->m_EmArray;

            //�����¿ռ��ָ��
            this->m_EmArray = newspace2;
        }
        else
        {
            cout << "����ѡ���Ҳ๦��"<<endl;
        }
        break;
    }
    case 3:
    {
        bmp * a3 = new bmp1;
        a3->readPic(filename);
        if (a3->success == 1)
        {
            a3->ShowImage(m_EmpNum);

            bmp** newspace3 = new bmp * [m_EmpNum + 1];
            if (this->m_EmArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    newspace3[i] = this->m_EmArray[i];
                }
            }
            newspace3[this->m_EmpNum] = a3;
            m_EmpNum++;
            //�ͷ�ԭ�пռ�
            delete[]this->m_EmArray;

            //�����¿ռ��ָ��
            this->m_EmArray = newspace3;
        }
        else
        {
            cout << "����ѡ����" << endl;
        }
        break;
    }
    case 4:
    {
        bmp* a4 = new bmp3;
        a4->readPic(filename);
        if (a4->success == 1)
        {
            a4->ShowImage(m_EmpNum);

            bmp** newspace4 = new bmp * [m_EmpNum + 1];
            if (this->m_EmArray != NULL)
            {
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    newspace4[i] = this->m_EmArray[i];
                }
            }
            newspace4[this->m_EmpNum] = a4;
            m_EmpNum++;
            //�ͷ�ԭ�пռ�
            delete[]this->m_EmArray;

            //�����¿ռ��ָ��
            this->m_EmArray = newspace4;
        }
        else
        {
            cout << "����ѡ����" << endl;
        }
        break;
    }
    default:
    {
        cout << "ѡ�������ѡ����"<<endl;
        break;
    }
    }
}
//��ת
void deal::ImageInvert()
{
    //�ҵ�����һ�δ����ͼ��
    bmp* a = this->m_EmArray[m_EmpNum-1];

    cout << endl;
    char name[100]={0};//�½��ɵ�bmp����
    cout << "��ͼƬ����:";
    cin>>name;

    a->writePic(rowReverse, name);
    bmp* a1 = NULL;
    //����ͼƬ��λͼ���д���
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

   bmp** newspace = new bmp * [m_EmpNum + 1];
   if (this->m_EmArray != NULL)
   {
       for (int i = 0; i < this->m_EmpNum; i++)
       {
           newspace[i] = this->m_EmArray[i];
       }
   }
   newspace[this->m_EmpNum] = a1;
   m_EmpNum++;
   //�ͷ�ԭ�пռ�
   delete[]this->m_EmArray;

   //�����¿ռ��ָ��
   this->m_EmArray = newspace;

}
//ģ��
void deal::Imagemuhu() 
{
    bmp* a = this->m_EmArray[m_EmpNum-1];

    cout << endl;
    cout << "��ͼƬ���ƣ�";
    char name[100]={0};//bmp����
    cin>>name;

    a->writePic(makeBlur, name);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//��ȡ
void deal::Imageintercept()
{
    bmp* a = this->m_EmArray[m_EmpNum-1];
    cout << endl;
    cout << "��ͼƬ����:";
    char name[100]={0};//bmp����
    cin>>name;
   
    int newheight1 = 0;
    int newwidth1 = 0;
    int newheight2 = 0;
    int newwidth2 = 0;

    cout << "��ȡ���:"<<endl;
    cout << "y���꣺";
    cin >> newheight1;
    getchar();
    cout << "x���꣺";
    cin >> newwidth1;
    getchar();

    while (newheight1 < 0 || newwidth1 < 0||newheight1>a->fileInFoHeader.biHeight||newwidth1>a->fileInFoHeader.biWidth)
    {
        cout << "����ͼƬ��Χ��������������!!!" << endl;
        cout << "��ȡ���:"<<endl;
        cout << "y���꣺";
        cin >> newheight1;
        getchar();
        cout << "x���꣺";
        cin >> newwidth1;
        getchar();
    }

    cout << "��ȡ�յ�:"<<endl;
    cout << "y���꣺";
    cin >> newheight2;
    getchar();
    cout << "x���꣺";
    cin >> newwidth2;
    getchar();

    while (newheight2 >= a->fileInFoHeader.biHeight || newwidth2 >= a->fileInFoHeader.biWidth||newheight2<=newheight1||newwidth2<=newwidth1)
    {
        cout << "����ͼƬ��Χ��������������!!!" << endl;
        cout << "��ȡ�յ�:"<<endl;
        cout << "y���꣺";
        cin >> newheight2;
        getchar();
        cout << "x���꣺";
        cin >> newwidth2;
        getchar();
    }

    int h = newheight2 - newheight1;
    int w = newwidth2 - newwidth1;
    RGBTriple* image = new RGBTriple[h * w];

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");//���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "���ļ�����";
        return;
    }

    //��ȡλͼ�ļ�ͷ��Ϣ
    BmpFileHeader wbitHead;
    wbitHead = a->fileHeader;
    //���ڽ�ȡͼ��ͷ��Դ�ļ�ͷ���ƣ������Ƚ�Դ�ļ�ͷ���ݸ����ȡ�ļ�ͷ
    //��ȡλͼ��Ϣͷ��Ϣ
    BmpFileInFoHeader wbitInfoHead;
    wbitInfoHead = a->fileInFoHeader;//ͬλͼ�ļ�ͷ����

    wbitInfoHead.biHeight = h;//Ϊ��ȡ�ļ���дλͼ�߶�
    wbitInfoHead.biWidth = w;//Ϊ��ȡ�ļ���дλͼ���

    int mywritewidth = WIDTHBYTES(wbitInfoHead.biWidth * wbitInfoHead.biBitCount);
    //BMPͼ��ʵ��λͼ�������Ŀ��Ϊ4byte�ı������ڴ˼���ʵ�����������
    wbitInfoHead.biSizeImages = mywritewidth * wbitInfoHead.biHeight;//����λͼʵ����������С

    wbitHead.bfSize = 54 + wbitInfoHead.biSizeImages;//λͼ�ļ�ͷ��СΪλͼ��������С����54byte

    if (fwrite(&wbitHead, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&wbitInfoHead, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�

    int offset = (wbitInfoHead.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    RGBTriple* temp = a->surface;
    int i2 = h - 1;
    for (int i =newheight2; i>=newheight1; i--) //���µ��ϣ������Ҵ�������
    {
        if (i2 >= 0)
        {
            int j2 = 0;
            for (int j = newwidth1; j < a->fileInFoHeader.biWidth - newwidth2; j++)
            {
                if (j2 < w)
                {
                    (image + (i2 * w + j2))->blue = (temp + (i * a->fileInFoHeader.biWidth + j))->blue;
                    (image + (i2 * w + j2))->green = (temp + (i * a->fileInFoHeader.biWidth + j))->green;
                    (image + (i2 * w + j2))->red = (temp + (i * a->fileInFoHeader.biWidth + j))->red;
                    fwrite((char*)(image + (i2 * w + j2)), sizeof(RGBTriple), 1, wfile);
                }
                j2++;
            }
            if (offset != 0)
            {
                char ign;
                for (int k = 0; k < offset; k++)
                {
                    if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                    {
                        cout << "ƫ��д�����" << endl;
                        return;
                    }
                }
            }
        }
        i2--;
    }
    fclose(wfile);
 
    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//����
void deal::ImageOver()
{
    bmp* a = this->m_EmArray[m_EmpNum-2];
    bmp* b = this->m_EmArray[m_EmpNum-1];
  
    int newheight = 0;
    int newwidth = 0;

    cout << "�������λ�ã�"<<endl;
    cout << "y����:";
    cin >> newheight;
    getchar();
    cout << "x����:";
    cin >> newwidth;
    getchar();

    while (newheight < 0 || newwidth < 0)
    {
        cout << "����ͼƬ��Χ��������������" << endl;
        cout << "����λ��:"<<endl;
        cout << "y����:";
        cin >> newheight;
        getchar();
        cout << "x����:";
        cin >> newwidth;
        getchar();
    }

    cout << "��ͼƬ����:";
    char name[100]={0};//bmp����
    cin>>name;

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");//���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "���ļ�����"<<endl;
        return;
    }

    //��ȡλͼ�ļ�ͷ��Ϣ
    BmpFileHeader wbitHead;
    wbitHead = a->fileHeader;
    //���ڽ�ȡͼ��ͷ��Դ�ļ�ͷ���ƣ������Ƚ�Դ�ļ�ͷ���ݸ����ȡ�ļ�ͷ
    //��ȡλͼ��Ϣͷ��Ϣ
    BmpFileInFoHeader wbitInfoHead;
    wbitInfoHead = a->fileInFoHeader;//ͬλͼ�ļ�ͷ����

    if (fwrite(&wbitHead, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&wbitInfoHead, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�

    RGBTriple* temp = a->surface;
    RGBTriple* temp1 = b->surface;
    RGBTriple* image = new RGBTriple[wbitInfoHead.biWidth* wbitInfoHead.biHeight];

    int offset = (wbitInfoHead.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    //������Ҫ�ı�ĸ߶���
    for (int i = a->fileInFoHeader.biHeight - 1; i >= newheight - 1 + b->fileInFoHeader.biHeight; i--) //���µ��ϣ������Ҵ�������
    {
        for (int j =0; j < a->fileInFoHeader.biWidth; j++ )
        {
            (image + (i * a->fileInFoHeader.biWidth + j))->blue = (temp + (i * a->fileInFoHeader.biWidth + j))->blue;
            (image + (i * a->fileInFoHeader.biWidth+ j))->green = (temp + (i * a->fileInFoHeader.biWidth + j))->green;
            (image + (i *a->fileInFoHeader.biWidth + j))->red = (temp + (i * a->fileInFoHeader.biWidth + j))->red;
            fwrite((char*)(image + (i * a->fileInFoHeader.biWidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    //���������������ϵ���е�������
    int i2 = b->fileInFoHeader.biHeight - 1;
    for (int i =newheight-1+b->fileInFoHeader.biHeight-1; i >= newheight-1; i--) //���µ��ϣ������Ҵ�������
    {
        if (i2 >= 0)
        {
            //������޹ص���
            for (int j = 0; j < newwidth; j++)
            {
                (image + (i * wbitInfoHead.biWidth + j))->blue = (temp + (i * wbitInfoHead.biWidth + j))->blue;
                (image + (i * wbitInfoHead.biWidth + j))->green = (temp + (i * wbitInfoHead.biWidth + j))->green;
                (image + (i * wbitInfoHead.biWidth + j))->red = (temp + (i * wbitInfoHead.biWidth + j))->red;
                fwrite((char*)(image + (i * wbitInfoHead.biWidth + j)), sizeof(RGBTriple), 1, wfile);
            }
            //������йص���
            for (int j = newwidth; j < newwidth + b->fileInFoHeader.biWidth; j++)
            {
                (image + (i * wbitInfoHead.biWidth + j))->blue = (temp1 + (i2 * b->fileInFoHeader.biWidth + j - newwidth))->blue;
                (image + (i * wbitInfoHead.biWidth + j))->green = (temp1 + (i2 * b->fileInFoHeader.biWidth + j - newwidth))->green;
                (image + (i * wbitInfoHead.biWidth + j))->red = (temp1 + (i2 * b->fileInFoHeader.biWidth + j - newwidth))->red;
                fwrite((char*)(image + (i * wbitInfoHead.biWidth + j)), sizeof(RGBTriple), 1, wfile);
            }
            //������޹ص���
            for (int j = newwidth + b->fileInFoHeader.biWidth; j < a->fileInFoHeader.biWidth; j++)
            {
                (image + (i * wbitInfoHead.biWidth + j))->blue = (temp + (i * wbitInfoHead.biWidth + j))->blue;
                (image + (i * wbitInfoHead.biWidth + j))->green = (temp + (i * wbitInfoHead.biWidth + j))->green;
                (image + (i * wbitInfoHead.biWidth + j))->red = (temp + (i * wbitInfoHead.biWidth + j))->red;
                fwrite((char*)(image + (i * wbitInfoHead.biWidth + j)), sizeof(RGBTriple), 1, wfile);
            }
            if (offset != 0)
            {
                char ign;
                for (int k = 0; k < offset; k++)
                {
                    if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                    {
                        cout << "ƫ��д�����" << endl;
                        return;
                    }
                }
            }
        }
        i2--;
    }
    //��ƫ���޹ص���
    for (int i = newheight-2; i >=0; i--) 
    {
        for (int j = 0; j < a->fileInFoHeader.biWidth; j++)
        {
            (image + (i * a->fileInFoHeader.biWidth + j))->blue = (temp + (i * a->fileInFoHeader.biWidth + j))->blue;
            (image + (i * a->fileInFoHeader.biWidth + j))->green = (temp + (i * a->fileInFoHeader.biWidth + j))->green;
            (image + (i * a->fileInFoHeader.biWidth + j))->red = (temp + (i * a->fileInFoHeader.biWidth + j))->red;
            fwrite((char*)(image + (i * a->fileInFoHeader.biWidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    fclose(wfile);

    clearrectangle(80, 70, 770, 850);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(0);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(0);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(0);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(0);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//����
void deal::ImageBig()
{
    bmp* a = this->m_EmArray[m_EmpNum-1];
    cout << endl;
    cout << "��ͼƬ����:";
    char name[100]={0};//bmp����
    cin>>name;

    int newheight = 0;//��ͼƬ�߶�
    int newwidth = 0;//��ͼƬ���
    cout << "��ͼƬ�߶�:";
    cin >> newheight;
    getchar();
    cout << "��ͼƬ���:";
    cin >> newwidth;
    getchar();

    while (newheight <= 0 || newwidth <= 0)
    {
        cout << "�޷���ȡ����СͼƬ�����������룡" << endl;
        cout << "��ͼƬ�߶�:";
        cin >> newheight;
        getchar();
        cout << "��ͼƬ���:";
        cin >> newwidth;
        getchar();
    }

    //��ȡλͼ�ļ�ͷ��Ϣ
    BmpFileHeader wbitHead;
    wbitHead = a->fileHeader;
    //���ڽ�ȡͼ��ͷ��Դ�ļ�ͷ���ƣ������Ƚ�Դ�ļ�ͷ���ݸ����ȡ�ļ�ͷ
    //��ȡλͼ��Ϣͷ��Ϣ
    BmpFileInFoHeader wbitInfoHead;
    wbitInfoHead = a->fileInFoHeader;//ͬλͼ�ļ�ͷ����

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");//���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "���ļ�����"<<endl;
        return;
    }

    wbitInfoHead.biWidth = newwidth;
    wbitInfoHead.biHeight = newheight;
    int mywritewidth = WIDTHBYTES(wbitInfoHead.biWidth * wbitInfoHead.biBitCount);
    //BMPͼ��ʵ��λͼ�������Ŀ��Ϊ4byte�ı������ڴ˼���ʵ�����������  
    wbitInfoHead.biSizeImages = mywritewidth * wbitInfoHead.biHeight;//����λͼʵ����������С
    wbitHead.bfSize = 54 + wbitInfoHead.biSizeImages;//λͼ�ļ�ͷ��СΪλͼ��������С����54byte

    if (fwrite(&wbitHead, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&wbitInfoHead, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�

    //�����ڴ�ռ��Դͼ�����ڴ�   
    RGBTriple* image = new RGBTriple[newheight * newwidth];
   
    int offset = (wbitInfoHead.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    /*******************ͼ������******************/
    /*******************˫���Բ�ֵ******************/
    RGBTriple* temp = a->surface;
    for (int i = newheight - 1; i >= 0; i--)
    {
        for (int j = 0; j < newwidth; j++)
        {
            //��Ӧԭͼ������
            double X = j * a->fileInFoHeader.biWidth / newwidth;
            double Y = i * a->fileInFoHeader.biHeight / newheight;

            int OX = X;//ԭ���X�����꣬ȡ��
            int OY = Y;//ԭ���Y�����꣬ȡ��

            double distanceX = Y - OY;//����y����ľ���
            double distanceY = X - OX;//����x����ľ���

            int BX = OX + 1;
            int BY = OY;
            int CX = OX;
            int CY = OY + 1;
            int DX = OX + 1;
            int DY = OY + 1;

            //����Խ������
            if (OX + 1 >= a->fileInFoHeader.biWidth)
            {
                BX = OX;
                BY = OY;
                DX = CX;
                DY = CY;
            }
            if (OY + 1 >= a->fileInFoHeader.biHeight)
            {
                CX = OX;
                CY = OY;
                DX = BX;
                DY = BY;
            }

            (image + (i * newwidth + j))->blue = (temp + (OY * a->fileInFoHeader.biWidth + OX))->blue * (1 - distanceX) * (1 - distanceY)
                + (temp + (BY * a->fileInFoHeader.biWidth + BX))->blue * distanceY * (1 - distanceX)
                + (temp + (CY * a->fileInFoHeader.biWidth + CX))->blue * distanceX * (1 - distanceY)
                + (temp + (DY * a->fileInFoHeader.biWidth + DX))->blue * distanceY * distanceX;
            (image + (i * newwidth + j))->green = (temp + (OY * a->fileInFoHeader.biWidth + OX))->green * (1 - distanceX) * (1 - distanceY)
                + (temp + (BY * a->fileInFoHeader.biWidth + BX))->green * distanceY * (1 - distanceX)
                + (temp + (CY * a->fileInFoHeader.biWidth + CX))->green * distanceX * (1 - distanceY)
                + (temp + (DY * a->fileInFoHeader.biWidth + DX))->green * distanceY * distanceX;
            (image + (i * newwidth + j))->red = (temp + (OY * a->fileInFoHeader.biWidth + OX))->red * (1 - distanceX) * (1 - distanceY)
                + (temp + (BY * a->fileInFoHeader.biWidth + BX))->red * distanceY * (1 - distanceX)
                + (temp + (CY * a->fileInFoHeader.biWidth + CX))->red * distanceX * (1 - distanceY)
                + (temp + (DY * a->fileInFoHeader.biWidth + DX))->red * distanceY * distanceX;

            fwrite((char*)(image + (i * newwidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    fclose(wfile);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//��ת
void deal::ImageTurn()
{
    bmp* a = this->m_EmArray[m_EmpNum-1];
    cout << endl;
    cout << "��ͼƬ����:";
    char name[100]={0};//bmp����
    cin>>name;

    int angle=0;
    cout << "please input the rotate angle : ";
    cin >> angle;
    getchar();
    //�Ƕ���ת��Ϊ������
    double thelta = (double)(1.0*angle * PI / 180);
    auto cosa = (double)cos(thelta);
    auto sina = (double)sin(thelta);

    //��ȡλͼ�ļ�ͷ��Ϣ
    BmpFileHeader wbitHead;
    wbitHead = a->fileHeader;
    //���ڽ�ȡͼ��ͷ��Դ�ļ�ͷ���ƣ������Ƚ�Դ�ļ�ͷ���ݸ����ȡ�ļ�ͷ
    //��ȡλͼ��Ϣͷ��Ϣ
    BmpFileInFoHeader wbitInfoHead;
    wbitInfoHead = a->fileInFoHeader;//ͬλͼ�ļ�ͷ����

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");
    //���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "lose";
        return;
    }

    int width =a->fileInFoHeader.biWidth;
    int height = a->fileInFoHeader.biHeight;

    //������ͼ�Ŀ�Ⱥ͸߶�
    //ԭͼ���ĸ�������
    auto SrcX1 = (float)(-0.5 * width);
    auto SrcY1 = (float)(0.5 * height);
    auto SrcX2 = (float)(0.5 * width);
    auto SrcY2 = (float)(0.5 * height);
    auto SrcX3 = (float)(-0.5 * width);
    auto SrcY3 = (float)(-0.5 * height);
    auto SrcX4 = (float)(0.5 * width);
    auto SrcY4 = (float)(-0.5 * height);
    //��ͼ���ĸ�������
    float DstX1 = cosa * SrcX1 + sina * SrcY1;
    float DstY1 = -sina * SrcX1 + cosa * SrcY1;
    float DstX2 = cosa * SrcX2 + sina * SrcY2;
    float DstY2 = -sina * SrcX2 + cosa * SrcY2;
    float DstX3 = cosa * SrcX3 + sina * SrcY3;
    float DstY3 = -sina * SrcX3 + cosa * SrcY3;
    float DstX4 = cosa * SrcX4 + sina * SrcY4;
    float DstY4 = -sina * SrcX4 + cosa * SrcY4;
    //������ͼ�Ŀ�Ⱥ͸߶�
    auto newWidth = (int)(max(fabs(DstX4 - DstX1), fabs(DstX3 - DstX2)) + 0.5);
    auto newHeight = (int)(max(fabs(DstY4 - DstY1), fabs(DstY3 - DstY2)) + 0.5);
    wbitInfoHead.biHeight = newHeight;
    wbitInfoHead.biWidth = newWidth;
    int mywritewidth = WIDTHBYTES(wbitInfoHead.biWidth * wbitInfoHead.biBitCount);
    //BMPͼ��ʵ��λͼ�������Ŀ��Ϊ4byte�ı������ڴ˼���ʵ�����������  
    wbitInfoHead.biSizeImages = mywritewidth * wbitInfoHead.biHeight;//����λͼʵ����������С
    wbitHead.bfSize = 54 + wbitInfoHead.biSizeImages;//λͼ�ļ�ͷ��СΪλͼ��������С����54byte

    if (fwrite(&wbitHead, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&wbitInfoHead, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�

    //ԭ������ת����
    double rotateX = width / 2;
    double rotateY = height / 2;
    //��ͼ������
    double write_rotateX = newWidth / 2;
    double write_rotateY = newHeight / 2;

    //�����ڴ�ռ��Դͼ�����ڴ�   
    RGBTriple* image = new RGBTriple[newHeight * newWidth];

    int offset = (wbitInfoHead.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    /*for (int i = newHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < newWidth; j++)
        {
            (image + (i * newWidth + j))->blue = 193;
            (image + (i * newWidth + j))->green = 182;
            (image + (i * newWidth + j))->red = 255;
            fwrite((char*)(image + (i * newWidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                fwrite(&ign, sizeof(char), 1, wfile);
            }
        }
    }*///���Դ���
    RGBTriple* temp = a->surface;
    for (int i = newHeight - 1; i >= 0; i--)
    {
        for (int j = 0; j < newWidth; j++)
        {
            // ���ù�ʽ�������ԭ���ĵ�ĵط�
            double oy =(j - write_rotateX) * sina + (i - write_rotateY) * cosa + rotateY;
            double ox =(j - write_rotateX) * cosa - (i - write_rotateY) * sina + rotateX;

            //�ж�ԭ���ĵ��Ƿ���ڣ�������Ϊ��ɫ
            if (oy < 0 || oy >= a->fileInFoHeader.biHeight || ox < 0 || ox >= a->fileInFoHeader.biWidth)
            {
                (image + (i * newWidth + j))->blue = 0;
                (image + (i * newWidth + j))->green = 0;
                (image + (i * newWidth + j))->red= 0;
                fwrite((char*)(image + (i * newWidth + j)), sizeof(RGBTriple), 1, wfile);
            }
            else
            {
                //˫���Բ�ֵ
                int OX = ox;//ԭ���X�����꣬ȡ��
                int OY = oy;//ԭ���Y�����꣬ȡ��

                double distanceX = oy - OY;//����y����ľ���
                double distanceY = ox - OX;//����x����ľ���

                int BX = OX + 1;
                int BY = OY;
                int CX = OX;
                int CY = OY + 1;
                int DX = OX + 1;
                int DY = OY + 1;

                //����Խ������
                if (OX + 1 >= a->fileInFoHeader.biWidth)
                {
                    BX = OX;
                    BY = OY;
                    DX = CX;
                    DY = CY;
                }
                if (OY + 1 >= a->fileInFoHeader.biHeight)
                {
                    CX = OX;
                    CY = OY;
                    DX = BX;
                    DY = BY;
                }

                (image + (i * newWidth + j))->blue = (temp + (OY * a->fileInFoHeader.biWidth + OX))->blue * (1 - distanceX) * (1 - distanceY)
                    + (temp + (BY * a->fileInFoHeader.biWidth + BX))->blue * distanceY * (1 - distanceX)
                    + (temp + (CY * a->fileInFoHeader.biWidth + CX))->blue * distanceX * (1 - distanceY)
                    + (temp + (DY * a->fileInFoHeader.biWidth + DX))->blue * distanceY * distanceX;
                (image + (i * newWidth + j))->green = (temp + (OY * a->fileInFoHeader.biWidth + OX))->green * (1 - distanceX) * (1 - distanceY)
                    + (temp + (BY * a->fileInFoHeader.biWidth + BX))->green * distanceY * (1 - distanceX)
                    + (temp + (CY * a->fileInFoHeader.biWidth + CX))->green * distanceX * (1 - distanceY)
                    + (temp + (DY * a->fileInFoHeader.biWidth + DX))->green * distanceY * distanceX;
                (image + (i * newWidth + j))->red = (temp + (OY * a->fileInFoHeader.biWidth + OX))->red * (1 - distanceX) * (1 - distanceY)
                    + (temp + (BY * a->fileInFoHeader.biWidth + BX))->red * distanceY * (1 - distanceX)
                    + (temp + (CY * a->fileInFoHeader.biWidth + CX))->red * distanceX * (1 - distanceY)
                    + (temp + (DY * a->fileInFoHeader.biWidth + DX))->red * distanceY * distanceX;
                fwrite((char*)(image + (i * newWidth + j)), sizeof(RGBTriple), 1, wfile);
            }
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    fclose(wfile);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//�Ҷ�
void deal::ImageGray()
{
    cout << endl;
    bmp* a = this->m_EmArray[m_EmpNum - 1];

    cout << "��ͼƬ����:";
    char name[100] = { 0 };//bmp����
    cin>>name;

    a->writePic(makeGary, name);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//��ֵ��
void deal::binaryimage()
{
    cout << endl;
    bmp* a = this->m_EmArray[m_EmpNum - 1];

    cout << "��ͼƬ����:";
    char name[100] = { 0 };//bmp����
    cin>>name;

    RGBQUAD rg[2];

    BmpFileHeader newfile= a->fileHeader;
    BmpFileInFoHeader newfilein = a->fileInFoHeader;

    newfilein.biBitCount = 8;
    newfilein.biClrUsed = 2;//��ɫ��������������ֵͼΪ2
    newfilein.biClrImportant = 0;//��Ҫ��ɫ����Ϊ0����ʾ����Ҫ
    newfile.bfOffBits= sizeof(BmpFileHeader) + sizeof(BmpFileInFoHeader) + 2 * sizeof(RGBQUAD);
    //������ƫ�����������ļ�ͷ����Ϣͷ��������Ĵ�С֮��
    newfile.bfSize = newfile.bfOffBits + newfilein.biSizeImages;//�ļ���С������ƫ����������������С

    rg[0].rgbBlue = rg[0].rgbGreen = rg[0].rgbRed = rg[0].rgbReserved = 0;//��ɫ����ɫΪ��ɫ��Ӧ������Ϊ0
    rg[1].rgbBlue = rg[1].rgbGreen = rg[1].rgbRed = 255;//��ɫ��Ӧ������Ϊ1
    rg[1].rgbReserved = 0;

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");//���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "���ļ�����";
        return;
    }

    if (fwrite(&newfile, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&newfilein, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�
    if (fwrite(&rg, 1, 2*sizeof(RGBQUAD), wfile) != 8)
    {
        cout << "�����ɫ��" << endl;
        return;
    }

    RGBTriple* temp = a->surface;
    unsigned char b;//�洢ÿ�����صĻҶ�ֵ���ֵ
    unsigned char* c;//�洢ÿ�����صĶ�ֵ

    /*����ɫͼתΪ��ֵͼ*/
    c = (unsigned char*)malloc((newfilein.biWidth + 3) / 4 * 4);
    //������c����Ŀ��ͼÿ��������ռ��С�Ŀռ�,ͬ�����ֽڶ���

    for (int i = 0; i < newfilein.biHeight; i++) 
    {//����ͼ��ÿ�е�ѭ��
        for (int j = 0; j < newfilein.biWidth; j++) 
        {//ѭ�����ؿ�ȴ�,�Ͳ������������ֽ����λ
            b = (int)(0.114 * (float)temp->blue + 0.587 * (float)temp->green + 0.299 * (float)temp->red);
            //a��ÿ�����ֽڷֱ����BGR���������ϲ�ͬȨֵת��Ϊ�Ҷ�ֵ
            if (190 <= (int)b) b = 1;//���Ҷ�ֵת��Ϊ��ֵ������ѡȡ����ֵΪ190
            else b = 0;
            c[j] = b;//�洢ÿ�еĶ�ֵ
         }
         fwrite(c, (newfilein.biWidth + 3) / 4 * 4, 1, wfile);
         //����ֵ�������ֽ����д���ļ�,���λû�г�ʼ��,Ϊ���ֵ
    }
    fclose(wfile);
}
//���
void deal::ImageAdd()
{
    bmp* a = this->m_EmArray[m_EmpNum-1];
    cout << endl;
    cout << "��ͼƬ����:";
    char name[100]={0};//bmp����
    cin>>name;

    BmpFileHeader wbitHead;
    wbitHead = a->fileHeader;
    //���ڽ�ȡͼ��ͷ��Դ�ļ�ͷ���ƣ������Ƚ�Դ�ļ�ͷ���ݸ����ȡ�ļ�ͷ
    //��ȡλͼ��Ϣͷ��Ϣ
    BmpFileInFoHeader wbitInfoHead;
    wbitInfoHead = a->fileInFoHeader;//ͬλͼ�ļ�ͷ����

    FILE* wfile;//����ļ�
    wfile = fopen(name, "wb");//���ļ�Ϊ�洢�޸ĺ�ͼ����׼��
    if (wfile == NULL)
    {
        cout << "���ļ�����"<<endl;
        return;
    }

    if (fwrite(&wbitHead, 1, sizeof(BITMAPFILEHEADER), wfile) != 14)
    {
        cout << "�����ļ�ͷ" << endl;
        return;
    }//д��λͼ�ļ�ͷ��Ϣ������ļ�
    if (fwrite(&wbitInfoHead, 1, sizeof(BITMAPINFOHEADER), wfile) != 40)
    {
        cout << "������Ϣͷ" << endl;
        return;
    }//д��λͼ��Ϣͷ��Ϣ������ļ�

    int offset = (wbitInfoHead.biWidth * 3) % 4;//�ڴ�������ƫ�ƣ�4�ı���
    if (offset != 0)
    {
        offset = 4 - offset;
    }

    RGBTriple* temp = a->surface;
    //�����ڴ�ռ��Դͼ�����ڴ�   
    RGBTriple* image = new RGBTriple[wbitInfoHead.biWidth*wbitInfoHead.biHeight];

    int N=0;//������
    int color=0;
    double x[50]={0}, y[50]={0};
    cout << "�������Ķ���εĶ�������";
    cin >> N;
    cout << "�����������Ķ������꣺"<<endl;
    for (int i = 0; i < N; i++)
    {
        cout << "�����" << i + 1 << "�����������:" << endl;
        cout << "x,y:";
        scanf_s("%lf,%lf", &x[i], &y[i]);
        while (x[i] >= wbitInfoHead.biWidth || y[i] >= wbitInfoHead.biHeight)
        {
            cout << "������Χ�������䣺" << endl;
            cout << "�����" << i + 1 << "�����������:" << endl;
            cout << "x,y:";
            scanf_s("%lf,%lf", &x[i], &y[i]);
        }
    }

    cout << "��ѡ����ɫ��1 �ڣ�2 �����ɫ  "<< "3 ����4 ������5 ��"<< "6 ��  7   ��  8 ��   9 ��"<< "10 ��   11 ǳ��\n ";
    cout << "��������ɫ��";
    cin >> color;
    int arr[3]={0};
    //BGR
    switch (color)
    {
    case 1:
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 0;
        break;
    case 2:
        arr[0] = 20;
        arr[1] = 128;
        arr[2] = 48;
        break;
    case 3:
        arr[0] = 255;
        arr[1] = 0;
        arr[2] = 0;
        break;
    case 4:
        arr[0] = 112;
        arr[1] = 25;
        arr[2] = 25;
        break;
    case 5:
        arr[0] = 0;
        arr[1] = 255;
        arr[2] = 0;
        break;
    case 6:
        arr[0] = 255;
        arr[1] = 255;
        arr[2] = 0;
        break;
    case 7:
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 255;
        break;
    case 8:
        arr[0] = 240;
        arr[1] = 32;
        arr[2] = 160;
        break;
    case 9:
        arr[0] = 42;
        arr[1] = 42;
        arr[2] = 128;
        break;
    case 10:
        arr[0] = 0;
        arr[1] = 255;
        arr[2] = 255;
        break;
    case 11:
        arr[0] = 192;
        arr[1] = 192;
        arr[2] = 192;
        break;
    default:
        break;
    }

    double new_y[50] = { 0 };
    int n = 0;//�ཻ�ĵ���
    double suitable_x[50]={0};

    cout << "����Ϊԭͼ�еĴ��·�Χ��" << endl;
    for (int i = 0; i < N; i++)
     //��ʱ�붥���������ɱպ϶����
    {
        if (i == N - 1)
        {
            line(80+x[i], 70+y[i], 80+x[0], 70+y[0]);
        }
        else
        {
            line(80+x[i], 70+y[i], 80+x[i + 1], 70+y[i + 1]);
        }
    }

    //����ɨ���߷�Χ
    double min_y = find_min(y, N);
    cout << min_y << endl;
    double max_y = find_max(y, N);
    cout << max_y << endl;
    //���漰�������Ĳ���
    for (int i = wbitInfoHead.biHeight - 1; i > max_y; i--)
    {
        for (int j = 0; j < wbitInfoHead.biWidth; j++)
        {
            (image + (i * wbitInfoHead.biWidth + j))->blue = (temp + (i * a->fileInFoHeader.biWidth + j))->blue;
            (image + (i * wbitInfoHead.biWidth + j))->green = (temp + (i * a->fileInFoHeader.biWidth + j))->green;
            (image + (i * wbitInfoHead.biWidth + j))->red = (temp + (i * a->fileInFoHeader.biWidth + j))->red;
            fwrite((char*)(image + (i * wbitInfoHead.biWidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    //-------------------------����������-------------------------//
    for (int now_y = max_y; now_y > min_y; now_y--)
    {
        Suitable_x(x, y, N, now_y, suitable_x, n);
        sort_min_to_max(suitable_x, n);  //��С��������,ʵ���������
        suitable_x[n] = wbitInfoHead.biWidth;
        //����������޹ص�������ȴ���
        for (int k = 0; k < suitable_x[0]; k++)
        {
            (image + (now_y * wbitInfoHead.biWidth + k))->blue = (temp + (now_y * a->fileInFoHeader.biWidth + k))->blue;
            (image + (now_y * wbitInfoHead.biWidth + k))->green = (temp + (now_y * a->fileInFoHeader.biWidth + k))->green;
            (image + (now_y * wbitInfoHead.biWidth + k))->red = (temp + (now_y * a->fileInFoHeader.biWidth + k))->red;
            fwrite((char*)(image + (now_y * wbitInfoHead.biWidth + k)), sizeof(RGBTriple), 1, wfile);
        }
        for (int i = 0; i < n; i += 2)
         //����Ϊһ�飬����ѭ��
        {
            for (int now_x = suitable_x[i]; now_x < suitable_x[i + 1]; now_x++)
                //ȷ����ɨ�����ϣ�Ҫ���ķ�Χ
            {
                (image + (now_y * wbitInfoHead.biWidth + now_x))->blue = arr[0];
                (image + (now_y * wbitInfoHead.biWidth + now_x))->green = arr[1];
                (image + (now_y * wbitInfoHead.biWidth + now_x))->red = arr[2];
                fwrite((char*)(image + (now_y * wbitInfoHead.biWidth + now_x)), sizeof(RGBTriple), 1, wfile);
            }
            for (int now_x = suitable_x[i+1]; now_x < suitable_x[i+2]; now_x++)
                //����ɨ�����ϣ�Ҫ���ķ�Χ
            {
                (image + (now_y * wbitInfoHead.biWidth + now_x))->blue = (temp + (now_y * a->fileInFoHeader.biWidth + now_x))->blue;
                (image + (now_y * wbitInfoHead.biWidth + now_x))->green = (temp + (now_y * a->fileInFoHeader.biWidth + now_x))->green;
                (image + (now_y * wbitInfoHead.biWidth + now_x))->red = (temp + (now_y * a->fileInFoHeader.biWidth + now_x))->red;
                fwrite((char*)(image + (now_y * wbitInfoHead.biWidth + now_x)), sizeof(RGBTriple), 1, wfile);
            }
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ��д�����" << endl;
                    return;
                }
            }
        }
    }
    //����������޹ص���
    for (int i = min_y; i >=0; i--)
    {
        for (int j = 0; j < wbitInfoHead.biWidth; j++)
        {
            (image + (i * wbitInfoHead.biWidth + j))->blue = (temp + (i * a->fileInFoHeader.biWidth + j))->blue;
            (image + (i * wbitInfoHead.biWidth + j))->green = (temp + (i * a->fileInFoHeader.biWidth + j))->green;
            (image + (i * wbitInfoHead.biWidth + j))->red = (temp + (i * a->fileInFoHeader.biWidth + j))->red;
            fwrite((char*)(image + (i * wbitInfoHead.biWidth + j)), sizeof(RGBTriple), 1, wfile);
        }
        if (offset != 0)
        {
            char ign;
            for (int k = 0; k < offset; k++)
            {
                if (fwrite(&ign, sizeof(char), 1, wfile) != 1)
                {
                    cout << "ƫ�ƴ���" << endl;
                    return;
                }
            }
        }
    }
    fclose(wfile);

    bmp* a1 = NULL;
    if (a->fileInFoHeader.biBitCount == 8)
    {
        a1 = new bmp2;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 24)
    {
        a1 = new bmp1;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 16)
    {
        a1 = new bmp3;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else if (a->fileInFoHeader.biBitCount == 1)
    {
        a1 = new bmp4;
        a1->readPic(name);
        a1->ShowImage(1);
    }
    else
    {
        cout << "�����ڴ���Ŀ���ܶ�ȡ��ͼƬ��ʽ��������ѡ��ͼƬ��ʽ����" << endl;
        return;
    }

    bmp** newspace = new bmp * [m_EmpNum + 1];
    if (this->m_EmArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newspace[i] = this->m_EmArray[i];
        }
    }
    newspace[this->m_EmpNum] = a1;
    m_EmpNum++;
    //�ͷ�ԭ�пռ�
    delete[]this->m_EmArray;

    //�����¿ռ��ָ��
    this->m_EmArray = newspace;
}
//��ⷽ�̵�k,bֵ
void deal::function_line(double x1, double y1, double x2, double y2, double& k, double& b)
{
    if (x2 - x1 == 0)
        //��ֱ��
    {
        k = -9999;
        //��x�ύ��
        b = x1;
        return;
    }
    //����б��
    k = (y2 - y1) / (x2 - x1);
    b = y1 - k * x1;
}
//����ֱ�ߵ�y
double deal::solve_y(double k, double b, double x)
{
    return k * x + b;
}
//����ֱ�ߵ�x
double deal::solve_x(double k, double b, double y)
{
    if (k == -9999)
        return b;
    int m = (y - b) / k;
    return m;
}
//�ҳ�ɨ������߽��ཻ�ĵ㣬��������suitable_x[]�У����ཻ�ĵ���������n��
void deal::Suitable_x(double x[], double y[], int N, double now_y, double suitable_x[], int& n)
//ע����suitable_x��n�ĵ�ַ
//x[]-----------����x����
//y[]-----------����y����
//N-------------����ĸ���
//now_y---------��ǰ��ɨ����y
//suitable_x[]--ɨ������߽��ཻ�ĵ��x����
//n-------------�ཻ�ĵ���
{
    n = 0;
    int t = 0;
    double k, b;
    //ÿ�����Ƿ���ɨ�����н���
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            if ((y[i] < now_y && now_y <= y[0]) ||( y[0] < now_y && now_y <= y[i]))
                //�ж�ֱ���Ƿ�����һ��ֱ��,�������
            {
                function_line(x[0], y[0], x[i], y[i], k, b);
                suitable_x[t++] = solve_x(k, b, now_y);
            }
        }
        else
         //ɨ��������
        {
            if ((y[i] < now_y && now_y <= y[i + 1]) ||( y[i + 1] < now_y && now_y <= y[i]))
             //�ж�ɨ���߹�����ֱ�ߵķ�Χ
            {
                function_line(x[i], y[i], x[i + 1], y[i + 1], k, b);
                suitable_x[t++] = solve_x(k, b, now_y);//�ѽ����x������suitable_x[]��
            }
        }
    }
    n = t;
}
//����----��С��������
void deal::sort_min_to_max(double suitable_x[], int n)
{
    double temp;
    int right = n - 1;
    int left = 0;
    quick_sort(suitable_x, left, right);
    //ð������
    //for (int i = 0; i < n - 1; i++)
    //{
      //  for (int j = i + 1; j < n; j++) 
      // {
      //      if (suitable_x[i] > suitable_x[j]) 
      //     {
      //          double temp = suitable_x[i];
      //          suitable_x[i] = suitable_x[j];
      //          suitable_x[j] = temp;
      //      }
      //  }
   //}
}
//��������
void deal::quick_sort(double s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ���� 
        quick_sort(s, i + 1, r);
    }
}
//�������Ԫ��ֵ
double deal::find_max(double elem[], int N)
{
    double max = elem[0];
    for (int i = 0; i < N; i++)
    {
        if (elem[i] > max)
        {
            max = elem[i];
        }
    }
    return max;
}
//�����С��Ԫ��ֵ
double deal::find_min(double elem[], int N)     
{
    double min = elem[0];
    for (int i = 0; i < N; i++)
    {
        if (elem[i] < min)
        {
            min = elem[i];
        }
    }
    return min;
}
//����
void deal::closeImage()
{
    //��ȡ���
    HWND hnd = GetHWnd();
    //��������
    int isok = MessageBox(hnd, "��������ʾ���һ������ͼƬ", "��ʾ", MB_OKCANCEL);
    if (isok == IDOK&&m_EmpNum!=0)
    {
        clearrectangle(80, 70, 750, 850);
        TCHAR s7[10] = "����";
        button(700, 820, 40, 20, s7);
        bmp* a = this->m_EmArray[m_EmpNum - 1];
        a->ShowImage(0);
        getchar();
    }
    else
    {
        cout << "go on!";
    }
}
//�رմ���
void deal::close()
{
    HWND a = GetHWnd();
    int i= MessageBox(a, "�Ƿ�ر�", "��Ϣ��", MB_OKCANCEL);
    if (i == IDOK)
    {
        closegraph();
        cout << "��ӭʹ�ã��´��ټ���";
        exit(0);
    }
}
//��ʾȫ��
void deal::showall()
{
    cout << endl;
    bmp* a = NULL;
    int i;
    for (i = 0; i < m_EmpNum; i++)
    {
        a = this->m_EmArray[i];
        cout << *a;
        getchar();
    }
}
//��������
deal::~deal()
{
    if (this->m_EmArray != NULL)
    {
        delete[]this->m_EmArray;
        this->m_EmArray = NULL;
        m_EmpNum = 0;
    }
}