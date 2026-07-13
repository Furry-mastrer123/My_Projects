#include <iostream>

int main()
{
	int loh = 2000;
	int* px = &loh;
	std::cout << px << std::endl << *px << std::endl << &px;
	return 0;
}