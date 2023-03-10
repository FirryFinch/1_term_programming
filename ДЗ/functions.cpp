#include <conio.h>
using namespace std;
void text_input (char* text, int* last_symbol_number)
{
	int i=0, j=0, k=0;
	char current_char;
	current_char = _getch();
	do
	{
		if (i!=0)
		{
			current_char=_getch();
		}
		if (current_char!=8)
		{
			if ((current_char==' ') || (current_char=='.'))
			{
				_putch(current_char);
				text[k]=current_char;
				k++;
			}
			else
			{
				if ((current_char>=96) && (current_char<=122))
				{
					for (j=97; j<=122; j++)
					{
						if (current_char==char(j))
						{
							_putch(current_char);
							text[k]=current_char;
							k++;
							break;
						}
					}
				}
			}
		}
		else
		{
			if (k!=0)
			{
				_putch('\b');
				_putch(' ');
				_putch('\b');
				text[k-1]='0';
				k=k-1;
			}
		}
		i++;
	}
	while (current_char!='.');
	(*last_symbol_number)=k-1;
}
void text_transformation (char* text, int* last_symbol_number)
{
	//	Определяем длину последнего слова
	char current_char;
	int i,j;
	int last_word_length=0;
	for (i=((*last_symbol_number)-1); i>=0; i--)
	{
		if (text[i]!=' ')
		{
			last_word_length++;
			if (text[i-1]==' ')
			{
				break;
			}
		}
	}
	//	Создаем массив из символов последнего слова
	char* last_word=new char[last_word_length];
	for (j=0; j<last_word_length; j++)
	{
		last_word[j]=text[i+j];
	}
	//	Ищем самое длинное слово, чтобы выделить место под создание массива для записи временного слова
	int how_many_symbols_in_current_word=0, how_many_symbols_in_longest_word=0;
	for (i=0; i<(*last_symbol_number); i++)
	{
		current_char=text[i];
		if (current_char!=' ')
		{
			how_many_symbols_in_current_word++;
		}
		else
		{
			if (how_many_symbols_in_current_word>how_many_symbols_in_longest_word)
			{
				how_many_symbols_in_longest_word=how_many_symbols_in_current_word;
			}				
			how_many_symbols_in_current_word=0;
		}
	}
	//	Выделили место под временное слово
	char* current_word=new char[how_many_symbols_in_longest_word];
	for (i=0; i<how_many_symbols_in_longest_word; i++)
	{
		current_word[i]='0';
	}
	//	Ищем слово = последнему и удаляем его
	int k=0;
	i=0;
	current_char=text[i];
	for (i=0; current_char!='0'; i++)
	{
		current_char=text[i];
		if ((current_char!=' ') && (current_char!='0'))
		{
			j=0;
			while ((text[i+j]!=' ') && (text[i+j]!='.'))
			{
				current_char=text[i+j];
				current_word[j]=current_char;
				j++;
			}
			how_many_symbols_in_current_word=j;
			for (j=0; j<how_many_symbols_in_current_word; j++)
			{
				if (current_word[j]==last_word[j])
				{
					k++;
				}
			}
			if ((how_many_symbols_in_current_word==last_word_length)&&(k==last_word_length))
			{
				for (j=0; text[i+j]!='0'; j++)
				{
					text[i+j]=text[i+j+last_word_length];
				}
				(*last_symbol_number)++;
				(*last_symbol_number)-=last_word_length;

			}
			else
			{
				i=i+how_many_symbols_in_current_word;
			}
			for (j=0; j<how_many_symbols_in_longest_word; j++)
			{
				current_word[j]='0';
			}
			k=0;
		}
	}
	delete[] last_word;
	delete[] current_word;
	// Удаляем предыдущие вхождения последней буквы
	char last_letter;
	int q=0;
	current_char=text[0];
	(*last_symbol_number)--;
	for (i=0; current_char!='.'; i++)
	{
		current_char=text[i];
		if ((current_char!=' ') && (current_char!='.'))
		{
			for (j=i; ((text[j]!=' ') && (text[j]!='.')); j++)
			{
				last_letter=text[j];
			}
			j=j-1;
			for (k=i; ((text[k+1]!=' ') && (text[k+1]!='.')); )
			{
				if (text[k]==last_letter)
				{
					for (q=k; (text[q]!='0'); q++)
					{
						text[q]=text[q+1];
					}
					(*last_symbol_number)-=1;
				}
				else
				{
					k++;
				}
			}
			i=k;
		}
	}
	// Убираем пробелы между словами
	for (i=0; i<(*last_symbol_number);)
	{
		if (text[i]==' ')
		{
			if (text[i+1]==' ')
			{
				for (j=i; j<=(*last_symbol_number); j++)
				{
					text[j]=text[j+1];
				}
				(*last_symbol_number)--;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	// Пробелы в начале
	i=0, j=0;
	current_char=text[i];
	if (current_char==' ')
	{
		while (current_char==' ')
		{
			for (j=i; j<=(*last_symbol_number); j++)
			{
				text[j]=text[j+1];
			}
			(*last_symbol_number)--;
			current_char=text[i];
		}
	}
	// Пробелы в конце
	i=(*last_symbol_number)-1;
	current_char=text[i];
	if (current_char==' ')
	{
		while (current_char==' ')
		{
			for (j=i; j<=(*last_symbol_number); j++)
			{
				text[j]=text[j+1];
			}
			(*last_symbol_number)--;
			i--;
			current_char=text[i];
		}
	}
}
void text_output (char* text)
{
	_putch('\n');
	for (int i=0; text[i]!='.'; i++)
	{
		_putch(text[i]);
	}
	_putch('\n');
}