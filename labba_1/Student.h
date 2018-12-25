#pragma once
#include "Header.h"

class Student
{
private:
	string name;
	int group;
	int progress[5];
public:
	Student();
	void set(string &name, int &group, int *arr);
	void get(int ID);
	int getgroup();
	double get_progress();
};