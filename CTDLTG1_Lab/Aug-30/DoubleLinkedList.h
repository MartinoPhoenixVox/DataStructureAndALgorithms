#pragma once
#include <iostream>
using namespace std;

struct Node {
	int info;
	Node *next, *previous;
};
struct DoubleList {
	Node *first, *last;
	void init() {
		first = NULL;
		last = NULL;
	}
	void printList() { //in tu dau ds
		Node *p = first;
		while (p != NULL) {
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}
	Node *searchFirst(int x) {
		Node *p = first;
		while (p != NULL && p->info != x)
			p = p->next;
		return p;
	}
	Node *searchLast(int x) {
		Node *p = last;
		while (p != NULL && p->info != x)
			p = p->previous;
		return p;
	}
	void insertFirst(int x) {
		Node *p = new Node;
		p->info = x;
		p->next = first;
		p->previous = NULL;
		if (first != NULL)
			first->previous = p;
		else last = p;
		first = p;
	}
	void insertLast(int x) {
		Node *p = new Node;
		p->info = x;
		p->previous = last;
		p->next = NULL;
		if (last != NULL)
			last->next = p;
		else first = p;
		last = p;
	}
	void insertAfter(int x, int y) {
		Node *q = searchFirst(y);
		if (q == NULL) return;
		Node *p = new Node;
		p->info = x;
		p->next = q->next;
		p->previous = q;
		q->next = p;
		if (p->next != NULL)
			p->next->previous = p;
		else last = p;
	}
	void insertBefore(int x, int y) {
		Node *q = searchFirst(y);
		if (q == NULL) return;
		Node *p = new Node;
		p->info = x;
		p->next = q;
		p->previous = q->previous;
		q->previous = p;
		if (p->previous != NULL)
			p->previous->next = p;
		else first = p;
	}
	void deleteFirst() {
		if (first != NULL) {
			Node *p = first;
			first = first->next;
			delete p;
			if (first != NULL)
				first->previous = NULL;
			else last = NULL;
		}
	}
	void deleteLast() {
		Node *p = last;
		last = last->previous;
		delete p;
		if (last != NULL)
			last->next = NULL;
		else first = NULL;
	}
	void deleteFirstX(int x) { //xoa x dau tien
		Node *p = first;
		while (p != NULL && p->info != x)
			p = p->next;
		if (p == NULL) return;
		if (p == first) deleteFirst();
		else
			if (p == last) deleteLast();
			else {
				p->next->previous = p->previous;
				p->previous->next = p->next;
				delete p;
			}
	}
	void deleteLastX(int x) {
		Node* p = last;
		while (p != NULL && p->info != x)
			p = p->previous;
		if (p == NULL) return;
		if (p == last) deleteLast();
		else
			if (p == first) deleteFirst();
			else {
				p->next->previous = p->previous;
				p->previous->next = p->next;
				delete p;
			}
	}
	void deleteAllX(int x) { //xoa tat ca phan tu co gia tri x
		if (first == NULL) return;
		Node *p = first;
		while (true) {
			while (p != NULL && p->info != x)
				p = p->next;
			if (p != NULL) //tim thay x
			{
				Node *q = p; //q la node tam, se vi xoa sau khi cho p = p->next de tim tiep
				if (p == first) {
					first = first->next;
					if (first == NULL) last = NULL;
					else first->previous = NULL;
				}
				else
					if (p == last) {
						last = last->previous;
						if (last == NULL) first = NULL;
						else last->next = NULL;
					}
					else {
						p->previous->next = p->next;
						p->next->previous = p->previous;
					}
					p = p->next;
					delete q;
			}
			else break; //khong tim thay
		}
	}
};