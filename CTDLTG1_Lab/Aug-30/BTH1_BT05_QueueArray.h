#pragma once
#include <iostream>
#define MAXSIZE 100
using namespace std;
struct QueueArray {
	int a[MAXSIZE];
	int front, rear;
	void init() {
		front = -1;
		rear = -1;
	}
	//tinh tien
	int Push(int x) {
		if (rear - front == MAXSIZE - 1) //queue day
			return 0;
		else {
			if (front == -1) //queue rong
				front = 0;
			if (rear == MAXSIZE - 1) // queue bi tran
			{
				//tinh tien cac phan tu trong hang
				for (int i = front; i <= rear; i++)
					a[i - front] = a[i];
				//cap nhat rear
				rear = MAXSIZE - 1 - front;
				//cap nhat front
				front = 0;
			}
			a[++rear] = x; // them x vao hang doi
			return 1;
		}
	}
	int Pop(int &x) {
		if (front == -1) return 0;
		else {
			x = a[front++];
			if (front > rear) {
				front = -1;
				rear = -1;
			}
			return 1;
		}
	}
	//phuong phap vong
	int pushCircle(int x) {
		if ((rear - front) == (MAXSIZE - 1) || (rear - front == -1)) //hang doi bi day
			return 0;
		if (front == -1) //hang doi rong
			front = 0;
		if (rear == (MAXSIZE - 1)) //hang doi bi tran
			rear = -1; //hang doi tran, vong gia tri rear xuong -1
		a[++rear] = x;
		return 1;
	}
	int popCircle(int &x) {
		if (front != -1) {
			x = a[front];
			if (front == rear) {
				front = -1;
				rear = -1;
			}
			else {
				front++;
				if (front > (MAXSIZE - 1)) front = 0;
			}
			return 1;
		}
		return 0;
	}
};
//ngoai struct
int reverseInt(int x, QueueArray list) {
	if (x < 10) return x;
	while (x > 0) {
		list.Push(x % 10);
		//list.pushCircle(x % 10);
		x = x / 10;
	}
	int kq = 0;
	while (true) {
		list.Pop(x);
		//list.popCircle(x);
		kq = kq * 10 + x;
		if (list.front == -1) break;
	}
	return kq;
}
