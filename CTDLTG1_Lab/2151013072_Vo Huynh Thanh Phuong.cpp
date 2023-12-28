#include <iostream>
#include <conio.h>
#define MAXSIZE 100
using namespace std;

void currentSize(int& n)
{
	cout << "Mang co bao nhieu phan tu?\t";
	do {
		cin >> n;
		if (n <= 0 || n > MAXSIZE)
			cout << "Nhap sai. Nhap lai:\t";
	} while (n <= 0 || n > MAXSIZE);
}
void nhap(int arr[], int arrSize)
{
	cout << "Nhap mang:\n";
	for (int i = 0; i < arrSize; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
}
void xuat(const int arr[], int arrSize)
{
	cout << "Mang dang luu tru:";
	for (int i = 0; i < arrSize; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << arr[i] << ",\t";
	}
}
void soTim(int& x)
{
	cout << "Ban muon tim so nguyen nao?\t";
	do {
		cin >> x;
		if (!(cin >> x))
			cout << "Nhap sai. Nhap lai:\t";
	} while (!(cin >> x));
}
bool tim(const int arr[], int arrSize, int x)
{
	bool tim = false;
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == x)
		{
			tim == true;
			break;
		}
	return tim;
}
void daonguoc(int arr[], int arrSize)
{
	int daoSo = 0, tam, j = arrSize - 1;
	if (arrSize % 2 == 0)
		for (int i = 0; i <= (arrSize - 1) / 2; i++)
		{
			tam = arr[j];
			arr[j] = arr[i];
			arr[i] = tam;
			j--;
		}
	else
		for (int i = 0; i < (arrSize - 1) / 2; i++)
		{
			tam = arr[j];
			arr[j] = arr[i];
			arr[i] = tam;
			j--;
		}
}
void viTriXoa(int& p, int n)
{
	cout << "Ban muon xoa o vi tri nao?\t";
	do {
		cin >> p;
		if (p <= 0 || p > p)
			cout << "Nhap sai. Nhap lai:\t";
	} while (p <= 0 || p > n);
}
void xoa(int arr[], int& arrSize, int p)
{
	for (int i = p; i < arrSize; i++)
	{
		arr[i] = arr[i + 1];
	}
	arrSize--;
}
int viTrimin(int arr[], int arrSize)
{
	int min = INT_MAX, viTri = 0;
	for (int i = 0; i < arrSize; i++)
		if (arr[i] < min)
		{
			min = arr[i];
			viTri = i;
		}
	return viTri;
}
int AppCount(int arr[], int arrSize, int x)
{
	int demSo = 0;
	for (int i = 0; i < arrSize; i++)
		if (arr[i] == x)
			demSo++;
	return demSo;
}
void sapXepGiam(int arr[], int arrSize)
{
	int tam;
	for (int i = 0; i < arrSize - 1; i++)
		for (int j =  i + 1; j < arrSize; j++)
			if (arr[i] < arr[j])
			{
				tam = arr[i];
				arr[i] = arr[j];
				arr[j] = tam;
			}
}
void soXoa(int& x)
{
	cout << "Ban muon xoa so nguyen nao?\t";
	do {
		cin >> x;
		if (!(cin >> x))
			cout << "Nhap sai. Nhap lai:\t";
	} while (!(cin >> x));
}
void xoaTrungNhau(int arr[], int& arrSize, int& x)
{
	soXoa(x);
	for (int i = 0; i < arrSize - 1; i++)
		for (int j = i + 1; j < arrSize; j++)
			if (arr[j] == arr[i])
			{
				xoa(arr, arrSize, j);
				j--;
			}
}

int main()
{
	int n, p, x, k, l = 1;
	int a[MAXSIZE];
	do {
		system("cls");
		cout << "Chuc nang cua mang:\n1.Nhap mang\n2.Xuat mang\n3.Tim so trong mang\n4.Dao nguoc mang\n5.Xoa mot vi tri\n6.Vi tri nho nhat\n7.Dem lan xuat hien cua so\8.Sap xep giam dan\9.Xoa cac phan tu lap lai phan tu ban dau\n10.Thoat chuong trinh\nBan chon chuc nang nao?\t";
		cin >> k;
		if (!(k > 0 && k <= 9))
		{
			cout << "Ban chon thoat chuong trinh. Dang thoat...";
			break;
		}
		else
			switch (k)
			{
			case 1:
				currentSize(n);
				nhap(a, n);
				break;
			case 2:
				xuat(a, n);
				break;
			case 3:
				soTim(x);
				if (tim(a, n, x))
					cout << x << " co trong mang.\n";
				else cout << x << " khong co trong mang.\n";
				break;
			case 4:
				daonguoc(a, n);
				break;
			case 5:
				viTriXoa(p, n);
				xoa(a, n, p);
				break;
			case 6:
				viTrimin(a, n);
				break;
			case 7:
				soTim(x);
				AppCount(a, n, x);
				break;
			case 8:
				sapXepGiam(a, n);
				break;
			case 9:
				soXoa(x);
				xoaTrungNhau(a, n, x);
				break;
			default:
				cout << "Ban chon thoat chuong trinh. Dang thoat...";
			}
		_getch();
	} while (k > 0 && k <= 9);
}