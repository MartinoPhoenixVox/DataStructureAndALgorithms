#pragma once
#include <iostream>
using namespace std;
struct Node {
	int info;
	Node* link;
};
struct QueueLinked {
	Node *front, *rear;
	void init() {
		front = NULL;
		rear = NULL;
	}
	void Push(int x) {
		Node* p;
		p = new Node;
		p->info = x;
		p->link = NULL;
		if (rear == NULL)
			front = p;
		else rear->link = p;
		rear = p;
	}
	int Pop(int &x) {
		if (front != NULL) {
			Node *p = front;
			x = p->info;
			front = front->link;
			if (front == NULL) rear = NULL;
			delete p;
			return 1;
		}
		return 0;
	}
};
//ngoai struct
int reserveInt(int x, QueueLinked q) {
	if (x < 10) return x;
	while (x > 0) {
		q.Push(x % 10);
		x = x / 10;
	}
	int kq = 0;
	while (true) {
		q.Pop(x);
		kq = kq * 10 + x;
		if (q.front == NULL) break;
	}
	return kq;
}