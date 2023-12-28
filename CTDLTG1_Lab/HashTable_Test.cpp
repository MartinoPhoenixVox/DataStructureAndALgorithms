#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
	HashTable ht;
	int x;
	ht.init();
	int a[] = { 0, 101, 2, 103, 204, 98, 199, 300, 401, 201 };
	for (int i = 0; i < 10; i++)
		ht.insertElement(a[i]);
	ht.printTable();
	cout << "Nhap x: ";
	cin >> x;
	Node* f = ht.search(x);
	if (f != NULL) {
		cout << x << " co trong bang\n";
		ht.deleteElement(x);
		cout << "Sau khi xoa " << x << ":\n";
		ht.printTable();
	}
	else cout << x << " khong co trong bang\n";
}