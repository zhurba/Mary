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
	string name1; //рядок для імені файлу
	getline(cin, name1);

	cout << "Enter the strings of this file:" << endl;
	cout << "(If you want to stop writing, just type 0)" << endl;
	entering(name1);

	cout << "File you entered: " << endl;
	showfile(name1);

	cout << "Enter the string to find: " << endl;
	string s; //рядок, який ми шукаємо
	getline(cin, s);

	cout << "Enter the name of file to write: " << endl;
	string name2;  //рядок для імені файлу
	getline(cin, name2);

	find(s, name1, name2);

	cout << "File you get" << endl;
	showfile(name2);
	system("pause");

}

//-------------------Функція для заповнення файлу-------------------//
void entering(string name)
{
	ofstream ofile; //оголошення потоку запису в файлу
	ofile.open(name);         //відкрити файл для запису
	if (!ofile.is_open()) openError(); //якщо файл не відкрився

	//bool first = true;
	string s;
	getline(cin, s);       //отримати рядок з консолі
	while (s[0] != '0')  //поки користувач не ввів "0"
	{
		//if (first) first = false;
		//else ofile << endl;
		
		ofile << s << endl;      //записати рядок в файл
		getline(cin, s);       //отримати рядок з консолі
	} 

	ofile.close();          //закрити файл
}

//-------------------Функція для виведення файлу-------------------//

void showfile(string name)
{
	ifstream ifile;		  //оголошення потоку читання з файлу
	ifile.open(name);     //відкрити файл для читання
	if (!ifile.is_open()) openError(); //якщо файл не відкрився

	string s;
	while (!ifile.eof()) //доки не кінець файлу
	{
		getline(ifile, s); //зчитати рядок з файлу
		cout << s << endl;
	}
	ifile.close();        //закрити файл
}



//-------------------Функція для пошуку підрядка у рядку-----------//
void find(string s, string name1, string name2)
{
	ifstream ifile;
	ifile.open(name1); //відкриття файлу для читання
	if (!ifile.is_open()) openError(); //якщо файл не відкрився

	ofstream ofile;
	ofile.open(name2); //відкриття файлу для запису
	if (!ofile.is_open()) openError(); //якщо файл не відкрився

	int k = 0;
	while (!ifile.eof()) //доки не кінець файлу 
	{
		string istr;     //буферна змінна (рядок)
		getline(ifile, istr); //зчитати рядок з Файлу1
		if (istr.find(s) != string::npos) //якщо рядок містить підрядок 
		{
			k++;
			ofile << istr << endl; //записати рядок у Файл2
		}

	}
	ofile << k; //додати кількість входжень у кінець Файлу2

	ifile.close(); //закрити файл
	ofile.close(); //закрити файл

}

void openError()
{
	cout << "There is a problem with file's opening" << endl << "Please, restart the program and try again..." << endl;
	system("pause");
	exit(0); //припинити виконання програми
}

//find() - функція пошуку підрядка у рядку
//string::npos - значення, яке повертається == відмова
