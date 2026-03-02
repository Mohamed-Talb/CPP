#include <iostream>

// class Me
// {
//     private:
//     int iDontKnow;
//     public:
//     Me(int v): iDontKnow(v)
//     {
//         std::cout << "Constrctor me" << std::endl;
//     }
//     class Her
//     {
//         private:
//         int iKnow;
//         public:
//         Her(int v)
//         {
//             iKnow = v;
//         }
// 		void display();
//         void show(Me &mtaleb)
//         {
//             std::cout << "mtaleb: " << mtaleb.iDontKnow << std::endl;
//         }
// 		void set(Me &mtaleb, int v)
// 		{
// 			mtaleb.iDontKnow = v;
// 		}
//     };
// };

// void Me::Her::display()
// {
// 	std::cout  << "DIFF PERSON IN THE SAME WORLD" << std::endl;
// }
// int main()
// {
//     Me mtaleb(0);
//     Me::Her someOne(100);
//     someOne.show(mtaleb);
// 	someOne.display();
// 	someOne.set(mtaleb, 25);
//     someOne.show(mtaleb);
// }

using namespace std;
// #include <stdexcept>
// int main()
// {
// 	int choise;
// 	cout << "Enter a Number" << endl;
// 	cin >> choise;
// 	try
// 	{
// 		if (choise == 1)
// 			throw 100;
// 		else if (choise == 2)
// 			throw 13.37;
// 		else if (choise == 3)
// 			throw "invalid option";
// 		else 
// 			cout << "No exception occured\n";
// 	}
// 	catch(int err)
// 	{
// 		cout << "Integer exception caught: " << err << endl;
// 		return 1;
// 	}
// 	catch(double err)
// 	{
// 		cout << "Double exception caught: " << err << endl;
// 		return 1;
// 	}
// 	catch(const char *err)
// 	{
// 		cout << "string exception caught: " << err << endl;
// 		return 1;
// 	}		
// 	cout << "Program continues execution" << endl;
// };

// void testExeptions(int choise)
// {
// 	switch (choise)
// 	{
// 		case 1: 
// 			throw std::invalid_argument("INVALID ARGUMENT: option cannot be negative");
// 		case 2:
// 			throw std::out_of_range("OUT OF RANGE: index exceeds container size");
// 		case 3:
// 			throw std::runtime_error("RUNTIME ERROR: unexpected runtime condition");
// 		case 4:
// 			throw std::bad_alloc();
// 	}
// }

// int main()
// {
// 	int choise;
// 	cout << "Enter a Number" << endl;
// 	cin >> choise;
// 	try
// 	{
// 		testExeptions(choise);
// 	}
// 	catch(const std::invalid_argument &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 		return 1;
// 	}
// 	catch(const std::out_of_range &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 		return 1;
// 	}
// 	catch(const std::bad_alloc &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 	}
// 	catch(const std::exception &error)
// 	{
// 		std::cout << error.what() << std::endl;
// 		return 1;
// 	}
// };

// class InvalidArgExeption : public std::exception
// {
// 	private:
// 		std::string message;
// 	public:
// 		InvalidArgExeption(const std::string &msg): message(msg){};
// 		virtual const char* what() const throw()
// 		{
// 			return message.c_str();
// 		}
// 		virtual ~InvalidArgExeption() throw() {}
// };

// int main()
// {
// 	try {
// 		throw InvalidArgExeption("AGE cannot be negative");
// 	}
// 	catch (const InvalidArgExeption& e)
// 	{
// 		std::cout << e.what() << endl;
// 	}
// } 

class Demo
{
	private:
	int id;
	public:
	Demo(int id): id(id) {std::cout << "CONSTRUCTOR: " << id << endl;}
	~Demo() {std::cout << "DESTRUCTING: " << id << endl;};
};

void test()
{
	Demo Da(1);
	Demo Db(2);
	throw std::runtime_error("Exception Thrown");
	Demo Dc(3);
}

int main()
{
	try
	{
		test();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}