#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 100
struct Array {
	int arr[MAXSIZE];
	int n = 0;
	void input() {
		for (int i = 0; i < n; i++) cin >> arr[i];
	}
	void output() {
		for (int i = 0; i < n; i++) {
			if (i % 10 == 0) cout << endl;
			cout << arr[i] << "\t";
		}
	}
	int search(int x) {
		for (int i = 0; i < n; i++) {
			if (arr[i] == x) return i;
		}
		return -1;
	}
	int insertInLocation(int x, int loc) {
		if (loc <= n) {
			n++;
			if (loc == n - 1) { // the case that the array is null or the inserted element is in the last place
				arr[n - 1] = x;
				return 1;
			}
			else for (int i = n - 2; i >= loc; i--) { // the other cases
				arr[i + 1] = arr[i];
				if (i == loc) {
					arr[i] = x;
					return 1;
				}
			}
		}
		return 0;
	}
	int insertFirst(int x) {
		n++;
		if (n <= 1) {
			arr[n - 1] = x;
			return 1;
		}
		else for (int i = n - 2; i >= 0; i--) {
			arr[i + 1] = arr[i];
			if (i == 0) {
				arr[i] = x;
				return 1;
			}
		}
		return 0;
	}
	int insertLast(int x) {
		n++;
		arr[n - 1] = x;
		return 1;
	}
	int deleteFirst() {
		if (n > 0) {
			for (int i = 0; i <= n - 1; i++) {
				arr[i] = arr[i + 1];
				if (i == n - 1) {
					n--;
					return 1;
				}
			}
		}
		return 0;
	}
	int deleteLast() {
		if (n > 0) {
			n--;
			return 1;
		}
		return 0;
	}
	int deleteInLocation(int loc) {
		if (n > 0)
			for (int i = loc; i <= n - 1; i++) {
				arr[i] = arr[i + 1];
				if (i == n - 1) {
					n--;
					return 1;
				}
			}
		return 0;
	}
	int findDelFirst(int x) {
		if (deleteInLocation(search(x)) == 1) return 1;
		return 0;
	}
	int findDelAll(int x) {
		int counter = 0;
		for (int i = 0; i <= n - 1; i++) {
			if (arr[i] == x) {
				counter += deleteInLocation(i);
				if (arr[i] == x) i--;
			}
		}
		return counter;
	}
};