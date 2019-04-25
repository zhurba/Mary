#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Element
{
	int n;
	Element *next;

};
struct Queue
{
	int count;
	Element *head, *tail;

	Queue()
	{
		head = tail = NULL;
		count = 0;
	}
};

void error(FILE *file);
void readFromFile(Queue&queue, char* name);
void push(Queue&queue, int value);
int pop(Queue&queue);
void outQueue(Queue &queue);
int minQueue(Queue &queue);
void sortQueue(Queue &queue);
void deleteList(Queue &queue);

int main()
{
	cout << "\t||Created by Maria Zhurba, variant 11, IS - 82||" << endl;

	cout << "Enter the name of file: " << endl;
	char name[10];  // имя файла
	//cin >> name;

	Queue data;
	//readFromFile(data,name);


	//cout << count << endl << endl;
	push(data, 7);
	push(data, 1);

	cout << "||Your queue: ||" << endl;
	outQueue(data);
	cout << endl;

	sortQueue(data);

	cout << "||Sorted queue: ||" << endl;
	outQueue(data);
	cout << endl;

	deleteList(data);

	system("pause");
}
//////////////////////////////////////////////////////////////////////////
void error(FILE *file)
{
	if (file == NULL)                                          //перевірка на можливість відкриття файлу
	{
		puts("There is a problem with file's opening.\nPlease, restart the program and try again...");
		system("pause");
		exit(0);                                               //вийти з програми 

	}
}
/////////////////////////////////////////////////////////////////////////
void readFromFile(Queue&queue, char* name)
{
	FILE *file = fopen(name, "r");
	error(file);
	while (!feof(file))
	{
		int a;
		fscanf(file, "%d", &a);
		push(queue, a);
	}
	fclose(file);
}
/////////////////////////////////////////////////////////////////////////
void push(Queue&queue, int value)
{
	Element *element = new Element;
	element->n = value;
	element->next = NULL;

	if (queue.tail == NULL)
		queue.head = element;
	else
		queue.tail->next = element;

	queue.tail = element;
	queue.count++;
}
///////////////////////////////////////////////////////////////////////
int pop(Queue&queue)
{
	Element *current = queue.head;
	int value = current->n;
	queue.head = current->next;
	if (queue.head == NULL)
	{
		queue.tail = NULL;
	}
	queue.count--;
	delete current;
	return value;
}

/////////////////////////////////////////////////////////////////////
void outQueue(Queue &queue)
{
	int count = queue.count;
	while (count--)
	{
		int value = pop(queue);
		cout << "  " << value;
		push(queue, value);
	}
}
////////////////////////////////////////////////////////////////////
int minQueue(Queue &queue)
{
	int min = pop(queue);
	int count = queue.count;
	while (count--)
	{
		int value = pop(queue);
		if (value < min)
		{
			push(queue, min);
			min = value;
		}
		else push(queue, value);
	}
	return min;
}

////////////////////////////////////////////////////////////////////
void sortQueue(Queue &queue)
{
	Queue sort;
	while (queue.count) push(sort, minQueue(queue));
	queue = sort;
}
//////////////////////////////////////////////////////////////////
void deleteList(Queue&queue)
{
	while (queue.count)
	{
		pop(queue);
	}
}