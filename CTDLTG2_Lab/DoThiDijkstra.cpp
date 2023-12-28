//Do thi - Dijkstra
#include <stdio.h>
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
	ifstream myFile("C:\\Users\\Phoenix Vo\\Documents\\Year2\\Semester1\\DataStructureAndAlgorithms2\\mtts3.txt");
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

//Dijkstra
int minimunDist(int dist[], bool Tset[]) {
	int min = INT_MAX, index = 0;
	for (int i = 0; i < 6; i++)
		if (Tset[i] == false && dist[i] <= min) {
			min = dist[i];
			index = i;
		}//if
	return index;
}//minimunDist(int dist[], bool Tset[])

//Djikstra
void Dijkstra(int src) {
	int dist[MAX]; //integer array to calculate minimum distance for each node
	bool Tset[MAX]; //boolean array to mark visited / unvisited for each node

	//set the nodes with infinity distance
	//except for the initial node and mark
	//them unvisited
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
		Tset[i] = false;
	}//for

	dist[src] = 0; //source vertex distance is set to zero

	for (int i = 0; i < n; i++) {
		int m = minimunDist(dist, Tset); //vertex not yet included
		Tset[m] = true; //m with minimum distance included in Tset
		for (int i = 0; i < n; i++)
			//Updating the minimum distance for the particular node
			if (!Tset[i] && A[m][i] && dist[m] != INT_MAX
				&& dist[m] + A[m][i] < dist[i])
				dist[i] = dist[m] + A[m][i];
	}//for
	cout << "Vertex\t\tDistance from source\n";
	for (int i = 0; i < n; i++)
		cout << vertex[i] << "\t\t\t" << dist[i] << endl;
}//Dijkstra(int scr)

int main() {
	//int a[MAX];
	int choice, x, i;
	system("cls");
	cout << " ----- DO THI - DIJKSTRA -----\n"
		<< "1. Khoi tao MA TRAN KE rong\n"
		<< "2. Nhap MA TRAN KE tu file text\n"
		<< "3. Nhap MA TRAN KE bang tay\n"
		<< "4. Xuat MA TRAN KE\n"
		<< "5. Duong di ngan nhat DIJKSTRA\n"
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
			cout << "Hay nhap dinh: ";
			cin >> x;
			Dijkstra(x);
			break;
		default:
			break;
		}//switch
	} while (choice != 0);
	system("pause");
	return 0;
}