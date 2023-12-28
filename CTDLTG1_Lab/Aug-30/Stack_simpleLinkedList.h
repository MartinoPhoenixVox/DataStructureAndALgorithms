#pragma once
#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
struct StackLinked
{
	Node *sp; // dinh stack
	void init()
	{
		sp = NULL;
	} //khoi tao stack
	void push(int x)
	{
		Node *p = new Node;
		p->info = x;
		p->link = sp;
		sp = p;
	} //them
	void pop(int &x)
	{
		if (sp != NULL)
		{
			Node *p = sp;
			x = p->info;
			sp = p->link;
			delete p;
		}
	} //xoa
	bool isEmpty()
	{
		return (sp == NULL);
	}
};
//ngoai stack
void listAll(StackLinked st)
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
void changeBase(StackLinked st, int n, int base)
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