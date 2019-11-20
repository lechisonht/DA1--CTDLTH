#include"matran.h"
#include"vector.h"
#include<iostream>
using namespace std;
//NHAP MA TRAN VUONG
void nhapmatran(float** s, int n)
{
	cout << "Nhap cac phan tu cua ma tran: \n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "S[" << i << "][" << j << "]="; cin >> s[i][j];
		}
}
//NHAP MA TRAN KHONG VUONG
void nhapmatran2(float** s, int n, int m)
{
	cout << "Nhap cac phan tu cua ma tran: \n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << "S[" << i << "][" << j << "]="; cin >> s[i][j];
		}
}
//XUAT MA TRAN VUONG
void xuatmatran(float** s, int n)
{
	for (int i = 0; i < n; i++)
	{
		getvector(s[i], n);
		cout << endl;
	}
}
//XUAT MA TRAN KHONG VUONG
void xuatmatran2(float** s, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		getvector(s[i], m);
		cout << endl;
	}
}
//Giai phong vung nho
void free2d(float** s, int n)
{
	for (int i = 0; i < n; i++)
		delete[]s[i];
	delete[]s;
}
//KHOI TAO MA TRAN DON VI
void khoitaoIn(float** ns, int n) {// HAM TAO MA TRAN DON VI In
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				ns[i][j] = 1;
			else
				ns[i][j] = 0;
		}
}
//COPY MA TRAN
void copy(float** a, float** b, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[i][j];
		}
}
void copy2(float** a, float** b, int n)
{
	for(int i=0;i<n;i++)
		for (int j = 0; j < n + 1; j++)
		{
			b[i][j] = a[i][j];
		}
}
//TINH DINH THUC
float dinhthuc(float** s, int n)
{
	//chuyen ma tran thanh ma tran tam giac
	for (int j = 0; j < n; j++)
		for (int i = j + 1; i < n; i++) {
			if (s[j][j] == 0) {				//Neu phan tu duong cheo bang 0 thi cong them mot dong o duoi sao cho phan tu duong cheo khac 0
				int k;
				for (k = j + 1; k < n; k++)
				{
					if (s[k][j] != 0) { congvector(s[j], s[k], s[j], n); break; }
				}
				if (k == n) return 0;//Khi ma k len den n thi ma tran chac chan co mot dong bang 0 nen DET=0
			}
			if (s[i][j] != 0) {				//Chuan hoa tung cot theo phan tu duong cheo, nghia la cac phan tu ben duoi bang 0
				if (s[i][j] != 0)
				{
					float a = -s[i][j] / s[j][j];
					nhanvector(s[j], n, a);
					congvector(s[i], s[j], s[i], n);
					nhanvector(s[j], n, 1 / a);
				}
			}
		}
	float t = 1;
	for (int i = 0; i < n; i++) //DET ma tran tam giac bang tich phan tu duong cheo
	{
		t *= s[i][i];
	}
	return t;
}
//NGHICH DAO MA TRAN
void ndmatran(float** s, float** ns, int n)
{
	for (int j = 0; j < n; j++)// chuyen thanh ma tran tam giac tren
		for (int i = j + 1; i < n; i++) {
			if (s[j][j] == 0) {				//Neu phan tu duong cheo bang 0 thi cong them mot dong o duoi sao cho phan tu duong cheo khac 0
				int k;
				for (k = j + 1; k < n; k++)
				{
					if (s[k][j] != 0) { congvector(s[j], s[k], s[j], n); congvector(ns[j], ns[k], ns[j], n); break; }
				}
			}
			if (s[i][j] != 0) {				//Chuan hoa tung cot theo phan tu duong cheo, nghia la cac phan tu ben duoi bang 0
				float a = -s[i][j] / s[j][j];
				nhanvector(s[j], n, a);
				nhanvector(ns[j], n, a);
				congvector(s[i], s[j], s[i], n);
				congvector(ns[i], ns[j], ns[i], n);
			}
		}
	for (int j = n - 1; j > -1; j--)// chuyen thanh ma tran tam giac duoi
		for (int i = j - 1; i > -1; i--) {
			if (s[i][j] != 0) {				//Chuan hoa tung cot theo phan tu duong cheo, nghia la cac phan tu ben duoi bang 0
				float a = -s[i][j] / s[j][j];
				nhanvector(s[j], n, a);
				nhanvector(ns[j], n, a);
				congvector(s[i], s[j], s[i], n);
				congvector(ns[i], ns[j], ns[i], n);
			}
		}
	for (int i = 0; i < n; i++)// DUA CAC PHAN TU DUONG CHEO VE 1
	{
		float a = 1 / s[i][i];
		nhanvector(s[i], n, a);
		nhanvector(ns[i], n, a);
	}
}
//TICH MA TRAN
void tichmt(float** x, float** y, float** z, int a, int b, int c)
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < c; j++)
		{
			z[i][j] = 0;
			for (int k = 0; k < b; k++)
			{
				z[i][j] += x[i][k] * y[k][j];
			}
		}
}
//DANG BAC THANG 
void dangbt(float** s, int a, int b)
{
	int d = 0;		//so cot da chuan hoa
	for (int i = 0; i < a; i++)
	{
		if (s[i][d] != 0)//phan tu tru
		{
			for (int j = i + 1; j < a; j++)//dua cac phan tu ben duoi ve 0
			{
				if (s[j][d] != 0)
				{
					float a = -s[j][d] / s[i][d];
					nhanvector(s[i], b, a);
					congvector(s[j], s[i], s[j], b);
					nhanvector(s[i], b, 1 / a);
				}
			}
		}
		else
		{
			int k;
			for (k = i + 1; k < a; k++)//doi dong de phan tu tru khac 0
				if (s[k][d] != 0) { swap(s[i], s[k], b); break; }
			if (k < a)//phan tu tru != 0
			{
				for (int j = i + 1; j < a; j++)//dua cac phan tu ben duoi ve 0
				{
					if (s[j][d] != 0)
					{
						float a = -s[j][d] / s[i][d];
						nhanvector(s[i], b, a);
						congvector(s[j], s[i], s[j], b);
						nhanvector(s[i], b, 1 / a);
					}
				}
			}
			else
			{
				i--;
			}
		}
		d++;
	}
}
int rankmt(float** s, int a, int b)
{
	int d = 0;
	for (int i = 0; i < a; i++)
	{
		if (vtkhong(s[i], b) == false)
			d++;
		else break;
	}
	return d;
}
// YEU CAU 1
void matran1() {
	cout << "---TINH DINH THUC---\n";
	//KHOI TAO MANG 2 CHIEU
	float** s = NULL;
	int n;
	cout << "Nhap so chieu: n="; cin >> n;
	if (n < 1) { cout << "Khong hop le."; return; }
	s = new float* [n];
	for (int i = 0; i < n; i++)
	{
		s[i] = new float[n];
	}
	nhapmatran(s, n);
	xuatmatran(s, n);
	float a = dinhthuc(s, n);
	cout << "DET=" << a;
	free2d(s, n);
}
// YEU CAU 2
void matran2() {
	cout << "---TIM MA TRAN NGHICH DAO---\n";
	//TAO MA TRAN VA KHAI BAO VUNG NHO
	float** s = NULL;
	float** t = NULL;
	int n;
	cout << "Nhap so chieu: n="; cin >> n;
	s = new float* [n];
	t = new float* [n];// MA TRAN PHU DE TINH "DET"
	for (int i = 0; i < n; i++)
	{
		s[i] = new float[n];
		t[i] = new float[n];
	}
	nhapmatran(s, n);
	xuatmatran(s, n);
	copy(s, t, n);
	int D = dinhthuc(t, n);
	if (D == 0) { cout << "DET=0 KHONG TON MA TRAN NGHICH DAO"; return; }
	else
	{
		cout << "DET=" << D << endl;
		float** ns = NULL;
		ns = new float* [n];
		for (int i = 0; i < n; i++)
		{
			ns[i] = new float[n];
		}
		khoitaoIn(ns, n);
		ndmatran(s, ns, n);
		cout << "MA TRAN NGICH DAO LA: \n";
		xuatmatran(ns, n);
		free2d(ns, n);
	}
	free2d(t, n);
	free2d(s, n);
}
// YEU CAU 3
void matran3() {
	cout << "---TICH HAI MA TRAN---\n";
	//Tao 2 ma tran va cap vung nho
	float** x = NULL;
	float** y = NULL;
	float** z = NULL;//Ma tran tich x.y=z
	int a, b, c;
	cout << "Nhap so Dong cua ma tran 1: "; cin >> a;
	cout << "Nhap so Cot cua ma tran 1: "; cin >> b;
	cout << "Nhap so Cot cua ma tran 2: "; cin >> c;
	x = new float* [a];
	y = new float* [b];
	z = new float* [a];
	for (int i = 0; i < a; i++)
		x[i] = new float[b];
	for (int i = 0; i < b; i++)
		y[i] = new float[c];
	for (int i = 0; i < a; i++)
		z[i] = new float[c];
	cout << "MA TRAN 1:\n";
	nhapmatran2(x, a, b);
	cout << "MA TRAN 2:\n";
	nhapmatran2(y, b, c);
	tichmt(x, y, z, a, b, c);
	cout << "Tich 2 ma tran tren la:\n";
	xuatmatran2(z, a, c);
	free2d(x, a);
	free2d(y, b);
}
//YEU CAU 4
void matran4()
{
	cout << "TIM HANG MA TRAN\n";
	//Tao con tro cap 2 va cap bo nho de luu ma tran
	float** s = NULL;
	int a, b;
	cout << "Nhap so Dong cua ma tran 1: "; cin >> a;
	cout << "Nhap so Cot cua ma tran 1: "; cin >> b;
	s = new float* [a];
	for (int i = 0; i < a; i++)
		s[i] = new float[b];
	nhapmatran2(s, a, b);
	xuatmatran2(s, a, b);
	dangbt(s, a, b);
	cout << endl;
	xuatmatran2(s, a, b); //kiem tra dang bac thang
	cout << "Rank=" << rankmt(s, a, b);
	free2d(s, a);
}
//YEU CAU 5
void matran5() {
	cout << "PHUONG TRINH TUYEN TINH\n";
	//Tao con tro cap 2 va cap bo nho de luu phuong trinh
	float** x, ** y, ** z, ** nghiem, ** t1, ** t2; x = y = z = nghiem = t1 = t2 = NULL;
	int n;//so an
	cout << "So an cua HPT: n="; cin >> n;
	//Cap phat bo nho
	x = new float* [n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new float[n + 1];
	}
	t1 = new float* [n];
	for (int i = 0; i < n; i++)
	{
		t1[i] = new float[n + 1];
	}
	y = new float* [n];
	for (int i = 0; i < n; i++)
	{
		y[i] = new float[n];
	}
	t2 = new float* [n];
	for (int i = 0; i < n; i++)
	{
		t2[i] = new float[n];
	}
	z = new float* [n];
	for (int i = 0; i < n; i++)
	{
		z[i] = new float[1];
	}
	nghiem = new float* [n];
	for (int i = 0; i < n; i++)
	{
		nghiem[i] = new float[1];
	}
	cout << "Nhap he: \n";
	nhapmatran2(x, n, n + 1);
	xuatmatran2(x, n, n + 1);
	for(int i=0;i<n;i++)//copy ve trai vao ma tran vuong cap n
		for (int j = 0; j < n; j++)
		{
			y[i][j] = x[i][j];
		}
	for (int i = 0; i < n; i++)//copy vao ma tran n dong 1 cot
	{
		z[i][0] = x[i][n];
	}
	copy2(x, t1, n);
	copy(y, t2, n);
	//luc nay t1 chua he phuong trinh t2 chua ma tran vuong(ve trai)
	dangbt(t1, n, n + 1);
	dangbt(t2, n, n);
	if (rankmt(t1, n, n + 1) > rankmt(t2, n, n))
	{
		cout << "Phuong trinh vo nghiem.";
		return;
	}
	if (rankmt(t2, n, n) < n) {
		cout << "Phuong trinh vo so nghiem.";
		return;
	}
	//luc nay r(x)=r(y)=n, det(y)!=0
	khoitaoIn(t2, n);//tan dung lai t2 de lam ma tran nghich dao cua y
	ndmatran(y, t2, n);
	tichmt(t2,z,nghiem,n,n,1);
	cout << "He phuong trinh co nghiem la:\n";
	xuatmatran2(nghiem, n, 1);
	free2d(x, n);
	free2d(y, n);
	free2d(z, n);
	free2d(t1, n);
	free2d(t2, n);
	free2d(nghiem, n);
}
void MATRAN() {
	cout << "-----MA TRAN-----\n" << "1.Tinh dinh thuc\n" << "2.Tim ma tran nghich dao\n" << "3.Tich hai ma tran\n" << "4.Tim hang ma tran\n" << "5.He phuong trinh tuyen tinh\n";
	int tinhnang; cout << "Nhap tinh nang su dung:";
	cin >> tinhnang;
	switch (tinhnang)
	{
	case(1): {system("cls"); matran1(); break; }
	case(2): {system("cls"); matran2(); break; }
	case(3): {system("cls"); matran3(); break; }
	case(4): {system("cls"); matran4(); break; }
	case(5): {system("cls"); matran5(); break; }
	default:
		break;
	}
}
