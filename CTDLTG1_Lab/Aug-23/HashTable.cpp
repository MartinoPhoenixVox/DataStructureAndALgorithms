//Source code
#include <iostream>
//#include "HashChaining.h"
#include "HashCoalesced.h"
using namespace std;

int main() {
	//HashChaining table;
	HashCoalesced table;
	table.init();
	//int a[10] = { 20, 35, 40, 32, 45, 25, 16, 37, 22, 55 };
	int a[] = { 20, 18, 30, 33, 28, 34, 8, 49, 7, 23 };
	//int a[] = { 199, 0, 2, 401, 300, 98, 201, 103, 204, 101 };
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) table.insert(a[i]);
	table.printTable();
	cout << "Delete 8\n";
	table.del(8);
	table.printTable();
	cout << "Delete 28\n";
	table.del(28);
	table.printTable();
	cout << "Delete 30\n";
	table.del(30);
	table.printTable();
	cout << "Delete 20\n";
	table.del(20);
	table.printTable();
	cout << "Delete 18\n";
	table.del(18);
	table.printTable();
	table.insert(8);
	table.insert(18);
	table.insert(20);
	table.printTable();
	return 0;
	/*cout << "Input value need to search: ";
	int x;
	cin >> x;
	Node* p = table.search(x);
	if (p != nullptr) cout << "Found " << p->key << "!\n";
	else cout << "Cannot be found!\n";
	cout << "Input value need to delete: ";
	cin >> x;
	table.del(x);
	table.printTable();
	return 0;*/
}