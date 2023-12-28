#include <iostream>
#include "Array_Int.h"
using namespace std;
#define minOpt 1
#define maxOpt 5

int main() {
	 Array arr;
	int opt1 = -1, opt2 = -1, x, loc;
	bool arrInput = false;
	do {
		system("cls");
		//The array's size and output is presented here:
		cout << "The array's size is: " << arr.n << endl;
		if (arrInput) {
			arr.output();
			cout << endl << endl;
		}
		//Menu is presented here:
		cout << "Menu:"
			<< "\n1/ Input the array."
			<< "\n2/ Search in the array."
			<< "\n3/ Insert an element."
			<< "\n4/ Delete an element."
			<< "\n5/ Find and delete an element."
			<< "\nInput others number to exit the program."
			<<"\nInput a number: ";
		cin >> opt1;
		if (opt1 < minOpt || opt1 > maxOpt) opt1 = -1; // change the option to -1 to exit the current menu
		if (opt1 == -1) break;
		switch (opt1) {
		case 1: //Input
			cout << "\nInput the array:"
				<< "\nInput the array's size: ";
			cin >> arr.n;
			cout << "Input the array here: ";
			arr.input();
			break;
		case 2: //Search
			if (arrInput) {
				cout << "\nInput a number to search: ";
				cin >> x;
				int loc = arr.search(x);
				if (loc == -1) cout << "\"" << x << "\" cannot be found in the array!";
				else cout << "The location of number \"" << x << "\":  " << loc;
			}
			else cout << "\nThe array must have at least 1 element!";
			break;
		case 3: //Insert
			cout << "\nInsert an element:"
				<< "\n1. Insert the first element"
				<< "\n2. Insert the last element"
				<< "\n3. Insert the element to a location"
				<< "\nInput a number: ";
			do {
				cin >> opt2;
				if (opt2 < 1 || opt2 > 3)
					cout << "Invalid number! Input again: ";
			} while (opt2 < 1 || opt2 > 3);
			cout << "Input the element to insert: ";
			cin >> x;
			switch (opt2) {
			case 1:
				if (arr.insertFirst(x) == 1) cout << "Insert succeeded!";
				else cout << "Insert failed!";
				break;
			case 2:
				if (arr.insertLast(x) == 1) cout << "Insert succeeded!";
				else cout << "Insert failed!";
				break;
			case 3:
				cout << "Input the location needed to insert: ";
				do {
					cin >> loc;
					if (loc > arr.n) cout << "The location must be smaller than or equal the array's size! Input again: ";
				} while (loc > arr.n);
				if (arr.insertInLocation(x, loc) == 1) cout << "Insert succeeded!";
				else cout << "Insert failed!";
				break;
			}
			break;
		case 4: //Delete
			cout << "\nDelete an element:"
				<< "\n1. Delete the first element"
				<< "\n2. Delete the last element"
				<< "\n3. Delete the element to a location"
				<< "\nInput a number: ";
			do {
				cin >> opt2;
				if (opt2 < 1 || opt2 > 3)
					cout << "Invalid number! Input again: ";
			} while (opt2 < 1 || opt2 > 3);
			switch (opt2) {
			case 1:
				if (arr.deleteFirst() == 1) cout << "Delete succeeded!";
				else cout << "Delete failed!";
				break;
			case 2:
				if (arr.deleteLast() == 1) cout << "Delete succeeded!";
				else cout << "Delete failed!";
				break;
			case 3:
				cout << "Input the location needed to delete: ";
				do {
					cin >> loc;
					if (loc > arr.n) cout << "The location must be smaller than or equal the array's size! Input again: ";
				} while (loc > arr.n);
				if (arr.deleteInLocation(loc) == 1) cout << "Delete succeeded!";
				else cout << "Delete failed!";
				break;
			}
			break;
		case 5: //Find and delete
			cout << "\nFind and delete:"
				<< "\n1. First element in the array"
				<< "\n2. All elements in the array"
				<< "\nInput a number: ";
			do {
				cin >> opt2;
				if (opt2 < 1 || opt2 > 2) cout << "Invalid number! Input again: ";
			} while (opt2 < 1 || opt2 > 2);
			cout << "Input the element to find and delete: ";
			cin >> x;
			if (opt2 == 1)
				if (arr.findDelFirst(x) == 1) cout << "Find and delete succeeded!";
				else cout << "Find and delete failed!";
			else cout << "Deleted " << arr.findDelAll(x) << " element(s)!";
			break;
		}
		cout << endl;
		system("pause");
		if (arr.n > 0) arrInput = true;
		else arrInput = false;
	} while (opt1 >= minOpt && opt1 <= maxOpt);
}

