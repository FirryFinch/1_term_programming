#include <iostream>
#include <iomanip>
using namespace std;
int main2()
{ 
setlocale(LC_ALL, "Russian");
float a=0, s=1;
int i=0;
char ans='y';
do
{
	cout << "������� ����� a: ";
	cin >> a;
	s=1;
	if (a>=0)
	{
		for (i=2; i<=8; i+=2)
		{
		s=s*i*i;
		}
		s-=a;
	}
	else
	{
		for(i=3; i<=9; i+=3)
		{
		s=s*(i-2);
		}
	}
	cout << "������������: " << setprecision(7) << s << endl;
	cout << "���������� ������? ������� 'y' ��� �����������: ";
	cin >> ans;
	cout << endl;
}
while (ans=='y');
system("pause");
return 0;
}