#pragma once
#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* link;
};

struct SingleLinkedList {
	Node* first;
	void init() {
		first = NULL;
	}
	void processList() {
		Node* p = first;
		while (p != NULL) {
			cout << p->info << " ";
			p = p->link;
		}
	}
	Node* search(int x) {
		Node* p = first;
		while ((p != NULL) && (p->info != x)) p = p->link;
		return p;
	}
	void insertFirst(int x) {
		Node* p = new Node;
		p->info = x;
		p->link = first;
		first = p;
	}
	void insertLast(int x) {
		Node* p = new Node;
		p->info = x;
		p->link = NULL;
		if (first == NULL) first = p; //the last element isn't exist
		else {
			Node* q = first;
			while (q->link != NULL) q = q->link;
			q->link = p;
		}
	}
	int insertBefore(int x, int y) {
		Node* q = search(y);
		if (q == NULL) return 0;
		else
			if (q == first) {
				insertFirst(x);
				return 1;
			}
			else {
				Node* p = new Node;
				p->info = x;
				Node* t = first;
				while (t->link != q) t = t->link;
				p->link = q;
				t->link = p;
				return 1;
			}
	}
	int insertAfter(int x, int y) {
		Node* q = search(y);
		if (q == NULL) return 0;
		else {
			Node* p = new Node;
			p->info = x;
			p->link = q->link;
			q->link = p;
			return 1;
		}
	}
	int deleteFirst() {
		if (first != NULL) { //the list must not be empty
			Node* p = first;
			first = first->link;
			delete p;
			return 1;
		}
		return 0;
	}
	int deleteLast() {
		if (first != NULL) {
			Node* p = first, * q = NULL;
			if (p != NULL)
				while (p->link != NULL) {
					q = p;
					p = p->link;
				}
			if (p != first) q->link = NULL; // if p is first, q is not exist
			else first = NULL;
			delete p;
			return 1;
		}
		return 0;
	}
	int deleteBefore(int y) {
		if (first != NULL) {
			Node* p = first, * q = search(y), * t = NULL;
			if (p != NULL)
				while (p->link != q) {
					t = p;
					p = p->link;
				}
			if (p != first) t->link = q;
			else first = q;
			delete p;
			return 1;
		}
		return 0;
	}
	int deleteAfter(int y) {
		if (first != NULL) {
			Node* p = first, * q = search(y), * t = p->link;
			if (q == NULL) return 0;
			if (p != NULL)
				while (q->link != p) {
					p = p->link;
					t = p->link;
				}
			q->link = t;
			delete p;
			return 1;
		}
		return 0;
	}
	int findDelete(int x) {
		if (first != NULL) {
			Node* p = search(x), * q = first;
			if (p == NULL) return 0;
			if (q != NULL)
				while (q->link != p) q = q->link;
			if (p != first) q->link = p->link;
			else {
				first = p->link;
				q = p->link;
			}
			delete p;
			return 1;
		}
		return 0;
	}
};