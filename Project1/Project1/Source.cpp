#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void entering(string name);
void showfile(string name);
void find(string s, string name1, string name2);
void openError();

int main()
{
	cout << "\tCreated by Maria Zhurba, variant 11, IS-82" << endl;

	cout << "Enter the name of file, you want to open: " << endl;
	string name1; //����� ��� ���� �����
	getline(cin, name1);

	cout << "Enter the strings of this file:" << endl;
	cout << "(If you want to stop writing, just type 0)" << endl;
	entering(name1);

	cout << "File you entered: " << endl;
	showfile(name1);

	cout << "Enter the string to find: " << endl;
	string s; //�����, ���� �� ������
	getline(cin, s);

	cout << "Enter the name of file to write: " << endl;
	string name2;  //����� ��� ���� �����
	getline(cin, name2);

	find(s, name1, name2);

	cout << "File you get" << endl;
	showfile(name2);
	system("pause");

}

//-------------------������� ��� ���������� �����-------------------//
void entering(string name)
{
	ofstream ofile; //���������� ������ ������ � �����
	ofile.open(name);         //������� ���� ��� ������
	if (!ofile.is_open()) openError(); //���� ���� �� ��������

	//bool first = true;
	string s;
	getline(cin, s);       //�������� ����� � ������
	while (s[0] != '0')  //���� ���������� �� ��� "0"
	{
		//if (first) first = false;
		//else ofile << endl;
		
		ofile << s << endl;      //�������� ����� � ����
		getline(cin, s);       //�������� ����� � ������
	} 

	ofile.close();          //������� ����
}

//-------------------������� ��� ��������� �����-------------------//

void showfile(string name)
{
	ifstream ifile;		  //���������� ������ ������� � �����
	ifile.open(name);     //������� ���� ��� �������
	if (!ifile.is_open()) openError(); //���� ���� �� ��������

	string s;
	while (!ifile.eof()) //���� �� ����� �����
	{
		getline(ifile, s); //������� ����� � �����
		cout << s << endl;
	}
	ifile.close();        //������� ����
}



//-------------------������� ��� ������ ������� � �����-----------//
void find(string s, string name1, string name2)
{
	ifstream ifile;
	ifile.open(name1); //�������� ����� ��� �������
	if (!ifile.is_open()) openError(); //���� ���� �� ��������

	ofstream ofile;
	ofile.open(name2); //�������� ����� ��� ������
	if (!ofile.is_open()) openError(); //���� ���� �� ��������

	int k = 0;
	while (!ifile.eof()) //���� �� ����� ����� 
	{
		string istr;     //������� ����� (�����)
		getline(ifile, istr); //������� ����� � �����1
		if (istr.find(s) != string::npos) //���� ����� ������ ������� 
		{
			k++;
			ofile << istr << endl; //�������� ����� � ����2
		}

	}
	ofile << k; //������ ������� �������� � ����� �����2

	ifile.close(); //������� ����
	ofile.close(); //������� ����

}

void openError()
{
	cout << "There is a problem with file's opening" << endl << "Please, restart the program and try again..." << endl;
	system("pause");
	exit(0); //��������� ��������� ��������
}

//find() - ������� ������ ������� � �����
//string::npos - ��������, ��� ����������� == ������
