//TIM KIEM, DO THI, GIAI THUAT PRIM
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// khai bao ma tran bang mang 2 chieu
#define MAX 20
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

void InitGraph() {
	n = 0;
}// InitGraph()

void inputGraphFromText() {
	string line;
	ifstream myfile("C:\\Users\\Phoenix Vo\\Documents\\Year2\\Semester1\\DataStructureAndAlgorithms2\\mtts1.txt");
	if (myfile.is_open()) {
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}// for
	}// if
}// inputGraphFromText()

// Nhap ma tran ke cua do thi
void inputGraph() {
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}// for
}// inputGraph()

// Xuat ma tran ke cua do thi
void outputGraph() {
	cout << setw(6) << left;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}// for
}// outputGraph()

// khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap

// khai bao Tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // so phan tap T

int TonTai(int d, int D[], int nD) {
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}// TonTai(int d, int D[]. int nD)

void XoaViTriE(int i) {
	for (int j = i; j < nE; j++) {
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}// for
	nE--;
}// XoaViTriE(int i)

void XoaCanhE(int u, int v) {
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v) {
			XoaViTriE(i);
			break;
		}// if
}// XoaCanhE(int u, int v)

void prim(int s) // s la dinh bat dau
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1) {
		for (int v = 0; v < n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0) {
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}// if
		for (i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0) {
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}// if
		for (; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i]) {
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}// if
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}// while
}// prim(int s)

void output(bool VertexName) {
	int tong = 0;
	for (int i = 0; i < nT; i++) {
		if (VertexName)
			cout << endl << "(" << vertex[T1[i]]
				<< ", " << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << ", "
				<< T2[i] << ") = " << wT[i];
		tong += wT[i];
	}// for
	cout << "\n  Tong = " << tong << endl;
}// output(bool VertexName)

void taoE() {
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0) {
				E1[nE] = i;
				E2[nE] = j;

				wE[nE] = a[i][j];

				a[i][j] = 0;
				a[j][i] = 0;

				nE++;
			}// if
}// taoE()

void SapXepE() {
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j]) {
				swap(wE[i], wE[j]);
				swap(E1[i], E2[j]);
				swap(E2[i], E2[j]);
			}// if
}// SapXepE()

void kruskal() {
	for (int i = 0; i < nE; i++) {
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}// for
}// kruskal()

int main() {
	int choice, x, i;

	do {
		system("cls");
		cout << " ------------  TIM KIEM CAY KHUNG TOI TIEU, PRIM ------------\n";
		cout << "1. Khoi tao MA TRAN KE rong\n"
			<< "2. Nhap MA TRAN KE tu file text\n"
			<< "3. Nhap MA TRAN KE\n"
			<< "4. Xuat MA TRAN KE\n"
			<< "5. Tim CAY KHUNG TOI TIEU bang PRIM\n"
			<< "0. Thoat\n";

		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice) {
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file:\n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			outputGraph();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi tieu voi PRIM:\n";
			output(true);
			break;
		case 0:
			cout << "Goodbye .....!" << endl;
			break;
		}// switch

		system("pause");
	} while (choice != 0);

	return 0;
}// main()