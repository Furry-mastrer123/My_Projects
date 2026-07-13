#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

struct student
{
	char name[20];
	int group;
	double uspi;
};
void vivodstudenta(student s)
{
	cout << s.name << "\t" << s.group << "\t" << s.uspi << "\n";
}
int main()
{
	student isit[5] = {
		{"Худолеев", 1, 3.5},
		{"Погосян", 2, 4.0},
		{"Товашов", 3, 5.0},
		{"Борисова", 1, 5.0},
		{"Назаров", 3, 4.4}
	};
	setlocale(LC_CTYPE, "ru");
	for (int i = 0; i <= 5; i++)
	{
		vivodstudenta(isit[i]);
	}
	FILE* f;
	f = fopen("bazastudentov", "w+");
	int numberofstudent;
	if (f == NULL) cout << "Ваш файл не открылся";
	else {
		fwrite(isit, sizeof student, 5, f);
		do
		{
			cout << "Введите номер желаемого студента, начиная с первого: ";
			cin >> numberofstudent;
			fseek(f, numberofstudent * sizeof student - sizeof student, SEEK_SET);
			student buffer;
			fread(&buffer, sizeof student, 1, f);
			vivodstudenta(buffer);
		} 
		while (numberofstudent < 6 && numberofstudent>0);
		cout << "Нет такого студента";
	}
}