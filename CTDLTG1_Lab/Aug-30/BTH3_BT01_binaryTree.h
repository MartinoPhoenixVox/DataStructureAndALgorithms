#pragma once
#include <iostream>
#define MAX 50
using namespace std;

struct Node {
	int info;
	Node *left;
	Node *right;
};

struct binaryTree {
	Node *root;
	void init() {
		root = NULL;
	}
	Node *search(Node *p, int x) {
		while (p != NULL) {
			if (p->info == x) return p;
			else if (p->info > x) p = p->left;
			else p = p->right;
		}
		return NULL;
	} //without recursion
	Node *searchRecursion(Node *p, int x) {
		if (p != NULL) {
			if (p->info == x) return p;
			else if (p->info > x) return searchRecursion(p->left, x);
			else return searchRecursion(p->right, x);
		}
		return NULL;
	}
	void insertNode(Node *&p, int x) {
		do {
			if (p == NULL) {
				p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
			}
			else {
				if (p->info == x) return;
				else if (p->info > x) p = p->left;
				else p = p->right;
			}
		} while (p == NULL);
	} //without recursion
	void insertNodeRecursion(Node *&p, int x) {
		if (p == NULL) {
			p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
		}
		else {
			if (p->info == x) return;
			else if (p->info > x) return insertNodeRecursion(p->left, x);
			else return insertNodeRecursion(p->right, x);
		}
	}
	void insertNodes() {
		init();
		int x;
		do {
			cout << "Input x: ";
			cin >> x;
			if (x > 0) insertNode(root, x);
		} while (x != 0);
	}
	void insertTreeFromArray() {
		int n = 12;
		int a[MAX] = { 40, 20, 50, 10, 25, 43, 53, 6, 15, 30, 47, 60 };
		for (int i = 0; i < n; i++) insertNode(root, a[i]);
	}
	void traverse() { //process, print
		cout << "LNR: ";
		LNR(root);
		cout << endl;
		cout << "NLR: ";
		NLR(root);
		cout << endl;
		cout << "LRN: ";
		LRN(root);
		cout << endl;
	}
	void LNR(Node *p) {
		if (p != NULL) {
			LNR(p->left);
			cout << p->info << "\t";
			LNR(p->right);
		}
	}
	void NLR(Node* p) {
		if (p != NULL) {
			cout << p->info << "\t";
			NLR(p->left);
			NLR(p->right);
		}
	}
	void LRN(Node* p) {
		if (p != NULL) {
			LRN(p->left);
			LRN(p->right);
			cout << p->info << "\t";
		}
	}
	int Delete(Node*& T, int x) { //delete node with x value
		if (T == NULL) return 0;
		if (T->info > x) return Delete(T->left, x);
		if (T->info < x) return Delete(T->right, x);
		// T->info == x
		if (T->left == NULL) T = T->right;
		else
			if (T->right == NULL) T = T->left;
			else {
				Node* p = T->right;
				while (p->left != NULL) p = p->left;
				T->info = p->info;
				Delete(T->right, p->info);
			}
		return 1;
	}
};
