#include "Source.h"

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}

void set_student(string & name, int & group, int * arr)
{
	cout << "Введите фамилию и инициалы студента: ";
	getline(cin, name);
	cout << "Введите номер группы: ";
	cin >> group;
	flush_stdin();
	cout << "Введите успеваемость (5 чисел): ";
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	flush_stdin();
}

int set_length()
{
	int length;
	cout << "Введите размер списка: ";
	cin >> length;
	flush_stdin();
	return length;
}

int set_ID()
{
	int ID;
	cout << "Введите ID человека: ";
	cin >> ID;
	return ID;
}