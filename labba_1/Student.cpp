#include "Student.h"

Student::Student()
{
	name = " ";
	group = 0;
	for (int i = 0; i < 5; i++) progress[i] = 0;
}

void Student::set(string & name, int & group, int * arr)
{
	this->name = name;
	this->group = group;
	for (int i = 0; i < 5; i++) progress[i] = arr[i];
}

void Student::get(int ID)
{
	cout << ID + 1 << "\t\t\t" << name << "\t\t\t" << group << "\t\t\t";
	for (int i = 0; i < 5; i++) cout << progress[i] << " ";
	cout << endl;
}

int Student::getgroup()
{
	return group;
}

double Student::get_progress()
{
	double z = 0;
	for (int i = 0; i < 5; i++)
	{
		z = z + progress[i];
	}
	return z / 5;
}