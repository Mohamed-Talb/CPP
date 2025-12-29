#include "Fixed.hpp"

// using namespace std;
// int main( void ) 
// {
//     Fixed a;
//     Fixed b( a );
//     Fixed c;
//     c = b;
//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;
//     return 0;
    
    
//     // int value = 10.0; 0000 1010
//     // int newv = value << 8; // 0000  0000 1010 0000

//     // int value = 10;
//     // int fixed = 10 << 8;
//     // cout << fixed << endl;
//     // // int value = fixed >> 8;
//     // // cout << value << endl;

//     // float fvalue = 10.6; //0000 1,0100000 * 2^3 // exponent = 130
//     // float ffixed = 10.6 * 256;
//     // cout << ffixed << endl;
// }

#include <iostream>
int main( void ) 
{
    Fixed a(10.51f); // 10.5078 error : 0.0022
    // Fixed const b( 10 );
    // Fixed const c( 42.42f );
    // Fixed const d( b );
    // a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    Fixed b;
    
    b = a;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}