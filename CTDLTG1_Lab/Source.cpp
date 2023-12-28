#include <iostream>
#define MAXSIZE 100
using namespace std;
void inputSize(int& n)
{
	do {
		cout << "Mang can nhap chua bao nhieu gia tri?\t";
		cin >> n;
		if (n < 0)
			cout << "Nhap thong tin sai. Yeu cau nhap 1 so nguyen duong nho hon " << MAXSIZE << endl;
	} while (n < 0);
}
void inputArrayDouble(int n, double aD[])
{
	cout << "Nhap mang so thuc:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "arrayDouble[" << i << "]\t=\t";
		cin >> aD[i];
		cout << endl;
	}
}
void outputArrayDouble(int n, double aD[])
{
	cout << "Mang so thuc gom cac gia tri:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << aD[i] << "\t";
	}
}
void inputArrayInt(int aI[], int n)
{
	cout << "Nhap mang so nguyen:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "arrayDouble[" << i << "]\t=\t";
		cin >> aI[i];
		cout << endl;
	}
}
void outputArrayInt(int aI[], int n)
{
	cout << "Mang so thuc gom cac gia tri:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << aI[i] << "\t";
	}
}
//01. Viet ham kiem tra mang so nguyen co ton tai gia tri 0 hay khong? Neu co thi tra ve 1, nguoc lai tra ve 0.
int checkArrayInt_0(int n, int aI[])
{
	for (int i = 0; i < n; i++)
	{
		if (aI[i] == 0)
			return 1;
	}
	return 0;
}
//02. Viet ham tim doan [a, b] sao cho doan nay chua tat ca cac gia tri cua mang 1 chieu cac so nguyen.
void findMaxMin(int n, int aI[], int& max, int& min)
{
	for (int i = 0; i < n; i++)
	{
		if (aI[i] > max)
			max = aI[i];
		else if (aI[i] < min)
			min = aI[i];
	}
}
void outputClosedInterval(int max, int min)
{
	cout << "Doan [" << max << ", " << min << "] chua tat ca ca gia tri cua mang 1 chieu cac so nguyen.\n";
}
//03. Viet ham liet ke cac gia tri am trong mang 1 chieu cac so nguyen.
void listNegativeNumber(int n, int aI[])
{
	cout << "Cac gia tri am trong mang 1 chieu cac so nguyen:";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		if (aI[i] < 0)
			cout << aI[i] << "\t";
		else continue;
	}
}
//04. Viet ham liet ke cac gia tri trong mang 1 chieu cac so thuc thuoc doan [x, y] cho truoc.
void inputClosedInterval(double& x, double& y)
{
	do {
		cout << "Nhap lan luot gia tri nho nhat va lon nhat cua doan can tim:\t";
		cin >> x >> y;
		if (x < INT_MIN || y < x || y > INT_MAX)
			cout << "Nhap thong tin sai. Nhap lai.\n";
	} while (x < INT_MIN || y < x || y > INT_MAX);
}
void listClosedInterval(int n, int aD[], double x, double y)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		if (aD[i] >= x && aD[i] <= y)
			cout << aD[i] << "\t";
	}
}
//05. Viet ham them 1 phan tu vao mang so nguyen.
void addSize(int& n)
{
	n++;
}
void whereToAddElement(int n, int& m)
{
	do {
		cout << "Ban muon them vao vi tri thu bao nhieu?\t";
		cin >> m;
		if (m >= n || m < 0)
			cout << "Nhap sai. Yeu cau nhap vi tri tu 0 den " << n - 1 << endl;
	} while (m >= n || m < 0);
}
void addElement(int n, int aI[], int m)
{
	for (int i = n - 2; i >= m; i--)
	{
		aI[i + 1] = aI[i];
		if (i == m)
			cin >> aI[m];
	}
}
//06. Viet ham xoa mot phan tu khoi mang so nguyen.
void whereToLoseElement(int n, int& m)
{
	do {
		cout << "Ban muon xoa vi tri thu bao nhieu?\t";
		cin >> m;
		if (m >= n || m < 0)
			cout << "Nhap sai. Yeu cau nhap vi tri tu 0 den " << n - 2 << endl;
	} while (m >= n || m < 0);
}
void loseElement(int n, int aI[], int m)
{
	for (int i = m; i < n; i++)
	{
		aI[i] = aI[i + 1];
	}
}
void eraseSize(int& n)
{
	n--;
}
//07. Viet ham sap xep cac phan tu cua mang so nguyen tang dan.
void swap(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
void arrangeElement1(int n, int aI[])
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (aI[j] > aI[i])
				swap(aI[j], aI[i]);
		}
	}
}
////08. Viet ham sap xep cac phan tu cua mang so nguyen sao cho cac phan tu chan tang dan, cac phan tu le thi giam dan.
//void arrangeElement2(int n, int aI[])
//{
//	for (int i = 0; )
//}
int main()
{
	int size, max = INT_MIN, min = INT_MAX, m;
	double x, y;
	double arrayDouble[MAXSIZE];
	int arrayInt[MAXSIZE];
	inputSize(size);
	int a;
	do {
		cout << "Muon nhap mang so nguyen (1) hay so thuc (2)?\t";
		cin >> a;
		if (a == 1)
		{
			inputArrayInt(arrayInt, size);
			outputArrayInt(arrayInt, size);

		}
	} while (a < 1 || a > 2);
}