#include <fstream>
#include <iostream>
#include <Windows.h>
#include "structure.h"
#include "functions_proto.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int word_length=31;
	int i=0, j=0;
	char eng_word[word_length], rus_word[word_length];
	Dictionary d[100];
	ifstream fin;
	int word_amount=0;
	cout << "Убедитесь, что с в папке с проектом существует файл словаря с названием \"data.txt\"." << endl << "Пары слов в этом файле должны располагаться на отдельной строке." << endl << "Каждая строка должна иметь вид: \"\*английское слово\* \*его перевод на русский язык\*\"" << endl << endl;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка: Файл \"data.txt\" не найден!" << endl;
	} 
	else 
	{
		cout << "Файл \"data.txt\" успешно открыт." << endl << endl;
		while (!fin.eof())
		{
			fin >> eng_word >> rus_word;
			d[i].eng=new char[strlen(eng_word)+1];
			d[i].rus=new char[strlen(rus_word)+1];
			strcpy_s(d[i].eng, strlen(eng_word)+1, eng_word);
			strcpy_s(d[i].rus, strlen(rus_word)+1, rus_word);
			word_amount++;
			i++;
		}
	for (i=0; i<(word_amount+1); i++)
		{
			for (j=i+1; j<word_amount; j++) 
			{
				if (strcmp(d[i].eng, d[j].eng)>0)
				{
					swap(d[i].eng, d[j].eng);
					swap(d[i].rus, d[j].rus);
				}
			}
		}
		do
		{
			switch(menu()) 
			{
				case '1':
					add_word(d, &word_amount); 
					break;
				case '2':
					delete_word(d, &word_amount);
					break;
				case '3':
					eng_to_rus(d, &word_amount);
					break;
				case '4':
					rus_to_eng(d, &word_amount);
					break;
				case '5': 
					show_dict(d, &word_amount); 
					break;
				case '6': 
					dict_out(d, &word_amount);
					break;
				case '7': 
					cout << endl << "Выход" << endl << endl;
					return 0;
				default: 
					cout << "Ошибка: Ваш символ не соответствует пункту меню! Повторите попытку" << endl << endl; 
					break;
			}
		}
		while (1);
	}
	system("pause");
	return 0;
}