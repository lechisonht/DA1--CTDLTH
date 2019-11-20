#include"vector.h"
#include"matran.h"
#include<iostream>
using namespace std;
void main()
{
	BATDAU:
	cout << "-------------------UNG DUNG GIAI TOAN-------------------\n" << "      1. DAI SO BOOL\n      2. VECTOR\n      3. MA TRAN\n";
	int ungdung;
	cout << "Ung dung su dung la: "; cin >> ungdung; 
	system("cls");
	switch (ungdung)
	{
	case(1): { break; }
	case(2): {VECTOR(); break;	}
	case(3): {MATRAN(); break; }
	default:
	{cout << "Khong co ung dung"; break; }
	}
	int i;
	cout << "\nNhap 1 de quay lai MENU va 0 de thoat. ";
	cin >> i;
	if (i == 1) { 
		system("cls");
		goto BATDAU; 
	}
}