#pragma once
#include <iostream>
using namespace std;
#define MAX 50

struct mono {
	int index;
	double number;
};

struct poly {
	mono list[MAX];
	int n;
	void printMono(mono m, int pos) {
		if (m.number == 0) return;
		if (m.index == 0) cout << m.number;
		else {
			//in dau + -
			if (m.number < 0) {
				if (m.number != 1) cout << m.number;
				cout << "x";
			}
			else {
				if (pos > 0) //if it's positive number, not input "+"
					cout << "+";
				if (m.number != 1) cout << m.number;
				cout << "x";
			}
			if (m.index > 1) cout << "^" << m.index;
		}
	}
	mono sumMono(mono m1, mono m2) {
		m1.number += m2.number;
		return m1;
	}
	void permute(mono &m1, mono &m2) {
		//this function permutes to ascendingly arrange, base on index
		mono tmp;
		tmp.number = m1.number;
		tmp.index = m1.index;
		m1.number = m2.number;
		m1.index = m2.index;
		m2.number = tmp.number;
		m2.index = tmp.index;
	}
	void inputPoly() {
		double number;
		int index;
		cout << "Please input your polynomial:\n";
		n = 0;
		while (true && n < MAX) {
			cout << "Number, index (input number = 0 to finish): ";
			cin >> number >> index;
			if (number == 0) break;
			list[n].number = number;
			list[n].index = index;
			n++;
		}
	}
	void printPoly() {
		for (int i = 0; i < n; i++) {
			printMono(list[i], i); //argument i corresponds with position of monomial
		}
		cout << endl;
	}
	void arrangePoly() {
		//ascendingly based on index
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (list[i].index > list[i].index)
					permute(list[i], list[j]);
	}
	void deleteMono(int pos) {
		//base on position in polynomial, delete monomial
		for (int i = pos + 1; i <= n - 1; i++)
			list[i - 1] = list[i];
		n--;
	}
	void reducePoly() {
		//reduce ascending polynomial
		//"reduce": add up polynomials' number-values with the same index
		arrangePoly();
		int i = n - 1;
		while (i > 0) {
			int j = i - 1;
			while (list[j].index == list[i].index) {
				list[i] = sumMono(list[i], list[j]);
				deleteMono(j); //add up "j"'s number-values into "i" then delete j
				j--;
			}
			i--;
		}
	}
	void addMono(mono m) {

	}
};