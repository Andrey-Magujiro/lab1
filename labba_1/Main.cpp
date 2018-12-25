#include "Header.h"
#include "Source.h"
#include "Group.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	Group group;
	int decision = 0;

	string temp_name = " ";
	int temp_group = 0;
	int temp_arr[5] = { 0 };
	int temp_length = 0;
	Student temp;

	do
	{
		system("cls");
		cout
			<< "1 - Создать список и заполнить;" << endl
			<< "2 - Вывести список на экран;" << endl
			<< "3 - Добавить студента;" << endl
			<< "4 - Удалить студента;" << endl
			<< "5 - Поиск студентов, чей средний балл больше 4.0;" << endl
			<< "0 - Завершение работы." << endl << endl;
		cin >> decision;

		switch (decision)
		{

		case 1:
			try
			{
				system("cls");
				group.create(temp_length = set_length());
				for (int i = 0; i < temp_length; i++)
				{
					system("cls");
					cout << "Осталось - " << temp_length - i << endl;
					set_student(temp_name, temp_group, temp_arr);
					group.fill(temp_name, temp_group, temp_arr, i);
				}
			}
			catch (const char *error)
			{
				system("cls");
				cout << error;
				Sleep(970);
			}
			break;

		case 2:
			system("cls");
			cout << "ID" << "\t\t\t" << "Ф.И.О." << "\t\t\t" << "\tГруппа" << "\t\t\t" << "Успеваемость" << endl;
			group.sorting();
			for (int i = 0; i < temp_length; i++)
			{
				group.show(i);
			}
			system("pause");
			break;

		case 3:
			flush_stdin();
			temp_length++;
			set_student(temp_name, temp_group, temp_arr);
			temp.set(temp_name, temp_group, temp_arr);
			group.operator+=(temp);
			break;

		case 4:
			flush_stdin();
			temp_length--;
			group.operator-=(set_ID());
			break;

		case 5:
			flush_stdin();
			group.special_show();
			break;
		case 0:
			break;
		default:
			cout << "Неккоректное действие! Пожалуйста, повторите попытку!";
			Sleep(970);
			break;
		}
	} while (decision != 0);

	return 0;
}