#pragma once
#include <iostream>
using namespace std;
#define MAX 100
struct Stack
{
	int a[MAX];
	int sp; //khai bao stack
	void init()
	{
		sp = -1;
	} //khoi tao stack
	bool isEmpty()
	{
		return (sp == -1);
	} //kiem tra rong
	bool isFull()
	{
		return (sp == MAX - 1);
	} //kiem tra day
	void push(int x)
	{
		if (sp < MAX - 1) //stack khong day
			a[++sp] = x;
	} //them
	void pop(int &x)
	{
		if (sp != -1) //stack khong rong
			x = a[sp--];
	} //xoa
};
//ngoai stack
void listAll(Stack st)
{
	int x;
	char y;
	while (!st.isEmpty())
	{
		st.pop(x);
		if (x < 10)
			cout << x;
		else {
			y = x + 55;
			cout << y;
		}
	}
	cout << endl;
}
void changeBase(Stack st, int n, int base)
{
	if (n == 0) cout << "0\n";
	else
	{
		while (n > 0)
		{
			int x = n % base;
			st.push(x);
			n = n / base;
		}
		listAll(st);
	}
} //chuyen n sang co so base
