#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
using namespace std;

const int maxI = 1000, minI = -1000;
const int minT = 10, maxT = 24, midT = 17;
const int money1_101 = 20000, money2_101 = 45000;
const int money1_102 = 5, money2_102 = 7, money3_102 = 10, money4_102 = 15, money5_102 = 20;

//Ham nhap 1 gia tri nguyen (co gioi han)
void nhap(int& n, int a, int b)
{
	do {
		cin >> n;
		if (n <= a || n >= b)
			cout << "THONG BAO: NHAP SAI. NHAP LAI:\t";
	} while (n <= a || n >= b);
}

//De bai (tach ham cho gon)
void deBai(int a)
{
	//De phan 1 (hoan thanh)
	if (a >= 101 && a <= 103)
	{
		if (a == 101)
			cout << "Du lieu cho san:\n"
			<< "[10, 17] h:\t20000 VND\n"
			<< "[17, 24) h:\t45000 VND\n"
			<< "[0, 10) h:\tkhong phuc vu\n"
			<< "Nhap gio vao va gio ra"
			<< ", va toi se cho ban biet so tien can tra!\n";

		else
			if (a == 102)
				cout << "Du lieu cho san:\n"
				<< "[1, 100] KW:\t$5\n"
				<< "[101, 150] KW:\t$7\n"
				<< "[151, 200] KW:\t$10\n"
				<< "[201, 300] KW:\t$15\n"
				<< "[300] KW tro len:\t$20\n"
				<< "Nhap so KW ban da dung trong thang"
				<< ", va toi se cho ban biet so tien dien cua thang ma ban phai tra!\n";

			else
				cout << "Nhap vao so nguyen n. "
				<< "Neu n > 5 thi tang n len 2 don vi va tra ve gia tri n, "
				<< "nguoc lai tra ve gia tri 0\n";
	}

	else
	//De phan 2 (hoan thanh)
		if (a >= 201 && a <= 210)
		{
			if (a >= 201 && a <= 205)
			{
				if (a == 201)
					cout << "Kiem tra mot so nguyen x la chan hay le?\n";

				else
					if (a == 202)
						cout << "Kiem tra mot so nguyen x co phai la so nguyen to khong? "
						<< "Biet rang so nguyen to la so chi co 2 uoc la 1 va chinh no\n"
						<< "Vi du: 2, 3, 5, 7, 11, 13, 17, 19, 23,... la cac so nguyen to\n";

					else
						if (a == 203)
							cout << "Kiem tra mot so nguyen x co phai la so chinh phuong khong? "
							<< "Biet rang so chinh phuong la binh phuong cua mot so nguyen khong am\n"
							<< "Vi du: 1 (1 = 1 * 1), 4 (4 = 2 * 2), 9 (9 = 3 * 3), 16 (16 = 4 * 4),... la cac so chinh phuong\n";

						else
							if (a == 204)
								cout << "Kiem tra 1 so nguyen x co la so hoan thien (con goi la so hoan chinh, so hoan hao) khong? "
								<< "Biet rang so hoan thien la so co tong cac uoc cua no (tru chinh no) bang chinh no\n"
								<< "Vi du: 6 co cac uoc 1 + 2 + 3 = 6 nen 6 la so hoan thien\n";

							else
								cout << "Xuat n so nguyen to dau tien voi n > 0 nhap tu ban phim\n"
								<< "Vi du: n = 5. 5 so nguyen to dau tien la: 2 3 5 7 11\n";
			}

			else
			{
				if (a == 206)
					cout << "Xuat n so chinh phuong dau tien voi n > 0 nhap tu ban phim\n"
					<< "Vi du: n = 3. 3 so chinh phuong dau tien la: 1 4 9\n";

				else
					if (a == 207)
						cout << "Dem so uoc cua so nguyen N\n";

					else
						if (a == 208)
							cout << "Nhap so N (0 < n < 1000, nhap sai thi yeu cau nhap lai). "
							<< "Xuat ra cach doc so N\n"
							<< "Vi du: N = 256 thi doc: hai tram nam muoi sau\n";

						else
							if (a == 209)
								cout << "Tim so n lon nhat sao cho 1 + 2 + 3 +...+ n < M voi M nhap tu ban phim\n";

							else
								cout << "Nhap vao N la so ngay (N > 0, neu nhap sai thi thong bao va yeu cau nhap lai). "
								<< "Cho biet N ngay do co bao nhieu tuan va ngay le\n"
								<< "Vi du: N = 37, co 5 tuan va 2 ngay le\n";
			}
		}

		else
	//De phan 3
			if (a >= 301 && a <= 330)
			{
				if (a >= 301 && a <= 310)
				{
					if (a >= 301 && a <= 305)
					{
						if (a == 301)
							cout << "Nhap mang 1 chieu\n"; // mang so thuc dung cho cau 9 va 16, con lai la mang so nguyen // cau 26 toi 30 dung cac mang khac nhau tuy de

						else
							if (a == 302)
								cout << "Xuat mang 1 chieu\n";

							else
								if (a == 303)
									cout << "Liet ke cac gia tri chan trong mang 1 chieu cac so nguyen\n";

								else
									if (a == 304)
										cout << "Liet ke cac vi tri ma gia tri tai do la gia tri am trong mang 1 chieu cac so nguyen\n";

									else
										cout << "Tim GIA TRI NHO NHUT trong mang 1 chieu cac so nguyen\n";
					}

					else
					{
						if (a == 306)
							cout << "Tim SO CHINH PHUONG DAU TIEN trong mang 1 chieu cac so nguyen\n";//Neu mang khong co so chinh phuong nao thi tra ve -1

						else
							if (a == 307)
								cout << "Tim doan [a,b] sao cho doan nay chua tat ca cac gia tri cua mang 1 chieu cac so nguyen\n";

							else
								if (a == 308)
									cout << "Liet ke cac gia tri am trong mang 1 chieu cac so nguyen\n";

								else
									if (a == 309)
										cout << "Liet ke cac gia tri trong mang 1 chieu cac so thuc thuoc doan [x,y] cho truoc\n";

									else
										cout << "Tinh tong cac gia tri le trong mang 1 chieu cac so nguyen\n";
					}
				}

				else
					if (a >= 311 && a <= 320)
					{
						if (a >= 311 && a <= 315)
						{
							if (a == 311)
								cout << "Tinh tong cac gia tri co chu so hang chuc la chu so 5 trong mang 1 chieu cac so nguyen\n";

							else
								if (a == 312)
									cout << "Tinh tong trung binh cong cac gia tri la so nguyen to trong mang 1 chieu cac so nguyen\n";

								else
									if (a == 313)
										cout << "Dem so luong cac gia tri chan trong mang 1 chieu cac so nguyen\n";

									else
										if (a == 314)
											cout << "Dem so luong cac gia tri duong chia het cho 3 trong mang 1 chieu cac so nguyen\n";

										else
											cout << "Kiem tra mang so nguyen co ton tai gia tri 0 hay khong?\n"; //Co tra ve 1, nguoc lai tra ve 0
						}

						else
						{
							if (a == 316)
								cout << "Kiem tra mang so thuc co doi xung khong?\n"; //Co tra ve 1, nguoc lai tra ve 0

							else
								if (a == 317)
									cout << "Sap xep cac phan tu cua mang so nguyen tang dan\n";

								else
									if (a == 318)
										cout << "Sap xep cac phan tu cua mang so nguyen sao cho cac phan tu chan tang dan, cac phan tu le giam dan\n";

									else
										if (a == 319)
											cout << "Them mot phan tu co gia tri x vao dau mang cac so nguyen\n";

										else
											cout << "Them mot phan tu co gia tri x vao vi tri k cua mang cac so nguyen\n";
						}
					}

					else
					{
						if (a >= 321 && a <= 325)
						{
							if (a == 321)
								cout << "Xoa mot phan tu o dau mang cac so nguyen\n";
							else

								if (a == 322)
									cout << "Xoa tat ca cac phan tu am cua mang cac so nguyen\n";

								else
									if (a == 323)
										cout << "Dua tat ca cac phan tu co gia tri 0 ve dau mang\n";

									else
										if (a == 324)
											cout << "Dua tat ca cac phan tu co dang 2^k ve dau mang\n";

										else
											cout << "Liet ke day con tang trong mang 1 chieu cac so nguyen\n";
						}

						else
						{
							if (a == 326)
								cout << "Cho 2 mang 1 chieu cac so nguyen a va b. Hay viet ham xem mang a co phai la mang con trong mang b khong?\n";

							else
								if (a == 327)
									cout << "Cho mang 1 chieu cac so nguyen a. "
									<< "Hay tao 2 mang b va c sao cho mang b chi chua gia tri duong va mang c chi chua gia tri am tu mang a\n";

								else
									if (a == 328)
										cout << "Cho 2 mang 1 chieu cac so nguyen b, c duoc sap xep tang dan. "
										<< "Hay tao mang a tu b va c sao cho a cung chua cac gia tri tang dan\n";

									else
										if (a == 329)
											cout << "Thuc hien:\n"
											<< "1) Nhap cac he so cua da thuc\n"
											<< "2) Xuat da thuc\n"
											<< "3) Tinh gia tri da thuc\n"
											<< "4) Tong 2 da thuc\n"
											<< "5) Tich 2 da thuc\n";

										else
											cout << "Thuc hien:\n"
											<< "1) Nhap nhiet do tung ngay trong 1 tuan\n"
											<< "2) Xuat nhiet do tung ngay trong 1 tuan\n"
											<< "3) Xuat nhiet do 1 ngay bat ky trong tuan theo yeu cau nguoi dung\n"
											<< "4) Tinh nhiet do trung binh trong tuan\n"
											<< "5) Tim nhiet do lon nhat\n"
											<< "6) Tim nhiet do nho nhat\n"
											<< "7) Tim so ngay co nhiet do tu 18 - 23 do C\n"
											<< "8) Tim ngay dau tien co nhiet do duoi 10 do C\n";
						}
					}

			}
}

//[2]
bool kiemChan(int x)
{
	if (x % 2 == 0)
		return true; //chan
	return false; //le
}

bool kiemSNT(int x)
{
	if (x < 2)
		return false;
	else
		for (int i = 2; i <= sqrt(x); i++)
			if (x % i == 0)
				return false;
	return true;
}

bool kiemSCP(int x)
{
	double a = sqrt(x);
	if (x < 1)
		return false;
	else
		if (a != static_cast<int>(a))
			return false;
	return true;
}

bool kiemSHH(int x)
{
	int tong = 0;
	if (x < 3)
		return false;
	else
		for (int i = 1; i < x; i++)
			if (x % i == 0)
				tong += i;
	if (tong != x)
		return false;
	return true;
}

void xuatSNT(int n)
{
	int i = 0, k = 2;
	cout << n << " so nguyen to dau tien:\n";
	while (i < n)
	{
		if (kiemSNT(k))
		{
			i++;
			cout << k << "\t";
		}
		k++;
	}
	cout << endl;
}

void xuatSCP(int n)
{
	int i = 0, k = 1;
	cout << n << " so chinh phuong dau tien:\n";
	while (i < n)
	{
		if (kiemSCP(k))
		{
			i++;
			cout << k << "\t";
		}
		k++;
	}
	cout << endl;
}

int demUoc(int x)
{
	int tong = 0;
	for (int i = 1; i <= x; i++)
		if (x % i == 0)
			tong++;
	return tong * 2;
}

void docN10(int a)
{
	switch (a)
	{
	case 1:
		cout << "mot";
		break;
	case 2:
		cout << "hai";
		break;
	case 3:
		cout << "ba";
		break;
	case 4:
		cout << "bon";
		break;
	case 5:
		cout << "nam";
		break;
	case 6:
		cout << "sau";
		break;
	case 7:
		cout << "bay";
		break;
	case 8:
		cout << "tam";
		break;
	case 9:
		cout << "chin";
		break;
	}
}

void docN(int x)
{
	int tram,chuc,donVi;
	donVi = x % 10;
	chuc = x / 10 % 10;
	tram = x / 100;
	if (tram != 0)
	{
		docN10(tram);
		cout << " tram ";
	}
	if (chuc == 0)
	{
		if (tram != 0 && donVi != 0)
			cout << "linh ";
	}
	else
		if (chuc == 1)
			cout << "muoi ";
		else
		{
			docN10(chuc);
			cout << " muoi ";
		}
	if (donVi != 0)
	{
		if (donVi == 5 && chuc != 0)
			cout << "lam\n";
		else
		{
			docN10(donVi);
			cout << endl;
		}
	}	
	else
		cout << endl;	
}

int timN(int m)
{
	int tong = 0, n;
	for (int i = 1; tong < m; i++)
	{
		tong += i;
		if (tong < m)
			n = i;
	}
	return n;
}

void xuatNgay(int n)
{
	int tuan = n / 7,ngay = n % 7;
	cout << "Co " << tuan << " tuan va " << ngay << " ngay le\n";
}

//[3]
void nhapMangNguyen(int a[], int n, string name)
{
	for (int i = 0; i < n; i++)
	{
		cout << name << "[" << i << "] = ";
		cin >> a[i];
	}
}

void nhapMangThuc(double a[], int n, string name)
{
	for (int i = 0; i < n; i++)
	{
		cout << name << "[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMangNguyen(const int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << a[i] << "\t";
	}
}

void xuatMangThuc(const double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << a[i] << "\t";
	}
}

int main()
{
	//khai bao, khoi tao bien
	int chon0;
	int chon1, gioVao_101, gioRa_101, tien_101, kwTruoc_102, kwSau_102, kwTinh_102, tien_102, n_103;
	int chon2, x_2, n_2;
	int chon3, chon329, chon329_1, heSo_329_1, heSo_329_2, chon330;
	int muc1_102 = 100 * money1_102, muc2_102 = muc1_102 + 50 * money2_102, muc3_102 = muc2_102 + 50 * money3_102, muc4_102 = muc2_102 + 100 * money4_102;
	bool check301 = false, check329_1 = false, check329_2 = false, check330 = false;

	//khai bao, khoi tao mang
	int arrInt[maxI] = { 0 }, a[maxI] = { 0 }, b[maxI] = { 0 }, c[maxI] = { 0 }, daThuc1[maxI] = { 0 }, daThuc2[maxI] = { 0 };
	double arrDouble[maxI] = { 0 }, nhietDo[maxI] = { 0 };

	//menu tong (chuong trinh don gian hoac bai tap voi ham)
	do {
		system("cls");
		cout << "MENU (MAN HINH CHINH):\n"
			<< "1. Chuong trinh don gian\n"
			<< "2. Bai tap voi ham\n"
			<< "3. Bai tap mang 1 chieu\n"
			<< "4. Thoat\n"
			<< "BAN CHON:\t";
		nhap(chon0, 0, 5);

		//cau lenh switch (0)
		switch (chon0)
		{

			//chuong trinh don gian (khong tach ham)
		case 1:
			do {
				system("cls");
				cout << "CHUONG TRINH DON GIAN\n"
					<< "1.\n"; 
				deBai(101);
				cout << "\n2.\n";
				deBai(102);
				cout << "\n3.\n";
				deBai(103);
				cout << "\n4. MENU (MAN HINH CHINH)\n" << "BAN CHON:\t";
				nhap(chon1, 0, 5);
				cout << endl;

				//cau lenh switch (1)
				switch (chon1)
				{
				case 1: //chi tinh theo so nguyen
					cout << "Nhap gio vao: ";
					nhap(gioVao_101, minT - 1, maxT);
					cout << "Nhap gio ra: ";
					nhap(gioRa_101, gioVao_101, maxT);
					if (gioVao_101 < midT && gioRa_101 > midT)
						tien_101 = (gioRa_101 - midT) * money2_101 + (midT - gioVao_101) * money1_101;
					else
						if (gioVao_101 >= midT)
							tien_101 = (gioRa_101 - gioVao_101) * money2_101;
						else
							tien_101 = (gioRa_101 - gioVao_101) * money1_101;
					cout << "So tien can tra: " << tien_101 << " VND\n" << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [101]

				case 2:
					cout << "Nhap so KW thang truoc: ";
					nhap(kwTruoc_102, -1, maxI);
					cout << "Nhap so KW thang nay: ";
					nhap(kwSau_102, kwTruoc_102 - 1, maxI);
					if (kwTruoc_102 == kwSau_102)
						tien_102 = 0;
					else
					{
						kwTinh_102 = kwSau_102 - kwTruoc_102;
						if (kwTinh_102 <= 100)
							tien_102 = kwTinh_102 * 5;
						else
							if (kwTinh_102 <= 150)
								tien_102 = (kwTinh_102 - 100) * 7 + muc1_102;
							else
								if (kwTinh_102 <= 200)
									tien_102 = (kwTinh_102 - 150) * 10 + muc2_102;
								else
									if (kwTinh_102 <= 300)
										tien_102 = (kwTinh_102 - 200) * 15 + muc3_102;
									else
										tien_102 = (kwTinh_102 - 300) * 20 + muc4_102;
						cout << "Tien dien thang nay ban can tra: $" << tien_102 << "\nHoan thanh chuong trinh!\n";
					}
					break; //hoan thanh [102]

				case 3:
					cout << "Nhap so nguyen n: ";
					nhap(n_103, minI, maxI);
					if (n_103 > 5)
						n_103 += 2;
					else 
						n_103 = 0;
					cout << "Gia tri tra ve: " << n_103 << "\nHoan thanh chuong trinh!\n";
					break; //hoan thanh [103]

				default:
					cout << "THONG BAO: CHUYEN TOI MAN HINH CHINH!\n";
				}
				_getch();
			} while (chon1 >= 1 && chon1 <= 3);
			break; //hoan thanh [1]

			//bai tap voi ham
		case 2:
			do {
				system("cls");
				cout << "BAI TAP VOI HAM\n";
				for (int i = 1; i <= 10; i++)
				{
					cout << i << ".\n";
					deBai(200 + i);
					cout << endl;
				}
				cout << "11. MENU (MAN HINH CHINH)\n" << "BAN CHON:\t";
				nhap(chon2, 0, 12);
				cout << endl;

				//cau lenh switch (2)
				switch (chon2)
				{
				case 1:
					cout << "Nhap so nguyen x: ";
					cin >> x_2;
					if (kiemChan(x_2))
						cout << x_2 << " la so chan\n";
					else
						cout << x_2 << " la so le\n";
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh[201]

				case 2:
					cout << "Nhap so nguyen x: ";
					cin >> x_2;
					if (kiemSNT(x_2))
						cout << x_2 << " la so nguyen to\n";
					else
						cout << x_2 << " khong la so nguyen to\n";
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [202]

				case 3:
					cout << "Nhap so nguyen x: ";
					cin >> x_2;
					if (kiemSCP(x_2))
						cout << x_2 << " la so chinh phuong\n";
					else
						cout << x_2 << " khong la so chinh phuong\n";
					cout << "Hoan thanh chuong trinh!";
					break; //hoan thanh [203]

				case 4:
					cout << "Nhap so nguyen x: ";
					cin >> x_2;
					if (kiemSHH(x_2))
						cout << x_2 << " la so hoan hao\n";
					else
						cout << x_2 << " khong la so hoan hao\n";
					cout << "Hoan thanh chuong trinh!";
					break; //hoan thanh [204]

				case 5:
					cout << "Nhap so nguyen duong n: ";
					nhap(n_2, 0, maxI);
					xuatSNT(n_2);
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [205]

				case 6:
					cout << "Nhap so nguyen duong n: ";
					nhap(n_2, 0, maxI);
					xuatSCP(n_2);
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [206]

				case 7:
					cout << "Nhap so nguyen N: ";
					cin >> x_2;
					cout << "Tong so uoc cua " << x_2 << ": " << demUoc(x_2) << "\nHoan thanh chuong trinh!\n";
					break; //hoan thanh [207]

				case 8:
					cout << "Nhap so N (0 < N < 1000): ";
					nhap(x_2, 0, maxI);
					docN(x_2);
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [208]

				case 9:
					cout << "Nhap M (1 < M < 1000): ";
					nhap(x_2, 1, maxI);
					n_2 = timN(x_2);
					cout << "1 + 2 + 3 + ... + n < M\nn = " << n_2 << endl;
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [209]

				case 10:
					cout << "Nhap so ngay N (0 < N < 1000): ";
					nhap(n_2, 0, maxI);
					xuatNgay(n_2);
					cout << "Hoan thanh chuong trinh!\n";
					break; //hoan thanh [210]

				default:
					cout << "THONG BAO: CHUYEN TOI MAN HINH CHINH!\n";
				}
				_getch();
			} while (chon2 >= 1 && chon2 <= 10);
			break; //hoan thanh[2]

			//bai tap mang 1 chieu
		case 3:
			do {
				system("cls");
				cout << "BAI TAP MANG 1 CHIEU\n";
				for (int i = 1; i <= 30; i++)
				{
					cout << i << ".\n";
					deBai(300 + i);
					cout << endl;
				}
				cout << "31. MENU (MAN HINH CHINH)\n" << "BAN CHON:\t";
				nhap(chon3, 0, 32);
				cout << endl;

				//cau lenh switch (3)
				switch (chon3)
				{
				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					break;

				case 5:
					break;

				case 6:
					break;

				case 7:
					break;

				case 8:
					break;

				case 9:
					break;

				case 10:
					break;

				case 11:
					break;

				case 12:
					break;

				case 13:
					break;

				case 14:
					break;

				case 15:
					break;

				case 16:
					break;

				case 17:
					break;

				case 18:
					break;

				case 19:
					break;

				case 20:
					break;

				case 21:
					break;

				case 22:
					break;

				case 23:
					break;

				case 24:
					break;

				case 25:
					break;

				case 26:
					break;

				case 27:
					break;

				case 28:
					break;

				case 29:
					do {
						system("cls");
						deBai(329);
						cout << "9) Thoat\nBAN CHON:\t";
						nhap(chon329, 0, 7);

						switch (chon329)
						{
						case 1:
							do {
								cout << "1'Nhap he so cua da thuc 1\n"
									<< "2'Nhap he so cua da thuc 2\n"
									<< "3'Thoat\nBAN CHON:\t";
								nhap(chon329_1, 0, 4);

								switch (chon329_1)
								{
								case 1:
									cout << "Da thuc co bao nhieu he so? ";
									nhap(heSo_329_1, 0, 10);
									nhapMangNguyen(daThuc1, heSo_329_1, "heSoDaThuc1");
									check329_1 = true;
									break;
								case 2:
									cout << "Da thuc co bao nhieu he so? ";
									nhap(heSo_329_2, 0, 10);
									nhapMangNguyen(daThuc2, heSo_329_2, "heSoDaThuc2");
									check329_2 = true;
									break;
								default:
									cout << "THONG BAO: TRO VE MENU \"DA THUC\"";
								}

							} while (chon329_1 >=1 && chon329_1 <=2);
							break;

						case 2:
							
							break;

						case 3:
							break;

						case 4:
							break;

						case 5:
							break;

						default:
							cout << "THONG BAO: TRO VE MENU \"BAI TAP MANG 1 CHIEU\" !";
						}

						_getch();
					} while (chon329 >= 1 && chon329 <= 5);
					break;

				case 30:
					do {
						system("cls");
						deBai(330);
						cout << "9) Thoat\nBAN CHON:\t";
						nhap(chon330, 0, 10);

						switch (chon330)
						{
						case 1:
							break;

						case 2:
							break;

						case 3:
							break;

						case 4:
							break;

						case 5:
							break;

						case 6:
							break;

						case 7:
							break;

						case 8:
							break;

						default:
							cout << "THONG BAO: TRO VE MENU \"BAI TAP MANG 1 CHIEU\" !";
						}

						_getch();
					} while (chon330 >= 1 && chon330 <= 8);
					break;

				default:
					cout << "THONG BAO: CHUYEN TOI MAN HINH CHINH!\n";
				}
				_getch();
			} while (chon3 >= 1 && chon3 <= 30);
			break;

			//thoat chuong trinh
		default:
			cout << "THONG BAO: THOAT CHUONG TRINH\n";
		}

		_getch();
	} while (chon0 >= 1 && chon0 <= 3);

	//tra ve gia tri
	return 0;
}