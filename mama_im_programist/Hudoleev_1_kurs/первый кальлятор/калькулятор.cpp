#include <iostream>

class function
{
public:
	virtual float Foo(float a, float b) = 0;
};

class substraction : public function
{
public:
	float Foo(float a, float b) override
	{
		return a - b;
	}
};

class sum : public function
{
public:
	float Foo(float a, float b) override
	{
		return a + b;
	}
};

class multiplication : public function
{
public:
	float Foo(float a, float b) override
	{
		return a * b;
	}
};

class division : public function
{
public:
	float Foo(float a, float b) override
	{
		if (b == 0) return 0;
		else return a / b;
	}
};


int main()
{
	using namespace std;								//чтобы не писать вечно std::cout и т.д.
	setlocale(LC_ALL, "ru");							//чтобы выводилось на русском

	float a, b, result;

	substraction sub;
	sum SUM;
	multiplication multi;
	division div;
	function** foo = new function * [4] {&SUM, & sub, & multi, & div};		//создаётся массив указателей, а не объектов абстрактного класса, которого не может существовать в c++			
	int op;


	cout << "Введите первую десятичную дробь" << endl;
	cin >> a;
	cout << "Введите вторую десятичную дробь" << endl;
	cin >> b;


	do
	{


		cout << "Введите желаемую операцию : 1 для сложения, 2 для разности, 3 для умножения и 4 для деления" << endl;
		cin >> op;


		switch (op)
		{
		case 1:
			cout << "Результат действия сложение: " << foo[0]->Foo(a, b) << endl;
			result = foo[0]->Foo(a, b);
			break;
		case 2:
			cout << "Результат действия разность: " << foo[1]->Foo(a, b) << endl;
			result = foo[0]->Foo(a, b);
			break;
		case 3:
			cout << "Результат действия умножение: " << foo[2]->Foo(a, b) << endl;
			result = foo[0]->Foo(a, b);
			break;
		case 4:
			if (b == 0) goto link;			//если пользователь нарушил правила математики, то он отправляется на 108 строку
			else {
				cout << "Результат действия деление: " << foo[3]->Foo(a, b) << endl;
				result = foo[0]->Foo(a, b);
				break;
			}
		default: cout << "неверный номер операции" << endl;
			break;
		}

		cout << "=============================================================" << endl;	//отделяет прошлую операцию от новой визуально

		int key;											//если пользователь хочет изменить значения он должен ввести нужный ключ
		cout << "Вы хотите изменить числа? если да, то введите цифру 0, если вы хотите работать с результатом данной операции, введите 1";
		cin >> key;
		if (key == 0) {
			cout << "Введите первую десятичную дробь" << endl;
			cin >> a;
			cout << "Введите вторую десятичную дробь" << endl;
			cin >> b;
		}
		if (key == 1) {
			a = result;
			cout << "Введите новое значение: " << endl;
			cin >> b;
		}

	} while (op >= 0 && op <= 5);
link:
	cout << "Вы нарушили логику программы, или данная функция ещё не определена :(" << endl;
	delete[] foo;
	return 0;
}