#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main3()
{ 
setlocale(LC_ALL, "Russian");
double eps=pow(10,-6), s=0, s1=0, y=0, x=0, k=0, a=1;
int n=1;
cout << setw (12) << left << "x" << setw (12) << left << "y" << setw (12) << left << "s" << setw (12) << left << "N" << endl;
for (x=0; x<=1; x+=0.2)
{ 
	a=1;
	s1=0;
	s=0;
	n=1;
	cout << setw (12) << left << x;
	y=cos(x);
	cout << setw (12) << left << y;
		do
		{
			s1=s;
			s+=a;
			k=(-x*x)/(2*n*(2*n-1));
			a*=k;
			n++;
		}
		while (abs(s1-s)>eps);
	cout << setw (12) << left << s;
	cout << setw (12) << left << n << endl;
}
system("pause");
return 0;
}