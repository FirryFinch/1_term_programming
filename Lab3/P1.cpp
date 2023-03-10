#include <iostream>
using namespace std;
int main1()
{ 
setlocale(LC_ALL, "Russian");
int	n=0, m=0, s=0;
char ans='y';
do
{
	do
	{
		cout << "Ââåäèòå êîëè÷åñòâî íàòóðàëüíûõ ÷èñåë n: ";
		cin >> n;
		cout << "Ââåäèòå ÷èñëî m: ";
		cin >> m;
	}
	while((m>=n) || (m<=0) || (n<=0));
	s=0;
	for (int i=5; i<=n; i+=5)
	{
		if (i%m!=0)
		{
			s+=i;
		}
	}
	cout << "Ñóììà ÷èñåë, êîòîðûå äåëÿòñÿ íà 5 è íå äåëÿòñÿ íà " << m << ": " << s << endl;
	cout << "Ïðîäîëæèòü ðàáîòó? Ââåäèòå 'y' äëÿ ïðîäîëæåíèÿ: ";
	cin >> ans;
	cout << endl;
}
while (ans=='y');
system("pause");
return 0;
}
