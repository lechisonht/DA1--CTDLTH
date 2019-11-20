#include "vector.h"
#include<iostream>
using namespace std;
//ham nhap vector
void setvector(float u[], int n)
{
	cout << "\nNhap cac thanh phan cua vector: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "u[" << i + 1 << "]="; cin >> u[i];
	}
}
//ham xuat vector
void getvector(float u[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0) cout << "(";
		if (i == n - 1)cout << u[i] << ")";
		if (i < n - 1) if (u[i] != 0) cout << u[i] << ","; else cout << 0 << ",";
	}
}
void congvector(float u[], float v[], float s[], int n)//ham cong 2 vector: addvector(u,v,s,n): u + v = s,   n la so thanh phan 
{
	for (int i = 0; i < n; i++)
	{
		s[i] = u[i] + v[i];
		if (s[i] < 0.00001) { s[i] = 0; }
	}
}
void nhanvector(float u[], int n, float a)// nhan vector voi mot so a
{
	for (int i = 0; i < n; i++)
	{
		u[i] *= a;
	}
}
void swap(float u[], float v[], int n)
{
	for (int i = 0; i < n; i++)
	{
		float temp = u[i];
		u[i] = v[i];
		v[i] = temp;
	}
}
bool vtkhong(float u[], int n) {
	for (int i = 0; i < n; i++)
		if (u[i] != 0) { return false; }
	return true;
}
void vector1()
{
	cout << "---CONG VECTOR---\n";
	int n; cout << "Nhap so chieu: n="; cin >> n;
	float u[100]; float v[100]; float s[100];
	cout << "Nhap vector thu nhat: "; setvector(u, n);
	cout << "Nhap vector thu hai: "; setvector(v, n);
	congvector(u, v, s, n);
	cout << "Tong 2 vector tren la: "; getvector(s, n);
}
void vector2()
{
	cout << "---NHAN VECTOR---\n";
	int n; cout << "Nhap so chieu: n="; cin >> n;
	float u[100];
	setvector(u, n);
	int a;
	cout << "Nhap gia tri alpha: "; cin >> a;
	nhanvector(u, n, a);
	cout << "Vector sau khi nhan voi alpha la";
	getvector(u, n);
}
void VECTOR() {
	cout << "1.Cong vector\n2.Nhan vector voi 1 so alpha"; int tinhnang;
	cout << "\nTinh nang can su dung: "; cin >> tinhnang;
	switch (tinhnang)
	{
	case(1): {system("cls"); vector1(); break; }
	case(2): {system("cls"); vector2(); break; }
	default:
	{cout << "Khong co tinh nang"; break; }
	}
}