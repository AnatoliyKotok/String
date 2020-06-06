#include<iostream>
#include"Line.h"

using namespace std;

int main() {
	String item1("ivan",5);
	item1.print();
    String copy = item1;
    copy.print();
	String clone(copy);
	clone.print();
	String v2 = move(item1);
	cout << "Item 1 : ";
	item1.print();
	cout << endl;
	cout << "V2 : ";
	v2.print();
	cout << endl;
	String in;
	cout << "Enter somthing->";
	in.input();
	
}