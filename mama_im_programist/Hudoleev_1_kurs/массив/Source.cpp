#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	int mas[20], k1 = 0, k2 = 0;
	srand(time(0));
	for (int i = 0; i <20; i += 1)	//k1 - положительные, k2 - отрицательные
	{
		mas[i] = rand() % 200 - 100;
		cout << mas[i] << " ";
		if (mas[i] > 0)k1++;
		else k2++;
	}
	cout << "\n ћассив заполнен";
	cout << "\n ѕоложительных значений массива - " << k1;
	cout << "\n ќтрицательных значений массива - " << k2;
	cout << "\n";
	for (int i = 0; i <20; i++)
	{
		int min = i;
			for (int a=i ; a < 20; a++)
			{
				if (mas[a] < mas[min]) min = a;
			}
		int boof = mas[i];
		mas[i] = mas[min];
		mas[min] = boof;
		cout << mas[i] << " ";
	}
}