#include <iostream>
//#include "Stack_List.h"
#include "Stack_simpleLinkedList.h"
using namespace std;

int main()
{
//	Stack stack;
	StackLinked stackLkd;
	int n;
	cout << "Nhap n (n > 0): ";
	do {
		cin >> n;
		if (n < 0) cout << "Dieu kien: n > 0\n Nhap lai: ";
	} while (n < 0);
	//cout << "Danh sach dac:\n";
	//stack.init();
	//cout << "He nhi phan: ";
	//changeBase(stack, n, 2);
	//stack.init();
	//cout << "He bat phan: ";
	//changeBase(stack, n, 8);
	//stack.init();
	//cout << "He thap luc phan: ";
	//changeBase(stack, n, 16);
	cout << "Danh sach lien ket don:\n";
	stackLkd.init();
	cout << "He nhi phan: ";
	changeBase(stackLkd, n, 2);
	stackLkd.init();
	cout << "He bat phan: ";
	changeBase(stackLkd, n, 8);
	stackLkd.init();
	cout << "He thap luc phan: ";
	changeBase(stackLkd, n, 16);
	system("pause");
	return 0;
}