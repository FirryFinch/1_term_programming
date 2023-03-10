#include <iostream>
using namespace std;
int int_random(int a, int b)
{
	return a+(b-a+1)*rand()/RAND_MAX;
}
void mas_out(int* m, int n)
{
	for (int i=0; i<n; i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
}
void mas_minmax_v(int* m, int* s, int* p, int n)
{
	int num=0, minmax=m[0], c=0;
	for (int i=0; i<n; i++)
	{
		num=i; 
		minmax=m[i];
		for (int j=(i+1); j<n; j++)
		{	
			if (m[j]<minmax)
			{
				num=j;
				minmax=m[j];
			}
			(*s)++;
		}
		if (num!=i)
		{
			c=m[i];
			m[i]=minmax;
			m[num]=c;
			(*p)++;
		}
	}
}
void mas_minmax_u(int* m, int* s, int* p, int n)
{
	int num=0, minmax=m[0], c=0;
	for (int i=0; i<n; i++)
	{
		num=i; 
		minmax=m[i];
		for (int j=(i+1); j<n; j++)
		{	
			if (m[j]>minmax)
			{
				num=j;
				minmax=m[j];
			}
			(*s)++;
		}
		if (num!=i)
		{
			c=m[i];
			m[i]=minmax;
			m[num]=c;
			(*p)++;
		}
	}
}
void mas_bubble_v(int* m, int* s, int* p, int n)
{
	int c=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<(n-i-1); j++)
		{
			if (m[j]>m[j+1])
			{
				c=m[j];
				m[j]=m[j+1];
				m[j+1]=c;
				(*p)++;
			}
				(*s)++;
		}
	if ((*p)==0)
	{
		return;
	}
	}
}
void mas_bubble_u(int* m, int* s, int* p, int n)
{
	int c=0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<(n-i-1); j++)
		{
			if (m[j]<m[j+1])
			{
				c=m[j];
				m[j]=m[j+1];
				m[j+1]=c;
				(*p)++;
			}
				(*s)++;
		}
	if ((*p)==0)
	{
		return;
	}
	}
}
void sp_out(int* s, int* p)
{
	cout << "Количество сравнений: " << *s << endl;
	cout << "Количество перестановок: " << *p << endl;
	cout << endl;
}