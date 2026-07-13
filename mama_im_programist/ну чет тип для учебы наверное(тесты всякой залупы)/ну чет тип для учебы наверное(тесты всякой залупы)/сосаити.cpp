#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
	setlocale(LC_CTYPE, "en");
	const char* buff = "Suck";
	FILE* F = fopen("POSHEL NAHUY", "wb");
	if (F == NULL) std::cout << "Mi v Pizde" << std::endl;
	fprintf(F, "%s", buff);
	fclose(F);
	FILE* M = fopen("POSHEL NAHUY", "r");
	char* mass = new char[100];
	fgets(mass, 5, M);
	std::cout << mass << std::endl;
	return 0;
}								//Нихуя не работает