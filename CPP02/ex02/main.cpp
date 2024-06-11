#include "Fixed.hpp"

int     main()
{
    Fixed           a;
    Fixed const     b(Fixed(5.05f) * Fixed(2));
    Fixed const     c(Fixed(5.05f) + Fixed(2));
    Fixed const     d(Fixed(5.05f) - Fixed(2));

    std::cout << "a is " << a << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a++ is " << a << std::endl;

    std::cout << "b: "<<b << std::endl;
    std::cout << "c: "<<c << std::endl;
    std::cout << "d: "<<d << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return (0);
}

/*

Example: 

raw integer: 515 
00000000 00000000 00000010 00000011

as a Fixed Point Number: 2.3
00000000 00000000 00000010 , 00000011
    whole part: 
    00000000 00000000 00000010 ==> 2
    fractional part:
    00000011 ==> 3 

as a float: 
2.01171875 ( = 515 / 2^8  OR  = 515 / 256)
00000000 00000000 00000010 00000011

*/