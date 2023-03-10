#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef double (*TPF)(double);
double f1 (double x)	{return x;}
double f2 (double x)	{return sin(22*x);}
double f3 (double x)	{return x*x*x*x;}
double f4 (double x)	{return atan(x);}
TPF functions[]={f1, f2, f3, f4};
struct I_print
{
	char* name;
	double i_sum;
	double i_toch;
	int n;
};
void PrintTabl (I_print i_prn[], int k)
{
	const int m=4;
	int wn[m]={12, 18, 18, 10};
	char *title[m]={"Function", "Integral", "IntSum", "n "};
	int size[m];
	for (int i=0; i<m; i++)
	{
		size[i]=strlen(title[i]);
	}
	cout << char(218) << setfill(char(196));
	for (int j=0; j<(m-1); j++)
	{
		cout << setw(wn[j]) << char(194);
	}
	cout << setw(wn[m-1]) << char(191) << endl;
	cout << char(179);
	for (int j=0; j<m; j++)
	{
		cout << setw((wn[j]-size[j])/2) << setfill(' ') << ' '<< title[j] << setw((wn[j]-size[j])/2) << char(179);
	}
	cout << endl;
	for (int i=0; i<k; i++)
	{
		cout << char(195) << fixed;
		for(int j=0; j<(m-1); j++)
		cout << setfill(char(196)) << setw(wn[j]) << char(197);
		cout << setw(wn[m-1]) << char(180) << setfill(' ') << endl;
		cout << char(179) << setw((wn[0]-strlen(i_prn[i].name))/2) << ' ' << i_prn[i].name << setw((wn[0]-strlen(i_prn[i].name))/2) << char(179);
		cout << setw(wn[1]-1) << setprecision(10) << i_prn[i].i_toch << char(179) << setw(wn[2]-1) << i_prn[i].i_sum << setprecision(6) << char(179) << setw(wn[3]-1) << i_prn[i].n << char(179) << endl;	
	}
	cout << char(192) << setfill(char(196));
	for (int j=0; j<(m-1); j++)
	cout << setw(wn[j]) << char(193);
	cout << setw(wn[m-1]) << char(217) << setfill(' ') << endl;
}
double IntRect (TPF f, double a, double b, double eps, int* n)
{
	double I1=0, I2=0, x=0, dx=0;
	dx=b-a;
	x=a+dx/2;
	I1=f(x)*dx;
	do
	{
		if ((*n)!=1)
		{
			I1=I2;
		}
		(*n)*=2;
		I2=0;
		x=a+dx/(2*(*n));
		for (int i=0; i<(*n); i++)
		{
			I2+=f(x)*(dx/(*n));
			x=x+dx/(*n);
		}
	}
	while ((abs(I2-I1)/3)>eps);
	return I2;
}
double IntTrap (TPF f, double a, double b, double eps, int* n)
{
	double I1=0, I2=0, x=0, dx=0;
	dx=b-a;
	x=a;
	I1=((f(a)+f(b))/2)*dx;
	do
	{
		if ((*n)!=1)
		{
			I1=I2;
		}
		(*n)*=2;
		I2=0;
		x=a;
		for (int i=0; i<(*n); i++)
		{
			I2+=((f(x)+f(x+dx/(*n)))/2)*(dx/(*n));
			x=x+dx/(*n);
		}
	}
	while (abs(I2-I1)>eps);
	return I2;
}
int main()
{
	int n=1;
	double a=-1, b=3, eps=0.01;
	I_print StructTable[4];
	cout << "I.METHOD OF RECTANGLES" << endl;
	for (int j=0; j<5; j++)
	{
		cout << "Accuracy: " << eps << endl;
		StructTable[0].name="y=x ";
		StructTable[0].i_sum=IntRect(functions[0],a,b,eps,&n);
		StructTable[0].i_toch=(b*b-a*a)/2.0;
		StructTable[0].n=n;
		n=1;
		StructTable[1].name="y=sin(22x)";
		StructTable[1].i_sum=IntRect(functions[1],a,b,eps,&n);
		StructTable[1].i_toch=(cos(a*22.0)-cos(b*22.0))/22.0;
		StructTable[1].n=n;
		n=1;
		StructTable[2].name="y=x^4 ";
		StructTable[2].i_sum=IntRect(functions[2],a,b,eps,&n);
		StructTable[2].i_toch=(b*b*b*b*b - a*a*a*a*a)/5.0;
		StructTable[2].n=n;
		n=1;
		StructTable[3].name="y=arctg(x)";
		StructTable[3].i_sum=IntRect(functions[3],a,b,eps,&n);
		StructTable[3].i_toch=b*atan(b)-a*atan(a)-(log(b*b+1)-log(a*a+1))/2.0;
		StructTable[3].n=n;
		PrintTabl(StructTable, 4);
		eps/=10;
		cout << endl;
	}
	eps=0.01;
	n=1;
	cout << "II.METHOD OF TRAPEZES" << endl;
	for (int j=0; j<5; j++)
	{
		cout << "Accuracy: " << eps << endl;
		StructTable[0].name="y=x ";
		StructTable[0].i_sum=IntTrap(functions[0],a,b,eps,&n);
		StructTable[0].i_toch=(b*b-a*a)/2.0;
		StructTable[0].n=n;
		n=1;
		StructTable[1].name="y=sin(22x)";
		StructTable[1].i_sum=IntTrap(functions[1],a,b,eps,&n);
		StructTable[1].i_toch=(cos(a*22.0)-cos(b*22.0))/22.0;
		StructTable[1].n=n;
		n=1;
		StructTable[2].name="y=x^4 ";
		StructTable[2].i_sum=IntTrap(functions[2],a,b,eps,&n);
		StructTable[2].i_toch=(b*b*b*b*b - a*a*a*a*a)/5.0;
		StructTable[2].n=n;
		n=1;
		StructTable[3].name="y=arctg(x)";
		StructTable[3].i_sum=IntTrap(functions[3],a,b,eps,&n);
		StructTable[3].i_toch=b*atan(b)-a*atan(a)-(log(b*b+1)-log(a*a+1))/2.0;
		StructTable[3].n=n;
		PrintTabl(StructTable, 4);
		eps/=10;
		cout << endl;
	}
	system("pause");
	return 0;
}