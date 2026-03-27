#include <iostream>

using namespace std;

class Base
{
	public:
	int data;
	void sayHello()
	{
		cout << "Hello From Base" << endl;
	}
	virtual ~Base(){};
};

class Derived: public Base
{
	public:
	std::string name;
	int age;
	void sayHello()
	{
		cout << "Hello From Derived" << endl;
	}
};


int main()
{
	double x = 10;
	// double *dPtr = &x;
	int i = static_cast<char >(x);
	Base *B = new Base();
	Base *B1 = new Derived();

	Derived *D1 = dynamic_cast<Derived *>(B1);
	Derived *D2 = dynamic_cast<Derived *>(B);
	// if (D1 == nullptr)
	// 	std::cout  << "hhhh" << std::endl;
}