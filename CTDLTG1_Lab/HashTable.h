#pragma once
#include <iostream>
#define M 101
using namespace std;

struct Node {
	int key;
	Node* next;
};
struct HashTable {
	Node* heads[M];
	void init() {
		for (int i = 0; i < M; i++)
			heads[i] = NULL;
	}
	Node* insertElement(int k) {
		Node* t = heads[k % M];
		Node* x = new Node;
		x->key = k;
		if (t == NULL) //ds rong
		{
			x->next = t;
			heads[k % M] = x;
		}
		else
			if (t->key >= k) //them x vo dau ds
			{
				x->next = t;
				heads[k % M] = x;
			}
		else { //tim vi tri thich hop
			Node* p = t->next;
			while (p != NULL && p->key < k) {
				t = t->next;
				p = t->next;
			}
			t->next = x;
			x->next = p;
		}
		return x;
	}
	Node* search(int k) {
		Node* t = heads[k % M];
		if (t == NULL) return t;
		while (t->key < k && t->next != NULL)
			t = t->next;
		if (t->key == k) return t;
		return NULL;
	}
	void printTable() {
		for (int i = 0; i < M; i++) {
			Node* t = heads[i];
			if (heads[i] != NULL)
			{
				cout << "T[" << i << "]: ";
				while (true) {
					if (t != NULL)
					{
						cout << t->key << "-->";
						t = t->next;
					}
					else {
						cout << "NULL\n";
						break;
					}
				}
			}
		}
	}
	int deleteElement(int k) {
		Node* t = heads[k % M];
		if (t == NULL) //ds rong
			return 0;
		Node* p = NULL;
		while (t->key < k) {
			p = t;
			t = t->next;
		}
		if (t->key = k) //tim thay
		{
			if (p == NULL) //k o dau dslk
				heads[k % M] = t->next;
			else p->next = t->next;
			delete t;
			return 1;
		}
		return 0;
	}
};