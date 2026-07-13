#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	cout << "Введите градусы в фаренгейтах:";
	float C, F;
	cin >> F;
	C = 5/9. * (F - 32);
	cout << "В градусах Цельсия это будет: " <<C;
}