#include <iostream>
#include <clocale>
#include <Windows.h>

	template <typename T> 
	void Summ(T a, T b)
	{
		std::cout << a + b;
	}


using namespace std;
struct pidorsnarazrabax
{
	char name[20];
	char profession[10];
};
void vizov(pidorsnarazrabax s)
{
	cout << s.name << " " << s.profession << "\n";
}
int main()
{
	setlocale(LC_CTYPE, "ru");
	SetConsoleCP (1251);
	pidorsnarazrabax easports[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите имя человека ";
		cin >> easports[i].name;
		cout << "Введите проффесию человека ";
		cin >> easports[i].profession;
	}
	for (int i = 0; i < 3; i++)
	{
		vizov(easports[i]);
	}
	return 0;
	short int i = 448588;
	cout << i;

	Summ(100, 2300);			// это уже для другой хуйни 

}