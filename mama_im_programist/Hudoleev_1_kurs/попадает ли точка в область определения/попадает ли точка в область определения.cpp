#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	float x, y;
	cout << "Введите координаты точки в виде: x y";
	cin >> x >> y;
	if (x * x + y * y <= 1||y >= -x - 2 && x <= 0 && y <= 0) cout << "Координата принадлежит области";
	else cout << "Координата не принадлежит области";
}


