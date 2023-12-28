#include <iostream>
#include "BTH1_BT05_QueueArray.h"
#include "BTH1_BT07_QueueLinked.h"
using namespace std;

int main() {
	QueueLinked q;
	QueueArray list;
	int opt = -1;
	int not1 = 0;
	int x, kq;
	do {
		if (not1 = 1) system("cls");
		cout << "Menu dao so:\n" << "1.Danh sach dac\n" << "2.Danh sach lien ket don\n" << "3.Thoat\n" << "Chon: ";
		cin >> opt;
		switch (opt) {
		case 1:
			list.init();
			cout << "1.Danh sach dac\n" << "Nhap so nguyen > 0: ";
			cin >> x;
			kq = reverseInt(x, list);
			cout << "Dao nguoc cua " << x << " la: " << kq << endl;
			break;
		case 2:
			q.init();
			cout << "2.Danh sach lien ket don\n" << "Nhap so nguyen > 0: ";
			cin >> x;
			kq = reserveInt(x, q);
			cout << "Dao nguoc cua " << x << " la: " << kq << endl;
			break;
		default:
			cout << "Thoat :>\n";
		}
		system("pause");
		not1 = 1;
	} while (opt >= 1 && opt <= 2);
	return 0;
}