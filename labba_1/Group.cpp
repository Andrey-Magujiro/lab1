#include "Group.h"

Group::Group()
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

Group::~Group()
{
	while (length != 0)
	{
		tail = head->ptrNext;
		delete head;
		head = tail;
		length--;
	}
}

void Group::create(int length)
{
	if (length < 1) throw "Введена неккоректная длина списка!";
	for (int i = 0; i < length; i++)
	{
		push();
	}
	this->length = length;
}

void Group::push()
{
	if (head == nullptr) head = new Node();
	else
	{
		tail = head;
		while (tail->ptrNext != nullptr) tail = tail->ptrNext;
		tail->ptrNext = new Node();
	}
}

void Group::check_tail(int ID)
{
	if (ID == 0) tail = head;
	else tail = tail->ptrNext;
}

void Group::fill(string & name, int & group, int * arr, int ID)
{
	check_tail(ID);
	tail->data.set(name, group, arr);
}

void Group::show(int ID)
{
	check_tail(ID);
	tail->data.get(ID);
}

void Group::sorting()
{
	if (length != 0)
	{
		for (int i = 0; i < length - 1; i++)
		{
			Student buff;
			Node *temp = head;
			int counter = length;
			for (int j = 0; j < length - i; j++)
			{

				if (temp->data.getgroup() > temp->ptrNext->data.getgroup())
				{
					buff = temp->ptrNext->data;
					temp->ptrNext->data = temp->data;
					temp->data = buff;
				}
				counter--;
				if (counter > 1)
				{
					temp = temp->ptrNext;
				}
			}
		}
	}
}

void Group::swap(Student & object_1, Student & object_2)
{
	Student temp;

	temp = object_1;
	object_1 = object_2;
	object_2 = temp;
}

void Group::operator+=(Student & object)
{
	push();
	length++;
	tail = head;
	while (tail->ptrNext != nullptr) tail = tail->ptrNext;
	tail->data = object;
}

void Group::operator-=(int ID)
{
	if (ID > length || ID <= 0)
	{
		throw "Некорректная длина списка!";
	}
	Node *temp = head;
	Node *temp_prev = 0;
	Node *temp_next = 0;

	if (length != 0)
	{
		if (ID != 1 && ID != length)
		{
			delete_1(ID, temp, temp_prev, temp_next); // удаление элемента, находящегося в середине списка
		}

		else if (ID == 1)
		{
			delete_2(ID, temp); // удаление первого элемента списка
		}

		else if (ID == length && length != 1) // удаление последнего элемента
		{
			delete_3(ID, temp, temp_prev, tail);
		}
	}
}

Group::Node::Node(Student data, Node * ptrNext)
{
	this->data = data;
	this->ptrNext = ptrNext;
}

void Group::delete_1(int ID, Node *temp, Node *temp_prev, Node *temp_next)
{
	for (int i = 1; i <= length; i++)
	{

		if (i == ID - 1)
		{
			temp_prev = temp;
		}

		if (i == ID + 1)
		{
			temp_next = temp;
		}

		if (i != length)
		{
			temp = temp->ptrNext;
		}
	}
	length--;
	delete temp_prev->ptrNext;
	temp_prev->ptrNext = temp_next;
}

void Group::delete_2(int ID, Node *temp)
{
	if (length > 1)
	{
		temp = head->ptrNext;
		delete head;
		head = temp;
		length--;
	}
	else if (length == 1)
	{
		delete head;
		head = 0;
		length--;
	}
}

void Group::delete_3(int ID, Node *temp, Node *temp_prev, Node *tail)
{
	for (int i = 1; i < length; i++)
	{
		temp_prev = temp;
		temp = temp->ptrNext;
	}
	length--;
	delete tail;
	tail = temp_prev;
}

void Group::special_show()
{
	system("cls");
	if (length > 0)
	{
		int j = 0;
		tail = head;
		for (int i = 0; i < length; i++)
		{
			if (tail->data.get_progress() >= 4.0)
			{
				j++;
				tail->data.get(i);
			}
			tail = tail->ptrNext;
		}
		if (j == 0) cout << "Таких студентов нет." << endl;
		system("pause");
	}
}