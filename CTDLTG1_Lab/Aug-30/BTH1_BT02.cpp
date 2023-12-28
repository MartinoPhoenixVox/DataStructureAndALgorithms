#include <iostream>
#include "SingleLinkedList_Int.h"
using namespace std;

int main() {
	SingleLinkedList list;
	list.init();
	list.insertFirst(5);
	list.insertFirst(3);
	list.insertFirst(2);
	list.insertFirst(4);
	list.insertFirst(1);
	list.processList();
	cout << endl;
	list.insertLast(15);
	list.insertLast(23);
	list.insertLast(52);
	list.insertLast(41);
	list.insertLast(12);
	list.processList();
	cout << endl;
	list.insertBefore(22, 1);
	list.processList();
	cout << endl;
	list.insertAfter(21, 12);
	list.processList();
	cout << endl;
	list.deleteFirst();
	list.processList();
	cout << endl;
	list.deleteLast();
	list.processList();
	cout << endl;
	list.deleteBefore(23);
	list.processList();
	cout << endl;
	list.deleteAfter(1);
	list.processList();
	cout << endl;
}