#include <iostream>
#include "Complex.h"
using namespace std;


Complex::Complex()
{
	re = 0;
	im = 0;
}


Complex::Complex(double x, double y)
{
	re = x;
	im = y;
}


	Complex Complex::operator + (Complex& a)
	{
		Complex n;
		n.re = re + a.re;
		n.im = im + a.im;
		return n;
	}


	Complex Complex::operator - (Complex& b)
	{
		Complex k;
		k.re = re - b.re;
		k.im = im - b.im;
		return k;
	}


	Complex& Complex::operator = (const Complex& c)
	{
		re = c.re;
		im = c.im;
	}


	void Complex::print()
	{
		cout << "(" << re << ", " << im << ")" << endl;
	}


	int main()
	{
		Complex per(1.1, 2.2), vtor(3.3, 4.4), tret;
		per.print();
		vtor.print();
		tret = per + vtor;
		tret.print();
		tret = per - vtor;
		tret.print();
		return 0;
	}