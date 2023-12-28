#pragma once
struct Node // khai bao cau truc danh sach
{
	int info;
	Node *link;
};
Node *first;
void Init()
{
	first = NULL;
}
void ProcessList() // xuat cac phan tu trong danh sach
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}
Node *Search(int x) // tim 1 phan tu trong danh sach
{
	Node *p = first;
	while ((p != NULL) && (p->info != x))
		p = p->link;
	return p;
}
void InsertFirst(int x) // them 1 phan tu vao dau sanh sach
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
void InsertLast(int x) // them 1 phan tu vao cuoi danh sach
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
bool DeleteFirst() // xoa phan tu dau danh sach
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return true;
	}
	return false;
}
bool DeleteLast() // xoa phan tu cuoi danh sach
{
	if (first != NULL)
	{
		Node *p = first, *q = NULL;
		if (p != NULL)
			while (p->link != NULL)
			{
				q = p;
				p = p->link;
			}
		if (p != first)
			q->link = NULL;
		else first = NULL;
		delete p;
		return true;
	}
	return false;
}
void DeleteAll(int x)
{
	Node *p = first, *q = NULL;
	bool search = true;
	do {
		while (p != NULL && p->info != x)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			Node *t = p;
			if (q == NULL)
				first = first->link;
			else
				q->link = p->link;
			p = p->link;
			delete t;
		}
		else search = false;
	} while (search);
}