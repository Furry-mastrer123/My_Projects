#include <iostream>
#include <stdlib.h>
using namespace std;


int Arrayfill(const int stroka, const int colona, int** const massiv)
{
	for (int i = 0; i != colona; i++)
	{
		for (int m = 0; m != stroka; m++)
		{
			massiv[i][m] = rand() % 100;
		}
	}
	return 0;
}


void Arraicout(const int pivo, const int loh,int ** const massiv)
{
	for (int i = 0; i != loh; i++)
	{
		for (int m = 0; m != pivo; m++)
		{
			cout << massiv[i][m] << "\t";
		}
		cout << endl;
	}
}


int main()
{
	int rows, collomns;
	cout << "Please, enter how many collomns do you want to see: ";
	cin >> rows;
	cout << "Please, enter how many rows do you want to see: ";
	cin >> collomns;


	int** arr = new int* [rows];

	for (int i = 0; i != collomns; i++)
	{
		arr[i] = new int[collomns];
	}


	Arrayfill(rows, collomns, arr);
	Arraicout(rows, collomns, arr);


	return 0;
}