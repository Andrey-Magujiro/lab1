#pragma once
#include "Student.h"

class Group
{
private:
	class Node
	{
	public:
		Student data;
		Node *ptrNext;

		Node(Student data = Student(), Node *ptrNext = nullptr);
	};
	int length;
	Node *head;
	Node *tail;
public:
	Group();
	~Group();
	void create(int length);
	void push();
	void check_tail(int ID);
	void fill(string & name, int & group, int * arr, int ID);
	void show(int ID);
	void sorting();
	void swap(Student & object_1, Student & object_2);
	void operator+=(Student &object);
	void operator-=(int ID);
	void delete_1(int ID, Node *temp, Node *temp_prev, Node *temp_next);
	void delete_2(int ID, Node *temp);
	void delete_3(int ID, Node *temp, Node *temp_prev, Node *tail);
	void special_show();
};