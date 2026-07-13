#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class syrostream
{
public:
	template <typename T>syrostream  operator << (T data) const;
	syrostream  operator << (const char* ch) const;
};

template <typename T> syrostream syrostream::operator << (T data) const
{
	cout << data;
	return *this;
}


syrostream syrostream::operator << (const char* ch) const
{
	char* buff = new char[strlen(ch) + 1];
	CharToOem(ch, buff);
	cout << buff;
	delete[] buff;
	return *this;
}

#define Cout syrostream()
