#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Class_info.h"
#include <stdio.h>


int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "ru");
	MARSH Russia[8];
	FILE* f = fopen("info.txt", "r");

	if (f == NULL) std::cout << "Не удалось открыть файл" << std::endl;
	else {

		for (int i = 0; i < 8; i++)
		{
			int res1, waynum_boof;
			const char* startp_boof = new char [100];
			const char* endp_boof = new char[100];
			res1 = fscanf(f, "%11s" "%11s" "%2i", startp_boof, endp_boof, &waynum_boof);
			MARSH BOOF (startp_boof, endp_boof, waynum_boof);
			Russia[i] = BOOF;
			Russia[i].print();
			delete[] startp_boof, endp_boof;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		int min = i;
		for (int a = i; a < 8; a++)
		{
			if (Russia[a] < Russia[min]) min = a;
		}
		MARSH temp = Russia[i];
		Russia[i] = Russia[min];
		Russia[min] = temp;
	}

	if (f != NULL)
	{
		fclose(f);
		f = NULL;							// опционально, для безопасности(честно - закрытие потока файла взято из интернета)
	}

	for (int i = 0; i < 8; i++)
	{
		Russia[i].print();
	}

	int vvod;
	do
	{
		std::cout << "Введите номер желаемого маршрута: ";
		std::cin >> vvod;
		MARSH BOOf(" ", " ", vvod);
		for (int i = 0; i < 8; i++)
		{
			if (Russia[i] == BOOf)
			{
				Russia[i].print();
				cout << endl;
			}
		}
	} while (vvod < 100 && vvod > 0);
	cout << "Нет такого маршрута, извините :( ." << endl;
	return 0;
}