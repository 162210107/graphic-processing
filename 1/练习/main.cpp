#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"deal.h"
#include<conio.h>//getch()������ͷ�ļ�
#include<mmsystem.h>//������ý��ӿ�
#include <string>

#pragma comment(lib,"winmm.lib")//����ӿ�
void BGM()
{
	mciSendString(_T("open ./music.mp3"), 0, 0, 0);//0��0,0ΪĬ���������̨
	mciSendString(_T("play ./music.mp3"), 0, 0, 0);
}

ostream& operator<<(ostream& out, bmp& obj)
{
	cout << "����:"<<obj.mfilename << endl;
	cout << "λͼ��ʽ:" << obj.fileInFoHeader.biBitCount << endl;
	cout << "ƫ��:" << obj.offset << endl;
	cout << "��:" << obj.fileInFoHeader.biHeight<<"  ��:"<<obj.fileInFoHeader.biWidth<<endl;
    //cout << "com" << obj.fileInFoHeader.biCompression;
	return out;
}

bool IsLoggedIn() 
{
    string username, password, un, pw;
    cout << "�û���: "; 
    cin >> username;

    cout << "����: "; 
    cin >> password;

    ifstream in;
    in .open("data.txt",ios::in );
    while (!in.eof())
    {
        getline(in, un);
        if (un == username)
        {
            getline(in, pw);
            if (pw == password)
            {
                return true;
            }
            continue;
        }
        getline(in, pw);
    }
    in.close();
    return false;
}

bool IsExist(string username)
{
    string un;
    ifstream in;
    in.open("data.txt", ios::in);
    while (!in.eof())
    {
        getline(in, un);
        if (un == username)
        {
            cout << "�Ѵ��ڸ��û���" << endl;
            return FALSE;
        }
    }
    in.close();
    return true;
}

bool IsComp(string password)
{
    if (password.length() < 6)
    {
        cout << endl;
        cout << "���볤�ȹ��̣�����������" << endl;
        return FALSE;
    }
    else if (password.length() >= 21)
    {
        cout << endl;
        cout << "����̫��������������" << endl;
        return FALSE;
    }
    char p[22];
    password.copy(p, password.length(), 0);
    *(p + password.length()) = '\0';
    int a[4] = { 0 };
    for (int i = 0; i < password.length(); i++)
    {
        if (p[i] >= 'A' && p[i] <= 'Z')
        {
            a[0] = 1;
        }
        else if (p[i] >= 'a' && p[i] <= 'z')
        {
            a[1] = 1;
        }
        else if (p[i] >= '0' && p[i] <= '9')
        {
            a[2] = 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 0)
        {
            cout << endl;
            cout << "̫����" << endl;
            return FALSE;
        }
    }
    return TRUE;
}

int main() 
{
    int choice=0;

    cout << "1: ע��\n2: ��¼\n3: �˳�\nѡ��: "; 
    cin >> choice;
    if (choice == 1)
    {
        string username;

        cout << "�û���: ";
        cin >> username;
        bool check1 = IsExist(username);
        while(!check1)
        {
            cout << "�û���: ";
            cin >> username;
            check1 = IsExist(username);
        }
      
        char password[64], ch;
        int i = 0;
        cout << "����������:";
        while (true)
        {
            ch = _getch();//�޻��Ե�����
            password[i++] = ch;
            if (ch == '\r')//getch()������������س����ŷ���'/r'
            {
                password[i] = '\0';
                break;
            }
            putchar('*');
        }
        bool check2 = IsComp(password);
        while (!check2)
        {
            int i = 0;
            cout << "����������:";
            while (true)
            {
                ch = _getch();//�޻��Ե�����
                password[i++] = ch;
                if (ch == '\r')//getch()������������س����ŷ���'/r'
                {
                    password[i] = '\0';
                    break;
                }
                putchar('*');
            }
            check2 = IsComp(password);
        }
        cout << endl;

        ofstream file;
        file.open("data.txt", ios::out | ios::app);

        file << username << endl << password<<endl;
        file.close();

        cout << "ע��ɹ�������" << endl;
        system("pause");
        system("cls");
        main();
    }
    else if (choice == 2) 
    {
        bool status = IsLoggedIn();

        if(!status) 
        {
            cout << "��������㻹�����λ��ᣡ�����Զ��˳���" << endl;
            for (int i = 0; i < 2; i++)
            {
                status = IsLoggedIn();
                if (status)
                {
                    getchar();
                    cout << "��¼�ɹ�������" << endl;
            
                    BGM();
                    deal temp;
                    getchar();
                    temp.showMenu();
                    return 0;
                }
                cout << "�㻹��" << 1 - i << "����" << endl;
            }
            cout << "bye" << endl;
            system("PAUSE");
            return 0;
        }
        if(status)
        {
            cout << "��¼�ɹ�������" << endl;
            BGM();
            deal temp;
            temp.showMenu();
            return 0;
        }
    }
    else
    {
        cout << "bye" << endl;
        system("pause");
        return 0;
    }
}