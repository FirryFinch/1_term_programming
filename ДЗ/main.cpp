#include <conio.h>
#include "functions_proto.h"
using namespace std;
int main()
{
	int size=1000, last_symbol_number=0;
	char* text=new char[size];
	for (int i=0; i<size; i++)
	{
		text[i]='0';
	}
	text_input(text, &last_symbol_number);
	text_transformation(text, &last_symbol_number);
	text_output(text);
	delete[] text;
	size=_getch();
	return 0;
}