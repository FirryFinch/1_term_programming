#include <iostream>
#include <iomanip>
using namespace std;
int main()
{ 
setlocale(LC_ALL, "Russian");
int n=0;
double y=0;
char ans='y';
do
{
	cout << "Введите число n: ";
	cin >> n;
	y=2*n;
	y=1/y;
	for (int i=2*(n-1); i>1; i=i-2)
	{
		y+=i;
		y=1/y;
	}
	cout << "При n = " << n << " значение y = " << setprecision(15) << y << endl;
	cout << "Продолжить работу? Введите 'y' для продолжения: ";
	cin >> ans;
	cout << endl;
}
while (ans=='y');
system("pause");
return 0;
}