#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "ru");
	float x1, t, x2, d, y;//x-перва€ координата t-константа k-конечное значение x d- шаг(дельта)
	cout << "¬ведите начальное значение x:\t";
	cin >> x1;
	cout << "¬ведите конечное значение x:\t";
	cin >> x2;
	cout << "¬ведите шаг:\t";
	cin >> d;
	cout << "¬ведите переменную t:\t";
	cin >> t;
	for (float x= x1; x != x2; x += d)
	{
		if (x < 0) y = t;
		else if (x >= 0 && x <= t) y = x + t;
		else if (x > t) y = 2*t;
		cout << x << "\t" << y << "\n";
	}
}