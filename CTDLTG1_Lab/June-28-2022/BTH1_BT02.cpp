#include <iostream>
using namespace std;
#include "BTH1_BT02_Struct.h"

int main()
{
	int option;
	do {
		cout << "\nMenu\n"
			<< "1. Nhap danh sach\n"
			<< "2. Xuat danh sach\n"
			<< "3. Them 1 so nguyen vao dau danh sach\n"
			<< "4. Them 1 so nguyen vao cuoi danh sach\n"
			<< "5. Xoa phan tu dau danh sach\n"
			<< "6. Xoa phan tu cuoi danh sach\n"
	} while (option >= 1 && option <= 6)
}