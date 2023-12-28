#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#define M 101
struct Node {
	int key;
	Node* next;
};
struct HashChaining {
	Node* T[M];
	void init() {
		for (int i = 0; i < M; i++)
			T[i] = NULL;
	}
	int Hash(int n) {
		return n % M;
	}
	Node* insert(int k) {
		int pos = Hash(k);
		Node* t = T[pos];
		Node* x = new Node;
		x->key = k;
		if (t == NULL) {
			x->next = t;
			T[pos] = x;
		}
		else if (t->key >= k) { //insert x to head of the list
			x->next = t;
			T[pos] = x;
		}
		else {
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
		int pos = Hash(k);
		Node*t = T[pos];
		if (t == NULL) return t;
		while (t->key < k && t->next != NULL) t = t->next;
		if (t->key == k) return t;
		return NULL;
	}
	void del(int k) {
		int pos = Hash(k);
		Node* t = T[pos];
		if (t == NULL) return;
		Node* p = NULL;
		while (t != NULL && t->key < k) {
			p = t;
			t = t->next;
		}
		if (t == NULL) return;
		if (t->key == k) { //found
			if (p == NULL) //k at head of the linked list
				T[pos] = t->next;
			else p->next = t->next;
			delete t;
		}
	}
	void printTable() {
		for (int i = 0; i < M; i++) {
			if (T[i] == NULL) continue;
			Node* p = T[i];
			cout << "T[" << i << "]: " << setw(5);
			while (p != NULL) {
				cout << p->key << "-->";
				p = p->next;
			}
			cout << "NULL\n";
		}
	}
};