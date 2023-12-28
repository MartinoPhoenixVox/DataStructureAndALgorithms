#include <iostream>
#include "BTH3_BT01_binaryTree.h"
using namespace std;
#define optionMax 3
void inputOption(int max, int &x) {
	do {
		cin >> x;
		if (x < 0 || x > max)
			cout << "Invalid input! Enter a number: ";
	} while (x < 0 || x > max);
}

int main() {
	binaryTree tree;
	tree.init();
	int option = 0, optionChild = 0;
	int x;
	do {
		system("cls");
		if (tree.root != NULL) {
			tree.LNR(tree.root);
			cout << endl;
		}
		cout << "BINARY TREE:"
			<< "\n0. Exit the program"
			<< "\n1. Insert a number"
			<< "\n2. Search a number"
			<< "\nInput your option here: ";
		inputOption(optionMax, option);
		switch (option)
		{
		case 1:
			cout << "Insert:"
				<< "\n0. Go back"
				<< "\n1. Without recursion"
				<< "\n2. With recurion"
				<< "\nInput your option here: ";
			inputOption(2, optionChild);
			cout << optionChild << endl;
			cin >> x;
			if (optionChild == 0) break;
			else if (optionChild == 1) tree.insertNode(tree.root, x);
			else tree.insertNodeRecursion(tree.root, x);
			break;
		case 2:
			cout << "Search:"
				<< "\n0. Go back"
				<< "\n1. Without recursion"
				<< "\n2. With recurion"
				<< "\nInput your option here: ";
			inputOption(2, optionChild);
			cout << "Input x: ";
			cin >> x;
			if (optionChild == 0) break;
			else if (optionChild == 1) {
				if (tree.search(tree.root, x) == NULL) cout << "\"" << x << "\" cannot be found!\n";
				else cout << "\"" << x << "\" was found!\n";
			}
			else {
				if (tree.searchRecursion(tree.root, x) == NULL) cout << "\"" << x << "\" cannot be found!\n";
				else cout << "\"" << x << "\" was found!\n";
			}
			break;
		default:
			cout << "You chose exit!\n";
		}
		system("pause");
	} while (option >= 1 && option <= optionMax);
}