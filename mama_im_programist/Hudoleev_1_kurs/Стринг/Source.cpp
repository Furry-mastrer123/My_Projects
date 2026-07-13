#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"

void String::print()
{
	if (str == NULL) std::cout << "your string is empty" << std::endl;
	else std::cout << "(" << len << ") "<< str << std::endl;
}

String String::operator +(String& op1)
{
	String op2;
	op2.len = len + op1.len;
	op2.str = new char[op2.len + 1];
	strcpy(op2.str, str);
	strcat(op2.str, op1.str);
	return op2;
}

String& String::operator =(const String& in)
{
	len = in.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, in.str);
	return *this;
}

bool String::operator >(String& op1)
{
	return (len > op1.len) ;
}

String::String(const char* x)
{
	len = strlen (x);
	str = new char [len+1];
	strcpy(str, x);
}

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const String& in)
{
	len = in.len;
	str = new char[len+1];
	strcpy(str, in.str);
}

String::~String()
{
	delete[] str;
}

void String::ToUpper()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
	}
}

void String::Tolower()
{
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
	}
}

void main()
{
	using namespace std;
	String c;
	String a("Bilo bilo G bilo F no  PS proshlo");
	String b("ayayayayayaya");
	a.print();
	b.print();
	c.print();
	c = a + b;
	c.print();
	if (a > b) a.print();
	else b.print();
	a.Tolower();
	a.print();
}