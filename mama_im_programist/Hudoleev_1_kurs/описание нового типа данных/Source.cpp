#include <iostream>
using namespace std;

struct student
{
	const char *name;
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

	for ( int i = 0; i < 5; i++)
	{
		vivodstudenta(isit[i]);
	}	
	cout << "\n";

	for (int i = 0; i < 5; i++)
	{
		int min = i;
		for (int a = i; a < 5; a++)
		{
			if (isit[a].group < isit[min].group) min = a;
		}
		student boof = isit[i];
		isit[i] = isit[min];
		isit[min] = boof;
	}
	for (int i = 0; i < 5; i++)
	{
		vivodstudenta(isit[i]);
	}
	cout << "\n";
	for (int i = 0; i < 5; i++)
		if (isit[i].uspi >= 4) vivodstudenta (isit[i]);
	return 0;
}