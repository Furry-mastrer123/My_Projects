/*
 Моя первая программа на C++
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <windows.h>
#include <stdio.h>

#include <iostream>
#include <iomanip>
using namespace std;

//Главная функция
int main()
{
	setlocale(LC_CTYPE, "ru");
	const int size = 0x20;
	char firstName[size], lastName[size], temp[size];
	int repeat;

	auto locale = _create_locale(LC_ALL, ".866");

	printf("\nВведите ваше имя: ");
	_scanf_s_l("%s", locale, temp, size);
	OemToChar(temp, firstName);

	_free_locale(locale);

	cout << "Введите Фамилию: ";
	cin >> temp;
	OemToChar(temp, lastName);

	fprintf(stdout, "Сколько развас приветствовать? ");
	fscanf_s(stdin, "%d", &repeat);
	cout << endl;

	for (int i = 0; i < repeat; i++)
	{
		cout << setw(2) << i + 1 << ".";
		cout << "Привет, " << firstName << " " << lastName << "!" << endl;
	}
	cout << endl;
}
/* 
Конец программы
*/