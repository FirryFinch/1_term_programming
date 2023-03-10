#include <iostream>
#include <fstream>
#include "func_proto.h"
using namespace std;
void main()
{
	system("chcp 1251 > nul");
	cout << "���������, ��� � ����� � �������� ��������� ���� � ������ \"key.txt\" � ���� � ������� \"text.txt\"." << endl;
	cout << "������������� ���� \"encrypted.txt\" � �������������� ���� \"decrypted.txt\" ����� ����� ���������� � ����� � ��������" << endl << endl;
	char answ_char = 'y';
	do
	{
		int wordcounter=0;	
		wordcounter=how_many_words();
		int* words=new int[wordcounter];
		key_arr_creator(words, &wordcounter);
		int stats[256];
		for (int i=0; i<256; i++)
		{
			stats[i]=0;
		}
		encrypter(words, &wordcounter, stats);
		decrypter(words, &wordcounter);
		cout << endl;
		cout << "����������: " << endl;
		for (int i=0; i<16; i++)
		{
			for (int j=0; j<16; j++)
			{cout << stats[16*i+j] << " ";}
			cout << endl;
		}
		delete[]words;
		cout << endl;
		cout << "���������? (y/n) ";
		cin >> answ_char;
	}
	while (answ_char == 'y');
	system("pause");
}