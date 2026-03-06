#include <iostream>
using namespace std;

class Animal
{
	public:
	int age = 10;
	virtual void sound()
	{
		cout << "animal sound" << endl;	
	}
};

class Cat : public Animal
{
	public:
	string name = "قمر الدين دبيازة";
	void sound()
	{
		cout << "MEAWWWWWWW" << endl;
	}
};

int main()
{
	Animal A;
	Animal *AC = new Cat();
	Cat C;
	Cat *PC =  static_cast<Cat *>(&A);
	AC->sound();
	cout << PC->age << endl;
	cout << PC->name << endl;
	AC->sound();
}