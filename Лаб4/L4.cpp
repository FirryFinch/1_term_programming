#include <iostream>
#include <iomanip>
#include "func_proto.h"
using namespace std;
int main()
{ 
	setlocale(LC_ALL, "Russian");
	double eps=pow(10,-6);
	for (int i=1; i<=2; i++)
	{
		cout << "Заданная точность: " << eps << endl;
		cout << "Заданное уравнение: x-cos(x)=0" << endl;
		f_newton (eps, 1);
		f_dividing (eps, 1);
		f_iter (eps, 1);
		eps/=100;
	}
	eps*=10000;
	cout << "Заданная точность: " << eps << endl;
	cout << "Заданное уравнение: x-10*cos(x)=0" << endl;
	f_newton (eps, 10);
	f_dividing (eps, 10);
	f_iter (eps, 10);
	system("pause");
	return 0;
}
void f_newton (double e, int m)
{
	double x=2;
	int k=0;
	while (abs (x-m*cos(x)) > e)
	{
		k++;
		x=x-((x-m*cos(x))/(1+m*sin(x)));
	}
	cout << "I. МЕТОД НЬЮТОНА" << endl;
	cout << "  Корень уравнения: " << setprecision (9) << x << endl;
	cout << "  Количество шагов: " << k << endl;
}
void f_dividing (double e,  int m)
{
	double a=0, b=2, x=0, fa=0, fx=0, k=0;
	do
	{
		k++;
		x=(a+b)/2;
		fa=a-m*cos(a);
		fx=x-m*cos(x);
		if (fa*fx>0)
		{
		a=x;
		}
		else
		{
		b=x;
		}
	}
	while (abs(fx)>=e);
	cout << "II. МЕТОД ПОЛОВИННОГО ДЕЛЕНИЯ" << endl;
	cout << "  Корень уравнения: " << setprecision (9) << x << endl;
	cout << "  Количество шагов: " << k << endl;
}
void f_iter (double e,  int m)
{
	double x=2, k=0;
	while ((abs(x-m*cos(x))>e) && (k<1000))
	{
		k++;
		x=x-(x-m*cos(x));
	}
	cout << "III. МЕТОД ПРОСТОЙ ИТЕРАЦИИ" << endl;
	cout << "  Корень уравнения: " << setprecision (9) << x << endl;
	cout << "  Количество шагов: " << k << endl << endl;
}