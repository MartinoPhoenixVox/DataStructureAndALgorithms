#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#define SIZE 10 //fact: the size is much bigger than 10
struct Node {
	int key;
	int next;
};
struct HashCoalesced {
	Node T[SIZE];
	int r;
	int Hash(int k) {
		return k % SIZE;
	}
	void init() {
		r = SIZE - 1;
		for (int i = 0; i < SIZE; i++)
			T[i].key = T[i].next = -1;
	}
	int insert(int x) {
		int i, j;
		i = Hash(x);
		if (T[i].key != x && T[i].key != -1) {
			do {
				j = i;
				i = T[i].next;
			} while (T[i].key != x && i != -1);
			if (i == -1) {
				while (r != -1 && T[r].key != -1) r--;
				if (r != -1) T[j].next = r;
				i = r;
			}
		}
		if (i != -1 && T[i].key != x) T[i].key = x;
		return i;
	}
	int search(int x) {
		int i = Hash(x);
		while (x != T[i].key && i != -1) i = T[i].next;
		return i;
	}
	int del(int x) {
		int i = Hash(x);
		int j = i;
		while (x != T[i].key && i != -1) {
			j = i;
			i = T[i].next;
		}
		if (i == -1) return i;
		int arr[SIZE], k = 0;
		//found at i, delete the element at i and re-insert all elements behind i
		if (j != i) T[j].next = -1; //insert field "next" of the in front element = -1
		while (T[i].next != -1) {
			T[i].key = T[T[i].next].key; //sequently go to the elements behind the deleted element
			arr[k++] = T[i].key; //before delete the element, save values of the elements behind the deleted element into temporary array to re-insert them afterward
			T[i].key = -1; //delete all elements behind i (insert "key" and "next" to -1)
			j = i;
			i = T[i].next;
			T[j].next = -1;
		}
		T[i].key = T[i].next = -1; //also delete the last element of the elements behind the deleted element
		r = SIZE - 1; //update: move r to the last empty position
		while (T[r].key != -1) r--;
		//re-insert the element behind i saved in the temporary array
		for (int m = 0; m < k; m++) insert(arr[m]);
		return 1;
	}
	void printTable() {
		for (int i = 0; i < SIZE; i++) {
			if (T[i].key == -1) {
				cout << "[" << i << "]" << setw(3) << "|" << setw(3) << -1
					<< setw(3) << "|" << setw(3) << -1 << setw(3) << "|\n";
			}
			else {
				cout << "[" << i << "]" << setw(3) << "|" << setw(3) << T[i].key
					<< setw(3) << "|" << setw(3) << T[i].next << setw(3) << "|\n";
			}
		}
		cout << "------------------------------------------\n";
	}
};