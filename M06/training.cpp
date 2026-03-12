#include <iostream>
// #include <std>


using namespace std;
#include <stdio.h>


class Animal
{
	public:
		const int value = 20;
		void speak()
		{
			cout << "Animal Sound" <<endl;
		}
};

class Dog : public Animal
{
	public:
		const int age = 5;
		void bark()
		{
			cout << "Dog Sound" << endl;
		}
};


int main()
{
	const int x = 10;
	int *ptr = (int *)&x;
	*ptr = 20;
	cout << ptr << endl;
	cout << &x << endl;
	cout << *ptr << endl;
	cout << x << endl;
	Dog d;

	// UPCAST
	Animal *A1 = new Dog();
	Animal *A2 = new Animal();
	A1->speak();
	// A1->bark();
	// DOWNCAST
	Dog *D1 = static_cast<Dog *>(A1);
	Dog *D2 = static_cast<Dog *>(A2);
	D1->bark();
	D1->speak();
	D2->bark();
	cout << D2->age << endl << D2->value;
	D2->speak();
}

// printf("%d\n", *ptr);
// printf("%d\n", x);
// printf("%p\n", ptr);
// printf("%p\n", &x);

