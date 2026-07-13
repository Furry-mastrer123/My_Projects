#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	n = rand() % 25;
	cout << "\t" << n << "\n";
	int *mas =new int [n];
	srand(time(0));
	for (int i = 0; i != n; i++)
	{
		mas[i] = rand() % 20 - 10;
		cout << mas[i] << "\t";
	}
	cout << "\n";
	int m = sizeof mas;
	sort (mas,mas +m );
	for (int i = 0; i != n; i++)
	{
		cout << mas[i] << "\t";
	}
}