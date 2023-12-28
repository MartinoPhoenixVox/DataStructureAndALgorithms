#include <iostream>
#include "DoubleLinkedList.h"
#include "CircleLinkedList.h"
using namespace std;

/*
Danh sach lien ket kep, vong
-Them vao dau, cuoi ds
-Them pt truoc sau pt cho truoc
-Xoa pt dau, cuoi ds
-Xoa pt co gia tri x tim thay dau tien/ cuoi cung
-Xoa tat ca cac phan tu co gia tri x
-Them pt vao ds da co thu tu
*/
int main() {
	DoubleList dl;
	int option1, option2, option3, x, y;
	do {
		system("cls");
		cout << "1. Danh sach lien ket kep\n"
			<< "2. Danh sach lien ket vong\n"
			<< "3. Thoat\nChon: ";
		cin >> option1;
		switch (option1) {
		case 1:
			dl.init();
			do {
				cout << "\n1. Them vao danh sach\n"
					<< "2. Xoa phan tu trong danh sach\n"
					<< "3. Thoat ra menu chinh\n"
					<< "Chon: ";
				cin >> option2;
				switch (option2) {
				case 1:
					cout << "\n1. Them phan tu vao dau danh sach\n"
						<< "2. Them phan tu vao cuoi danh sach\n"
						<< "3. Them phan tu vao truoc gia tri x\n"
						<< "4. Them phan tu vao sau gia tri x\n"
						<< "5. Menu danh sach lien ket kep\nChon: ";
					cin >> option3;
					switch (option3) {
					case 1:
						cout << "Nhap lan luot cac phan tu, nhap 0 de ket thuc:\n";
						while (true) {	
							cin >> x;
							if (x != 0) dl.insertFirst(x);
							else break;
						}
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 2:
						cout << "Nhap lan luot cac phan tu, nhap 0 de ket thuc:\n";
						while (true) {
							cin >> x;
							if (x != 0) dl.insertLast(x);
							else break;
						}
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 3:
						cout << "Nhap x: ";
						cin >> x;
						cout << x << " se o truoc y\ny = ";
						cin >> y;
						dl.insertBefore(x, y);
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 4:
						cout << "Nhap x: ";
						cin >> x;
						cout << x << " se o sau y\ny = ";
						cin >> y;
						dl.insertAfter(x, y);
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					default:
						cout << "Menu danh sach lien ket kep\n";
					}
					break;
				case 2:
					cout << "\n1. Xoa phan tu dau danh sach\n"
						<< "2. Xoa phan tu cuoi danh sach\n"
						<< "3. Xoa phan tu co gia tri x tim thay dau tien\n"
						<< "4. Xoa phan tu co gia tri x tim thay cuoi cung\n"
						<< "5. Xoa tat ca cac phan tu co gia tri x\n"
						<< "6. Menu danh sach lien ket kep\nChon: ";
					cin >> option3;
					switch (option3) {
					case 1:
						dl.deleteFirst();
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 2:
						dl.deleteLast();
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 3:
						cout << "Nhap x muon xoa: ";
						cin >> x;
						dl.deleteFirstX(x);
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 4:
						cout << "Nhap x muon xoa: ";
						cin >> x;
						dl.deleteLastX(x);
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					case 5:
						cout << "Nhap x muon xoa: ";
						cin >> x;
						dl.deleteAllX(x);
						cout << "\nKet qua:\n";
						dl.printList();
						break;
					default:
						cout << "Menu danh sach lien ket kep\n";
					}
					break;
				default:
					cout << "Thoat ra menu chinh\n";
				}
			} while (option2 >= 1 && option2 <= 2);
			break;
		case 2:
			break;
		default:
			cout << "Thoat chuong trinh\n";
		}
		system("pause");
	} while (option1 >= 1 && option1 <= 2);
	return 0;
}
