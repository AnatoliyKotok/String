#include "Line.h"
#include<iostream>

using namespace std;
const char* String::getItem() const
{
	return Item;
}
String::String(String&& other)
{
	cout << "MOVE" << endl;
	Item = other.Item;
	size = other.size;
	other.Item = nullptr;
	other.size = 0;
}
void String::SetName(const char* item,size_t size)
{
	if (item == nullptr || strlen(item) == 0)
		return;
	if (this->Item != nullptr) {
		delete[]this->Item;
	}
	this->size = size;
	size_t  NewSize= size;
	if (size <= strlen(item)) {
		cout << "size incorect" << endl;
		return;
	}
	this->Item = new char[NewSize];
	strcpy_s(this->Item, NewSize, item);
}

void String::SetSize(const size_t size)
{
	this->size = size;
}


void String::print() const
{
	if (Item != nullptr) {
		cout << getItem() << endl;
	}

}

void String::assing(const String& other)
{
	if (Item != nullptr) {
		delete[]Item;
	}

	size = other.size;
	Item = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		Item[i] = other.Item[i];
	}
}


void String::operator=(const String& other)
{
	if (this != &other)
		assing(other);
}

void String::operator=( String&& other)
{
	if (this != &other) {
		if (Item != nullptr)
			delete[]Item;
		cout << "MOVE" << endl;
		Item = other.Item;
		size = other.size;
		other.Item = nullptr;
		other.size = 0;
	}
}

void String::input()
{
	const int newsize = 1000;
	char* tmp = new char[newsize];
	cin.getline(tmp, newsize);
	cin.ignore(cin.rdbuf()->in_avail());
	this->size = newsize;
	size_t  NewSize = newsize;
	if (size <= strlen(tmp)) {
		cout << "size incorect" << endl;
		return;
	}
	this->Item = new char[NewSize];
	strcpy_s(this->Item, NewSize, tmp);
}





bool String::operator==(const String& other) const
{
	return this->Item==other.Item;
}

bool String::operator!=(const String& other) const
{
	return !(*this==other);
}

int String::operator[](int index) const
{
	if (index < size) {
		return Item[index];
	}
	cout << "Error" << endl;
	exit(EXIT_FAILURE);
	return 0;
}

