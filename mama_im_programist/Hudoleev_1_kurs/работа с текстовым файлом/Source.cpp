#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	FILE *f;
	f = fopen("readme.txt", "r");
	char mass[300][50];
	if (f == NULL) cout << "Файл не открылся";
	else {
		int numberofwords = 0;
		for (; ; )
		{
			fscanf(f, "%s", mass[numberofwords]);
			if (feof(f) != 0) break;
			cout << mass[numberofwords] << " ";
			numberofwords = numberofwords++;
		}
		cout << "\nКоличество слов - " << numberofwords;
		int korotkoe = 0;
		int dlinnoe = 0;
		for (int i = 0; i != numberofwords; i++)
		{
			if (strlen(mass[korotkoe]) > strlen(mass[i])) korotkoe = i;
			if (strlen(mass[dlinnoe]) < strlen(mass[i])) dlinnoe = i;
		}
		cout << "\n Самое длинное слово - " << string(mass[dlinnoe]);
		cout << "\n Самое короткое слово - " << string(mass[korotkoe]);
	}
}