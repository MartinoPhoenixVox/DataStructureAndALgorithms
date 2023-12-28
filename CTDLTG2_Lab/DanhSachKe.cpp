//Do thi - Danh sach ke
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MAX 20

//DSLK su dung cho STACK va QUEUE va DANH SACH KE
struct Node {
	int info;
	Node *link;
};

Node *first[MAX]; //DS cac DSK

int A[MAX][MAX];
char vertex[MAX];
int n;

//Khoi tao do thi
void initGraph() {
	n = 0;
}//initGraph()

void insertLast(Node *&first, Node *p) {
	if (first == NULL)
		first = p;
	else {
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}//else
}//insertGraph(Node *&first, Node *p)

void inputGraph() {
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++) 
		cin >> vertex[i];
	
	for (int i = 0; i <= n; i++) {
		if (i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << "): ";
		int u;
		string str;
		while (getline(cin, str)) {
			istringstream ss(str);
			while (ss >> u) {
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
				//cout << u << "-";
			}//while
			//cout << " i-" << i - 1 << endl;
			break;
		}//while
	}//for
	
}//inputGraph()

void inputGraphFromTxt() {
	string line;
	ifstream myFile("C:\\Users\\Phoenix Vo\\Downloads\\dsk.txt");
	if (myFile.is_open()) {
		myFile >> n;
		for (int i = 0; i < n; i++)
			myFile >> vertex[i];

		string str;
		int i = 0;
		while (getline(myFile, str)) {
			istringstream ss(str);
			int u;
			while (ss >> u) {
				//Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i - 1], p);
			}//while
			i++;
		}//while
	}//if
}//inputGraphFromTxt()

void output(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}//output(int a[], int n)

void outputGraph() {
	for (int i = 0; i < n; i++) {
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = first[i];
		while (p != NULL) {
			cout << p->info << " ";
			p = p->link;
		}//while
		cout << endl;
	}//for
}//outputGraph()

int main() {
	int choice;
	system("cls");
	cout << " ----- BIEU DIEN DO THI -----\n"
		<< "1. Khoi tao DANH SACH KE rong\n"
		<< "2. Nhap DANH SACH KE tu file text\n"
		<< "3. Nhap DANH SACH KE bang tay\n"
		<< "4. Xuat DANH SACH KE\n"
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