//Do thi - Ma tran ke
//#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 20

int A[MAX][MAX];
char vertex[MAX];
int n;

//DSLK su dung cho STACK va QUEUE
struct Node {
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//STACK
void initStack() {
	sp = NULL;
}//initStack()

int isEmptyS() {
	if (sp == NULL)
		return 1;
	return 0;
}//isEmptyS()

void pushS(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}//pushS(int x)

int popS(int &x) {
	if (sp != NULL) {
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}//if
	return 0;
}//popS(int &x)
//end STACK

//QUEUE
void initQueue() {
	front = NULL;
	rear = NULL;
}//initQueue()

int isEmptyQ() {
	if (front == NULL)
		return 1;
	return 0;
}//isEmptyQ()

void pushQ(int x) {
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}//pushQ(int x)

int popQ(int &x) {
	if (front != NULL) {
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}//if
	return 0;
}//popQ(int &x)
//end QUEUE

//Khoi tao do thi
void initGraph() {
	n = 0;
}//initGraph()

//Nhap do thi bang tay
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

//Nhap do thi bang txt
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
	cout << endl;
}//output(int a[], int n)

//Xuat ma tran ke
void outputGraph() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}//for
}//outputGraph()

//Cau 4.3: Duyet do thi theo chieu rong BFS (dung QUEUE va DSLK don)
int C[100], bfs[100];
int nbfs = 0;
void initC() {
	for (int i = 0; i < n; i++) //n la so dinh cua do thi
		C[i] = 1;
}//initC()

void BFS(int v) { //v la dinh bat dau 
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL) {
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1) {
				pushQ(w);
				C[w] = 0;
			}//if
	}//while
}//BFS(int v)

//Cau 4.4: Duyet do thi theo chieu sau DFS (dung STACK va DSLK don)
int dfs[100];
int ndfs = 0;
void DFS(int s) {
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0) {
		if (v == n)
			popS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1) {
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}//if
	}//while
}//DFS(int s)

//Cau 4.5: dung BFS tim x trn do thi
void search_by_BFS(int x, int v) { //v la dinh bat dau
	int w, p;
	pushQ(v);
	C[v] = 0;
	while (front != NULL) {
		popQ(p);
		if (x == p) {
			cout << "Tim thay x = " << x << endl;
			return;
		}//if
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1) {
				pushQ(w);
				C[w] = 0;
			}//if
	}//while
}//search_by_BFS(int x, int v)

int main() {
	int a[MAX], b[MAX];
	int choice, x;
	int sp, sb_b, i;
	system("cls");
	cout << " ----- BIEU DIEN DO THI -----\n"
		<< "1. Khoi tao MA TRAN KE rong\n"
		<< "2. Nhap MA TRAN KE tu file text\n"
		<< "3. Nhap MA TRAN KE bang tay\n"
		<< "4. Xuat MA TRAN KE\n"
		<< "5. Duyet do thi theo chieu rong BFS - DSLK\n"
		<< "6. Duyet do thi theo chieu sau DFS - DSLK\n"
		<< "7. Tim dinh co gia tri x theo BFS\n"
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
		case 5:
			initQueue();
			initC();
			cout << "vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS:\n";
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:\n";
			output(dfs, n);
			break;
		case 7:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			search_by_BFS(x, 0);
			break;
		case 0:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}//switch
	} while (choice != 0);
	//system("pause");
	return 0;
}//main()