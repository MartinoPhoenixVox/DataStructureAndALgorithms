//Do thi - Ma tran ke
//#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 20

int A[MAX][MAX];
char vertex[MAX];
int n;

//Khoi tao do thi
void initGraph() {
	n = 0;
}//initGraph()

void inputGraph() {
	cout << "Nhap so dinh cua do thi n = ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap du lieu dong thu [" << i + 1 << "]: ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}//for
}//inputGraph()

void inputGraphFromTxt() {
	string line;
	ifstream myFile("C:\\Users\\Phoenix Vo\\Documents\\Year2\\Semester1\\DataStructureAndAlgorithms2\\mtk.txt");
	if (myFile.is_open()) {
		myFile >> n;
		for (int i = 0; i < n; i++) 
			myFile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myFile >> A[i][j];
	}//if
}//inputGraphFromTxt()

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}//output(int a[], int n)

void outputGraph() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}//for
}//outputGraph()

int main() {
	int choice;
	system("cls");
	cout << " ----- BIEU DIEN DO THI -----\n"
		<< "1. Khoi tao MA TRAN KE rong\n"
		<< "2. Nhap MA TRAN KE tu file text\n"
		<< "3. Nhap MA TRAN KE bang tay\n"
		<< "4. Xuat MA TRAN KE\n"
		<< "0. Thoat\n";
	do {
		cout << "Chon so de thuc hien: ";
		cin >> choice;
		switch (choice) {
		case 1:
			initGraph();
			cout << "Da khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromTxt();
			cout << "Nhap MA TRAN KE tu file thanh cong!\n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		default:
			break;
		}//switch
	} while (choice != 0);
	system("pause");
	return 0;
}