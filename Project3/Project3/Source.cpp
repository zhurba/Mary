#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
using namespace std;

struct Record 
{
	int i;
};


void inputRecord(Record& rec) 
{
	cout << "Input int i: ";
	cin >> rec.i;
}

void inputData(Record* data, size_t& datacount) 
{
	for (size_t i = 0; i < datacount; i++) 
	{
		inputRecord(data[i]);
		
		cout << "Any data else? y/n" << endl;
		if (_getch() != 'y')
		{
			datacount = i + 1;
			break;
		}
	} 
}

bool writeDataToFile(const char* filename, Record* data, size_t datacount)
{
	FILE* file = fopen(filename, "ab");
	if (!file)
	{
		cerr << "Sorry, can't open file " << filename << endl;
		return false;
	}
	else
	{

		fseek(file, 0L, SEEK_END);
		fwrite(data, sizeof(Record), datacount, file);

		return true;
	}
}

Record* readDataFromFile(const char* filename)
{

	FILE* file = fopen(filename, "rb");
	if (!file)
	{
		cerr << "Sorry, can't open file " << filename << endl;
		return NULL;
	}
	else
	{
		fseek(file, 0L, SEEK_END);
		size_t fsize = ftell(file);

		Record* data = new Record[fsize / sizeof(Record)];

		fseek(file, 0L, SEEK_SET);
		fread(data, fsize, 1, file);

		return data;
	}

}

void main() 
{
	size_t datacount = 10;
	Record* data = new Record[datacount];

	size_t realcount = datacount;

	inputData(data, realcount);

	writeDataToFile("file.dat", data, realcount);

	delete data[];
}
