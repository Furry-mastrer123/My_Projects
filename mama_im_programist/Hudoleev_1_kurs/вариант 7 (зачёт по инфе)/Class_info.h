class MARSH
{
	char* startp = new char;								//start point
	char* endp = new char;									//end point
	int waynum;												//way number 
public:
	MARSH();
	MARSH(const char *a, const char* b, int c);
	MARSH(MARSH&);
	~MARSH();
	MARSH& operator = (MARSH& op1);
	bool operator < (MARSH& op2);
	bool operator == (MARSH& op3);
	void print();
};

MARSH::MARSH()
{
	startp = new char[100];
	endp = new char[100];
	waynum = 0;
}

MARSH::MARSH(const char* a, const char* b, int c)
{
	startp = new char [strlen(a)+1];
	strcpy(startp, a);
	endp = new char[strlen(b)+1];
	strcpy(endp, b);
	waynum = c;
	std::cout << "Вызван конструктор копирования для";
}

MARSH::MARSH (MARSH& n1)
{
	delete[] startp;
	startp = new char[strlen(n1.startp) + 1];
	strcpy(startp, n1.startp);
	delete[] endp;
	endp = new char[strlen(n1.endp) + 1];
	strcpy(endp, n1.endp);
	waynum = n1.waynum;
}

MARSH::~MARSH()
{
	delete[] startp;
	delete[] endp;
	std::cout << "Маршрут удалён" << std::endl;
}

MARSH& MARSH::operator = (MARSH& op1)
{
	if (this == &op1) return *this;
	else {
		delete[] startp;
		startp = new char[strlen(op1.startp) + 1];
		strcpy(startp, op1.startp);
		delete[] endp;
		endp = new char[strlen(op1.endp) + 1];
		strcpy(endp, op1.endp);
		waynum = op1.waynum;
		return *this;
		}
}

bool MARSH::operator < (MARSH& op2)
{
	if (waynum < op2.waynum) return true;
	else return false;
}

bool MARSH::operator == (MARSH& op3)
{
	if (op3.waynum == waynum)return true;
	else return false;
}

void MARSH::print()
{
	std::cout << "Начальная точка маршрута - " << startp;
	std::cout << "\nКонечная точка маршрута - " << endp;
	std::cout << "\nНомер маршрута - " << waynum << std::endl;
}