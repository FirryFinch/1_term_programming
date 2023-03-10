#include <iostream>
#include <fstream>
#include "func_proto.h"
using namespace std;
void main()
{
	system("chcp 1251 > nul");
	cout << "Убедитесь, что в папке с проектом находятся файл с ключом \"key.txt\" и файл с текстом \"text.txt\"." << endl;
	cout << "Зашифрованный файл \"encrypted.txt\" и расшифрованный файл \"decrypted.txt\" будут также находиться в папке с проектом" << endl << endl;
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
		cout << "Статистика: " << endl;
		for (int i=0; i<16; i++)
		{
			for (int j=0; j<16; j++)
			{cout << stats[16*i+j] << " ";}
			cout << endl;
		}
		delete[]words;
		cout << endl;
		cout << "Повторить? (y/n) ";
		cin >> answ_char;
	}
	while (answ_char == 'y');
	system("pause");
}