#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	int x;
	do {
		cout << "Введите день недели:\t";
		cin >> x;
		switch (x)
		{
		case 1: cout << "Понедельник\n"; break;
		case 2 : cout << "Вторник\n"; break;
		case 3 : cout << "Среда\n"; break;
		case 4 : cout << "Четверг\n"; break;
		case 5 : cout << "Пятницв\n"; break;
		case 6 : cout << "Суббота\n"; break;
		case 7 : cout << "Воскресенье\n"; break;
		default: cout << "Нет такого дня\n"; break;
		}
	}
	while (x > 0 && x <= 7);
}