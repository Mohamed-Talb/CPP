#include <iostream>

using namespace std;
int main()
{
    char ch;
    string line;
    cout << "enter character: ";
    ch = cin.get();
    cout << "you entered: " << ch << endl;
    cin.ignore();
    ch = cin.get();
    cout << "you entered: " << ch << endl;
    // ch = cin.peek();
     ch = cin.get();
    cout << "you entered: " << ch << endl;
    getline(cin, line); // reads whole line
    // getline(cin, line); // reads whole line
    cout << "You entered: " << line << endl;
}