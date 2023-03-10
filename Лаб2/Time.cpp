#include <iostream>
using namespace std;
int main()
{ 
setlocale(LC_ALL, "Russian");
int h,h1,m;
do
{
cout << "Ââåäèòå ÷àñû è ìèíóòû: ";
cin >> h;
cin >> m;
}
while((h<0) || (h>=24) || (m<0) || (m>=60));
h1 = h;
if (h==12 && m==0)
{
cout << "Ïîëäåíü" << endl;
}
else
{
	if ((h==0) && (m==0))
	{
	cout << "Ïîëíî÷ü" << endl;		
	}
	else
	{
		if (h>12)
		{
		h=h-12;
		}
		cout << h;
		cout << " ÷àñ";
			if (h==1)
			{
			cout << " ";
			}
			else
			{
				if (h>1 && h<5)
				{
				cout << "à ";
				}
				else
				{
				cout << "îâ ";
				}
			}
		if (m!=0)
		{
			cout << m;
			cout << " ìèíóò";
			if (((m==1) || (m%10==1)) && (m!=11))
				{
				cout << "à ";
				}
				else
				{
				if ((m/10!=1) && ((m%10==2) || (m%10==3) || (m%10==4)))
					{
					cout << "û ";
					}
					else
					{
					cout << " ";
					}
				}
		}
		if (h1>=5 && h1<12)
		{
		cout << "óòðà";
		}
		else
		{
			if (h1>=12 && h1<18)
			{
			cout << "äíÿ";
			}
			else
			{
				if (h1>=18 && h1<=23)
					{
					cout << "âå÷åðà";
					}
				else
				{
				cout << "íî÷è";
				}
			}
		}
		if (m==0)
		{
		cout << " ðîâíî";
		}
		cout << endl;
	}
}
system("pause");
return 0;
}
