#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "ru");
	int kolvovichisleniy;															//доверительная вероятность
	double sr, srqwotk, cenapribora;										// sr - среднее значение, srqwotk - среднеквадратичное отклонение
	cout << "Внимание, эта программа не считает важные числа! Она предназначена исключительно для вычисления значения и погрешностей прямого измерения " << endl;
	cout << "Введите кол-во значений измерений: ";
	cin >> kolvovichisleniy;

	cout << "Введите цену деления прибора: ";
	cin >> cenapribora;

	double *massznacheniy = new double [kolvovichisleniy];

	for (int i = 0; i != kolvovichisleniy; i++)
	{
		cout << "Введите " << i+1 << " измерение: ";
		cin >> massznacheniy[i];											// заполнение массива(все полученные значения)
		cout << "\n";
	}

	double sum1 = 0;														//ввёл дополнительную переменную, чтобы посчитать сумму

	for (int i = 0; i != kolvovichisleniy; i++)
	{
		sum1 = sum1 + massznacheniy[i];
	}

	sr = sum1 / kolvovichisleniy;
	cout << "Среднее значение = " << sr << endl;
	double sum2 = 0 ;

	for (int i = 0; i != kolvovichisleniy; i++)
	{
		sum2 = sum2 + pow((massznacheniy[i] - sr), 2);						//вычисление суммы отклонений в квадрате pow - функция, возводящая в степень 
	}

	srqwotk = sqrt(sum2 / (kolvovichisleniy * (kolvovichisleniy - 1)));		// вычисление среднеквадратичного отклонения 
	cout << "Среднеквадратичное отклонение = " << srqwotk << endl;
	double prpogr, slpogr;													// prpogr - приборная погрешность, slpogr - случайнкая погрешность 
	float koefst_1, koefst_2 = 1.96, oppogr;								//oppogr - итоговая погрешность прямого измерения
	cout << "Введите значение коэффициента Стьюдента для доверительной вероятности 0,95, соответствующее вашему количеству измерений минус 1 - ";
	cin >> koefst_1;
	slpogr = srqwotk * koefst_1;
	prpogr = 1 / 3. * cenapribora * koefst_2;
	oppogr = sqrt(slpogr * slpogr + prpogr * prpogr);
	cout << "Случайная погрешность: " << slpogr << endl;
	cout << "Приборная погрешность: " << prpogr << endl;
	cout << "Итоговая погрешность прямого измерения - " << oppogr;
	return 0;
}