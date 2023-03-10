#include <fstream>
#include <iostream>
#include "structure.h"
#include "functions_proto.h"
using namespace std;
char menu()
{
	char answer;
	setlocale(LC_ALL, "Russian");
	cout << "����: " << endl;
	cout << "1. �������� ����� ����� � �������" << endl;
	cout << "2. ������� ����� �� �������" << endl;
	cout << "3. ��������� ����� � ����������� �� �������" << endl;
	cout << "4. ��������� ����� � �������� �� ����������" << endl;
	cout << "5. �������� �������" << endl;
	cout << "6. ������� ������� � ���� \"out.txt\"" << endl;
	cout << "7. �����" << endl;
	cout << "�������� ��������: ";
	cin >> answer;
	return answer;
}
void add_word(Dictionary* d, int* word_amount)
{
	setlocale(LC_ALL, "Russian");
	char* eng_word;
	char* rus_word;
	char temp_arr[31];
	int i=0;
	cout << endl << "������� ����� ����� �� ���������� �����: ";
	cin >> temp_arr;
	eng_word=new char[strlen(temp_arr)+1];
	strcpy_s(eng_word, strlen(temp_arr)+1, temp_arr);
	cout << "������� �����, ������������ �� ������� ����: ";
	cin >> temp_arr;
	rus_word=new char[strlen(temp_arr) + 1];
	strcpy_s(rus_word, strlen(temp_arr)+1, temp_arr);
	if ((*word_amount)==0)
	{
		strcpy_s(d[i].eng, strlen(eng_word)+1, eng_word);
		strcpy_s(d[i].rus, strlen(rus_word)+1, rus_word);
	} 
	else 
	{
		d[(*word_amount)].eng = new char[strlen(eng_word)+1];
		d[(*word_amount)].rus = new char[strlen(rus_word)+1];
		strcpy_s(d[(*word_amount)].eng, strlen(eng_word)+1, eng_word);
		strcpy_s(d[(*word_amount)].rus, strlen(rus_word)+1, rus_word);
		for (i=(*word_amount); i>0; i--)
		{
			if (strcmp(d[i].eng, d[i-1].eng)<0) 
			{
				swap(d[i].eng, d[i-1].eng);
				swap(d[i].rus, d[i-1].rus);
			}
		}
	}
	(*word_amount)++;
	cout << "����� ������� ��������� � �������." << endl << endl;
}
void delete_word(Dictionary* d, int* word_amount)
{
	setlocale(LC_ALL, "Russian");
	char temp_arr[31];
	int i=0;
	if ((*word_amount)<=0)
	{
		cout << endl << "������: ������� ����!" << endl << endl;
	} 
	else 
	{
		cout << endl << "������� �����, ������� �� ������ ������� (�� ���������� �����): ";
		cin >> temp_arr;
		for (i=0; i<(*word_amount); i++) 
		{
			if (strcmp(d[i].eng, temp_arr)==0)
			{
				for (int j=i; j<((*word_amount)-1); j++) 
				{
					d[j]=d[j+1];
				}
				cout << "����� ������� �������." << endl << endl;
				(*word_amount)--;
				break;
			}
			if (i==((*word_amount)-1)) 
			{
				cout << "������: ������� ����� ��� � �������!" << endl << endl;
			}
		}
	}
}
void eng_to_rus(Dictionary* d, int* word_amount) 
{
	setlocale(LC_ALL, "Russian");
	char temp_arr[31];
	int i=0;
	if ((*word_amount)<=0)
	{
		cout << endl << "������: ������� ����! " << endl << endl;
	}
	else 
	{
		cout << endl << "������� �����, ������� �� ������ ��������� � ����������� �� �������: ";
		cin >> temp_arr;
		for (i=0; i<(*word_amount); i++) 
		{
			if (strcmp(d[i].eng, temp_arr)==0) 
			{
				cout << "������� ����� ����� �� �������: " << d[i].rus << endl << endl;
				break;
			}
			if (i==((*word_amount)-1)) 
			{
				cout << "������: ����� ����� ��� � �������!" << endl << endl;
				break;
			}
		}
	}
}
void rus_to_eng(Dictionary* d, int* word_amount)
{
	setlocale(LC_ALL, "Russian");
	char temp_arr[31];
	int i=0;
	if ((*word_amount)<=0)
	{
		cout << endl << "������: ������� ����! " << endl << endl;
	}
	else 
	{
		cout << endl << "������� �����, ������� �� ������ ��������� � �������� �� ����������: ";
		cin >> temp_arr;
		for (i=0; i<(*word_amount); i++) 
		{
			if (strcmp(d[i].rus, temp_arr)==0) 
			{
				cout << "������� ����� ����� �� ����������: " << d[i].eng << endl << endl;
				break;
			}
			if (i==((*word_amount)-1)) 
			{
				cout << "������: ����� ����� ��� � �������!" << endl << endl;
			}
		}
	}
}
void show_dict(Dictionary* d, int* word_amount)
{
	int i=0;
	cout << endl << "������� [ENG - RUS]: " << endl;
	for (i=0; i<(*word_amount); i++) 
	{
		cout << d[i].eng << " - " << d[i].rus << endl;
	}
	cout << endl;
}
void dict_out(Dictionary* d, int* word_amount) 
{
	ofstream fout;
	int i=0;
	fout.open("out.txt");
	for (i=0; i<(*word_amount); i++)
	{
 		fout << d[i].eng << " - " << d[i].rus << endl;
	}
	cout << endl << "������� ������� ������� � ���� \"out.txt\"." << endl << endl;
}