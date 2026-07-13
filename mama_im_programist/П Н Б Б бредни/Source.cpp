#include <iostream>
#include <cstdlib>
#define k 1000
using namespace std;


class pnbb
{
private:

	int data1;

public:

	class pnbb2 {

		int data2;

	public: pnbb2(int value2)
	{
		data2 = value2;
	}

		  int Getint() const
		  {
			  return this->data2;
		  }
	};
};

//class A{
//public:
//	virtual int Foo(int a) { return a; }
//	A() {
//		cout << "A class made";
//	}
//	~A() {
//		cout << "A class is determined";
//	}
//};
//
//
//class B: public A {
//public:
//	int Foo(int a) override {
//		return a + 1;
//	}
//	B() {
//		cout << "B class made";
//	}
//	~B() {
//		cout << "B class is determined";
//	}
//};
//
//class C : public A, public B {
//public:
//	C() {
//		cout << "C class is made";
//	}
//	~C() {
//		cout << "C class is determined";
//	}
//};


int main()
{
//	int x { 5 };
//	cout << x << endl;
//	int y[] = { 1,2 ,3,4 };
//	int* z {y};
//	for (int i =0; i != sizeof(y)/4; i++)						//sizeof(int) = 4 !!!!!
//	{
//		cout <<(z+i)<< "\t" <<  * (z + i) << endl;
//	}
//	char* m{(char*)z};
//	*m = 'k';
//	cout<<  z <<endl <<  m;
//	const char *Chararr[] = {"Hello", "World", "re"};				// char* он ругается ппц как истеричка без const
//#if k >100
//	{
//		cout << "sosat" << endl;
//	}
//#endif 
//	pnbb a();
//	pnbb::pnbb2 atrey (20);
//	cout << atrey.Getint();
//	//A a1;
//	//cout << a1.Foo(20);
//	//B b;
//	//cout << b.Foo(20);
//	//cout << b.A::Foo(20);
//	//cout << "=====================" << endl;
//	//C c;
//	try {
//		cerr << "vi loh";
//		int a;
//		cin >> a;
//		cout << 5 / a;
//		int b, c, d;
//	}
//	catch (const int c)
//	{
//	}
	int a = 10;
	auto f = [a]() {int b = 10;
	cout << b - a;
		};
	f();df'ljng '
}