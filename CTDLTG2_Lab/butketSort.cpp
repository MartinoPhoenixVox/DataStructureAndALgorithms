#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXSIZE 10000 //so luong phan tu toi da cua mang
//khai bao mang
    int Array[MAXSIZE]; //mang goc, khong the chinh sua, co the nhap
    int n = 0; //so luong phan tu hien co

//khoi tao mang ngau nhien
void RandomArray(int a[], int &n) {
	do { //nhap so luong phan tu cua mang
		cout << "NHAP SO LUONG PHAN TU CUA MANG (<= 10000): ";
		cin >> n;
		if (n < 0 || n > MAXSIZE)
			cout << "SO LUONG PHAN TU CUA MANG LA SO NGUYEN > 0 VA <= 10000.\n";
	} while (n < 0 || n > MAXSIZE);

	srand(time(NULL)); //khoi tao seed ngau nhien

	for (int i = 0; i < n; i++) //khoi tao mang co n phan tu
		a[i] = rand() % 10000; //mang co gia tri ngau nhien tu 0 toi 9999

	cout << "\nMANG DUOC KHOI TAO THANH CONG!\n"; //thong bao ket thuc
}//RandomArray

//khoi tao mang bang cach nhap
void InputArray(int a[], int &n) {
	do { //nhap so luong phan tu cua mang
		cout << "NHAP SO LUONG PHAN TU CUA MANG (<= 10000): ";
		cin >> n;
		if (n < 0 || n > MAXSIZE)
			cout << "SO LUONG PHAN TU CUA MANG LA SO NGUYEN > 0 VA <= 10000.\n";
	} while (n < 0 || n > MAXSIZE);

	cout << "NHAP LAN LUOT GIA TRI CHO MANG:\n";
	
	for (int i = 0; i < n; i++) { //khoi tao mang co n phan tu
		do {
		    cout << "a[" << i << "] = ";
		    cin >> a[i];
		    if (a[i] < 0 || a[i] > MAXSIZE)
		        cout << "GIA TRI CUA MANG > 0 VA < 10000.\n";
		} while (a[i] < 0 || a[i] > MAXSIZE);
		cout << endl;
	}//for

	cout << "\nMANG DUOC KHOI TAO THANH CONG!\n"; //thong bao ket thuc
}//InputArray

//xuat mang
void OutputArray(int a[], int n) {
	if (n < 1) { //mang chua co so luong phan tu
		cout << "\nSO LUONG PHAN TU CUA MANG CHUA DUOC XAC DINH!\n";
		return;
	}//if

	cout << "MANG CO " << n << " GIA TRI:";
	for (int i = 0; i < n; i++) { //xuat mang
		if (i % 10 == 0) cout << endl;
		cout << "\t" << a[i];
	}//for

	cout << "\nXUAT MANG THANH CONG!\n"; //thong bao ket thuc
}//OutputArray

//hoan doi hai so nguyen
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;

	//cout << "\nHOAN DOI THANH CONG!\n";
}//Swap

//copy mang
void CopyArray(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}//CopyArray

//QuickSort theo slide
void QuickSort(int a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			Swap(a[i], a[j]);
			i++;
			j--;
		}//if
	}//while
	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}//QuickSort

//QuickSort khong theo slide
int Partition(int a[], int low, int high) {
	int pivot = a[high]; //pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && a[left] < pivot) left++;
		while (right >= left && a[right] > pivot) right--;
		if (left >= right) break;
		Swap(a[left], a[right]);
		left++;
		right--;
	}//while
	Swap(a[left], a[high]);
	return left;
}//Partition

//Ham thuc hien QuickSort2
void QuickSort2(int a[], int low, int high) {
	if (low < high) {
		//pi la chi so noi phan tu nay da dung dung vi tri
		//va la phan tu chia mang lam 2 mang con trai va phai
		int pi = Partition(a, low, high);
		//goi de quy sap xep 2 mang con trai va phai
		QuickSort2(a, low, pi - 1);
		QuickSort2(a, pi + 1, high);
	}//if
}//QuickSort2

//InsertionSort
void InsertionSort(int a[], int n) {
	int x, j;
	for (int i = 1; i < n; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}//while

		a[j + 1] = x;
	}//for

}//InsertionSort

//SelectionSort
void SelectionSort(int a[], int n) {
	int minPos;
	for (int i = 0; i < n - 1; i++) {
		minPos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[minPos]) minPos = j;
		Swap(a[minPos], a[i]);
	}//for

}//SelectionSort

//BubbleSort
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				Swap(a[j], a[j - 1]);
}//BubbleSort

//InterchangeSort
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				Swap(a[i], a[j]);
}//InterchangeSort

//MergeSort
void Merge(int a[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* Left = new int[n1]; //mang left tam
	int* Right = new int[n2]; //mang right tam
	/*moi mang doc tung phan tu*/
	for (i = 0; i < n1; i++) Left[i] = a[left + i];
	for (j = 0; j < n2; j++) Right[j] = a[mid + 1 + j];
	/*tron nhung mang tam vao mang a[left ... right]*/
	i = 0; //index khoi dau cua Left[]
	j = 0; //index khoi dau cua Right[]
	k = left; //index khoi dau cua mang duoc tron
	//chon phan tu nho hon giua 2 mang con va dua vao a[]
	while (i < n1 && j < n2) {
		if (Left[i] <= Right[j]) a[k] = Left[i++];
		else a[k] = Right[j++];
		k++;
	}
	/*neu Right[] ket thuc som hon, di chuyen nhung phan tu con lai trong Left[] vao a[]*/
	while (i < n1) {
		a[k] = Left[i];
		i++;
		k++;
	}
	/*neu Left[] ket thuc som hon, di chuyen nhung phan tu con lai trong Right[] vao a[]*/
	while (j < n2) {
		a[k] = Right[j];
		j++;
		k++;
	}
	delete[]Left;
	delete[]Right;
}//Merge

void MergeSort(int a[], int left, int right) { //ban dau: left = 0, right = n - 1
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}//MergeSort

//Heap Sort theo slide
void Shift(int a[], int i, int n) {
	int j = i * 2 + 1;
	if (j >= n) return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a, j, n);
	}//else

}//Shift

void HeapSort(int a[], int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		Shift(a, i, n);
		i--;
	}//while

	int r = n - 1;
	while (r > 0) {
		Swap(a[0], a[r]);
		r--;
		if (r > 0)
			Shift(a, 0, r);
	}//while

}//HeapSort

//Heap Sort khong theo slide
void Heapify(int a[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest]) largest = l;
	if (r < n && a[r] > a[largest]) largest = r;
	if (largest != i) {
		Swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}//if

}//Heapify

void HeapSort2(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) Heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--) {
		Swap(a[0], a[i]);
		Heapify(a, i, 0);
	}//for

}//HeapSort2

//Butket Sort theo slide
int getMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}//getMax

void butketSort(int a[], int n) {
	int max = getMax(a, n);
	int butket[MAXSIZE], i;
	for (int i = 0; i <= max; i++)
		butket[i] = 0;
	for (int i = 0; i < n; i++)
		butket[a[i]]++;
	for (int i = 0, j = 0; i <= max; i++)
		while (butket[i] > 0) {
			a[j++] = i;
			butket[i]--;
		}//while
}//butketSort

int main()
{
    
    int Temp[MAXSIZE]; //mang tam thoi, co the bi thay doi, khong the nhap
    int opt = -1; //gia tri lua chon hien tai, co the thay doi
    int temp = 0; //bien tam, dung cho cac thu tuc khong can luu du lieu lau dai 
    const int maxOpt = 15; //gia tri lua chon toi da co the co
	clock_t start;
	double duration;
    
    do {
        system("cls");
        //cout << endl; //tam thoi de the nay
        
        //nhap menu chuong trinh
		cout << "-----MENU-----\n"
			<< "0. Thoat chuong trinh\n"
			<< "1. Khoi tao danh sach ngau nhien\n"
			<< "2. Nhap danh sach bang tay\n"
			<< "3. Xuat danh sach\n"
			<< "4. ButketSort danh sach\n"
			<< "5. InsertionSort danh sach\n"
			<< "6. SelectionSort danh sach\n"
			<< "7. BubbleSort danh sach\n"
			<< "8. InterchangeSort danh sach\n"
			<< "9. MergeSort danh sach\n"
			<< "10. HeapSort danh sach\n"
			<< "11. HeapSort2 danh sach\n"
			<< "12. QuickSort danh sach\n"
			<< "13. QuickSort2 danh sach\n";
            
        //lua chon so thuc hien
        do {
            cout << "HAY CHON LUA SO THUC HIEN: ";
            cin >> opt;
            if (opt < 0 || opt > maxOpt)
                cout << "GIA TRI NHAP KHONG NAM TRONG GIOI HAN THUC HIEN!\n";
        } while (opt < 0 || opt > maxOpt);
        
        switch (opt) {//tung hanh dong cua so thuc hien
        case 1:
            cout << "1. Khoi tao danh sach ngau nhien\n";
            RandomArray(Array, n);
            break; //ket thuc hanh dong 1
        
        case 2:
            cout << "2. Nhap danh sach bang tay\n";
            InputArray(Array, n);
            break; //ket thuc hanh dong 2
            
        case 3:
            cout << "3. Xuat danh sach\n";
            OutputArray(Array, n);
			break; //ket thuc hanh dong 3

		case 4:
			cout << "4. ButketSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			butketSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN BUTKET SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 5:
			cout << "5. InsertionSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			InsertionSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN INSERTION SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 6:
			cout << "6. SelectionSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			SelectionSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN SELECTION SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 7:
			cout << "7. BubbleSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			BubbleSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN BUBBLE SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 8:
			cout << "8. InterchangeSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			InterchangeSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN INTERCHANGE SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 9:
			cout << "9. MergeSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			MergeSort(Temp, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN MERGE SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 10:
			cout << "10. HeapSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			HeapSort(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN HEAP SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 11:
			cout << "11. HeapSort2 danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			HeapSort2(Temp, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN HEAP SORT 2 LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 12:
			cout << "12. QuickSort danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			QuickSort(Temp, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN QUICK SORT LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 13:
			cout << "13. QuickSort2 danh sach\n";
			CopyArray(Array, Temp, n);
			start = clock();

			QuickSort2(Temp, 0, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "THOI GIAN QUICK SORT 2 LA " << duration * 1000000 << " MiliSeconds!\n";
			break;

		case 14:
			CopyArray(Array, Temp, n);
			butketSort(Temp, n);
			OutputArray(Temp, n);
			break;
            
        default:
            do {
                cout << "NHAN 1 DE THUC HIEN, NHAN 0 DE HUY: ";
                cin >> temp;
            } while (temp < 0 || temp > 1);
            if (temp == 0) opt = 1;
        }//switch
        
		system("pause");
    } while (opt >= 1 && opt <= maxOpt);
    
}//main
