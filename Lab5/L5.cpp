#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "func_proto.h"
using namespace std;
int main()
{ 
	setlocale(LC_ALL, "Russian");
	int const n=4;
	int mas1[n], mas2[n], amount_of_s=0, amount_of_p=0;
	srand((unsigned int)time(NULL));
	rand();
	for (int i=0; i<n; i++)
	{	
		mas1[i] = int_random(-100,100);
		mas2[i] = mas1[i];
	}
	cout << "�������� ������: ";
	mas_out (mas1, n);
	cout << endl;
	mas_minmax_v(mas1, &amount_of_s, &amount_of_p, n);
	cout << "������, ��������������� ������� ������ ������������ �������� �� �����������: ";
	mas_out (mas1, n);
	sp_out (&amount_of_s, &amount_of_p);
	amount_of_s=0;
	amount_of_p=0;
	mas_bubble_v(mas2, &amount_of_s, &amount_of_p, n);
	cout << "������, ��������������� ������� �������� �� �����������: ";
	mas_out (mas2, n);
	sp_out (&amount_of_s, &amount_of_p);
	amount_of_s=0;
	amount_of_p=0;
	mas_minmax_v(mas1, &amount_of_s, &amount_of_p, n);
	cout << "��������� ���������� ������� ������� ������ ������������ �������� �� �����������: " << endl;
	sp_out (&amount_of_s, &amount_of_p);
	amount_of_s=0;
	amount_of_p=0;
	mas_bubble_v(mas2, &amount_of_s, &amount_of_p, n);
	cout << "��������� ���������� ������� ������� �������� �� �����������: " << endl;
	sp_out (&amount_of_s, &amount_of_p);
	amount_of_s=0;
	amount_of_p=0;
	mas_minmax_u(mas1, &amount_of_s, &amount_of_p, n);
	cout << "������, ��������������� ������� ������ ������������� �������� �� ��������: ";
	mas_out (mas1, n);
	sp_out (&amount_of_s, &amount_of_p);
	amount_of_s=0;
	amount_of_p=0;
	mas_bubble_u(mas2, &amount_of_s, &amount_of_p, n);
	cout << "������, ��������������� ������� �������� �� ��������: ";
	mas_out (mas2, n);
	sp_out (&amount_of_s, &amount_of_p);
	int r=0;
	cout << "������� �������� ��������������� ������� ������� ��� ���������: ";
	cin >> r;
	cout << endl;
	for (int k=1; k<=3; k++)
	{
		amount_of_s=0;
		amount_of_p=0;
		int* t1=new int[r];
		int* t2=new int[r];
		for (int j=0; j<r; j++)
		{	
			t1[j]=int_random(-100,100);
			t2[j]=t1[j];
		}
		mas_minmax_v(t1, &amount_of_s, &amount_of_p, r);
		cout << "��� �������, ���������� �� " << r << " ��������� � ���������������� ������� ������ ������������ �������� �� �����������: " << endl;
		sp_out(&amount_of_s, &amount_of_p);
		mas_bubble_v(t2, &amount_of_s, &amount_of_p, r);
		cout << "��� �������, ���������� �� " << r << " ��������� � ���������������� ������� �������� �� �����������: " << endl;
		sp_out(&amount_of_s, &amount_of_p);
		delete[]t1;
		delete[]t2;
		r*=10;
	}
	system("pause");
	return 0;
}