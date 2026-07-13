#include <iostream>
#include <fstream>
using namespace std; 

template <class T> class stack
{
private:
	int Maxnum;									// для предохранения от перегрузки стека/кучи от информации ограничиваем кол-во ячеек памяти в стеке
	int Nownum = 0;

public:

	class Node								//т.н. внутренний (вложенный класс), хранит информацию в совеобразной ячейке
	{
	public:
		T data;
		Node* prev, * next;					//поскольку в внешнем классе есть всего два указателя, то связб держиться за счёт того, что элементы знают где расположен следующий и предыдущий
		Node(T data)							//у меня ошибка и есть ссылка на предыдущий и следующий, в оригинальном задании есть только *next(список односторонний, там также нет *ptrbeg)
		{
			this->data = data;				// по своей сути nullptr и NULL одно и то же, но компилятор может ругаться, если две переменные указыва.ют на NULL, поэтому лучше использовать nullptr
			prev = nullptr;
			next = nullptr;
		}
		~Node()
		{
			prev = nullptr;
			next = nullptr;
		}
	};

	friend ostream & operator << (std::ostream& os, const stack <typename T>& Stack)					//ебнутая перегрузка оператора потокового класса на вывод(используется friend, чтобы 
		// класс ostream имел доступ к полям privat у класса stack
	{
		if (Stack.ptrbeg == nullptr)
		{
			os << "there is no elements (((";
			return os;
		}
		else
		{
			Node* NOWNODE = Stack.ptrbeg;					//указываем на первую ячуйку и ебашим по всем, пока не наткнёмся на ячейку, которой не сущействует
			do
			{
				if (NOWNODE == nullptr) break;
				else os << "DATA: " << NOWNODE->data << "\t";
				NOWNODE = NOWNODE->next;
			} while (NOWNODE->next != nullptr);
			os << "DATA: " << NOWNODE->data << "\t";						//cout заменён на имя объекта класса, хз почему просто так работает 
			os << endl;
		}
		os << "the end of stack" << std::endl;
		return os;
	}


	Node* ptrbeg, * ptrend;						//pointer to begin, ptr to end оф хе лист (первая и замыкающая ячейки)
	

	~stack()									//конструкторы и деструкторы надо писать в public, иначе к ним невозможно обратиться изне класса -> нельхя создать или удалить объект
	{
		if (ptrbeg == nullptr) cout << "there is no elements in stack to delete them (((" << endl;
		else
		{
			do
			{
				Node* Newnode = this->ptrend;						// создаю объект внутри класса потому что до этого он запоминал последний адрес на этой строке и нихуя не происходило в цикле после первой итерации
				//ибо его дальше не переназначаю
				this->ptrend = Newnode->prev;
				delete ptrend->next;
				ptrend->next = nullptr;
			} while (ptrend != ptrbeg);									//раньше было пока ptrend != nullptr, но он ебал мне мозг ибо я даун: элементы не расположены друг за другом в памяти
																		//как в массиве, поэтому если не сравнить с несуществующим элементом (указателем на то, что сзади этого элемента ничего нет),
			//то он будет работать не со своей памятью(((
			cout << "list has been deleted" << endl;
		}
	}


	stack(int Maxnum)
	{
		this->Maxnum = Maxnum;
		ptrbeg = nullptr;
		ptrend = nullptr;
	}

	void push(T DATA)						//запихнуть ячейку на последнее место
	{
		Node* newNode = new Node(DATA);
		if (ptrbeg == nullptr)								// проверка на пустоту начала списка
		{
			ptrbeg = ptrend = newNode;
			Nownum = Nownum + 1;
		}
		else if (Nownum == Maxnum) std::cout << "there is no more space int stack (((" << std::endl;
		else
		{
			newNode->prev = ptrend;
			ptrend->next = newNode;
			ptrend = newNode;
			Nownum = Nownum + 1;
		}
	}
	void pop()											// удаление последней ячейки
	{
		if (ptrend == nullptr) std::cout << "there is no elements to delete (" << std::endl;
		else
		{
			ptrend = ptrend->prev;
			delete ptrend->next;						//при выходе из зоны видимости(занулении указателя или при выходе из тела функции) вызывается деструктор класса 
			ptrend->next = nullptr;
			Nownum = Nownum - 1;
		}
	}

};


	


int main()
{
	stack <int> Stack(20);
	for (int i = 0; i < 10; i++)
	{
		Stack.push(i);
	}
	cout << Stack;
	Stack.pop();
	cout << Stack;
	return 0;						// при выходе из функции или метода класса вызывается деструктор для созданных внутри функции элементов
}