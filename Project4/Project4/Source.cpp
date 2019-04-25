#include <iostream>
#include <conio.h>

using namespace std;

struct Date
{
	int day;
	int mounth;
	int year;
};

struct Record
{
	Date date;
	double ticketCost;
};

int compareDates(Date& d1, Date& d2)
{
	if (d1.year < d2.year) return -1;
	else
		if (d1.year > d2.year) return 1;
		else
			if (d1.mounth < d2.mounth) return -1;
			else
				if (d1.mounth > d2.mounth) return 1;
				else
					if (d1.day < d2.day) return -1;
					else
						if (d1.day > d2.day) return 1;
						else 
							return 0;
}

int compareRecords(Record& r1, Record& r2)
{
	int cmpDates = compareDates(r1.date, r2.date);

	if (cmpDates) return cmpDates;
	else
		if (r1.ticketCost < r2.ticketCost) return -1;
		else
			if (r1.ticketCost > r2.ticketCost) return 1;
			else
				return 0;
}

int f1()
{
	cout << "f1" << endl;
	return 1;
}

int f2()
{
	cout << "f2" << endl;
	return 2;
}

void fun(int a, int b){
}

void main() {
	fun(f1(), f2());

	Date d1;
	d1.day = 12;
	d1.mounth = 6;
	d1.year = 2019;

	Date d2;
	d2.day = 12;
	d2.mounth = 6;
	d2.year = 2019;

	cout << compareDates(d1, d2) << "  " << (d1==d2) << endl;

	_getch();
}