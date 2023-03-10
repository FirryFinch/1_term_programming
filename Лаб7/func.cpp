#include <iostream>
#include <fstream>
using namespace std;
int how_many_words()
{
	ifstream fin;
	char unsigned tempchar;
	char tch;
	int sum=0;
	fin.open("key.txt", ios_base::binary);
	if (!fin)
	{
		cout << "Ошибка открытия файла ключей. Проверьте расположение файла в папке с проектом" << endl;		
		system("pause");
	}
	else 
	{
		cout << "Файл с ключами успешно открыт." << endl;
		while (!fin.eof())
		{
			tch=fin.get();
			tempchar=tch;
			if ((tempchar==' ') || (tempchar=='\n'))
			{
				sum++;
			}
		}
		fin.close();
	}
	return (sum+1);
}
void key_arr_creator(int* words, int* wordcounter)
{
	fstream fin;
	int i=0;
	char unsigned tempchar;
	for (i=0; i<(*wordcounter); i++)
	{
		words[i]=0;
	}
	i=0;
	fin.open("key.txt");
	fin.clear();
	fin.seekg(0);
	while (!fin.eof())
	{
		tempchar=fin.get();
		if ((tempchar==' ') || (tempchar=='\n'))
		{
			i++;
		}
		else
		{
			words[i]+=(tempchar);
		}
	}
	fin.close();
}
void encrypter(int* words, int* wordcounter, int* stats)
{
	ifstream fin;
	ofstream fout;
	int i=0;
	char unsigned tempchar, c;
	char tch;
	fin.open("text.txt", ios_base::binary);
	if (!fin)
	{ 
		cout << "Ошибка открытия файла текста." << endl;		
		system("pause");
	}
	else
	{
		cout << "Файл с текстом успешно открыт." << endl;
		fout.open("encrypted.txt", ios_base::binary);
		cout << "Запуск процесса шифрования файла." << endl;
		char unsigned charforstat;
		cout << "Введите символ для сбора статистики: ";
		cin >> charforstat;
		tch=fin.get();
		while (!fin.eof())
		{

			tempchar=tch;
			c=((words)[i]+tempchar)%256;
			if (tempchar==charforstat)
			{
				stats[c]++;
			}
			
			fout << c;
			i++;
			if (i==(*wordcounter))
			{
				i=0;
			}
			tch=fin.get();
		}
	}
	fin.close();
	fout.close();
	cout << "Процесс шифрования завершен." << endl;
}
void decrypter(int* words, int* wordcounter)
{
	ifstream fin;
	ofstream fout;
	char unsigned tempchar;
	char tch;
	int i=0;
	fin.open("encrypted.txt", ios_base::binary);
	fout.open("decrypted.txt", ios_base::binary);
	tch=fin.get();
	while (!fin.eof())
	{
		tempchar=tch;
		tempchar=(tempchar-(words)[i])%256;
		fout << tempchar;
		i++;
		if (i=(*wordcounter))
		{
			i=0;
		}
		tch=fin.get();
	}
	fin.close();
	fout.close();
	cout << "Расшифрованный файл создан." << endl;
}