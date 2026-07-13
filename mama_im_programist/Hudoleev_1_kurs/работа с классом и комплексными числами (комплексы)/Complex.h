#include<iostream>

class Complex
{
	double re, im;						//re- נואכüםûו im - imaginary 
public:
	Complex();
	Complex(double x, double y);
	Complex operator + (Complex& op);
	Complex operator - (Complex& op1);
	Complex& operator = (const Complex& op2);
	void print();
};