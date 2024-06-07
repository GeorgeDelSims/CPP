#include "Fixed.hpp"

int     main()
{
    Fixed           a;
    Fixed const     b(10);
    Fixed const     c(42.42f);
    Fixed const     d(b);
        
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl; 
    std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
    std::cout << "c is " << c.toInt() << " as integer" << std::endl; 
    std::cout << "d is " << d.toInt() << " as integer" << std::endl; 

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