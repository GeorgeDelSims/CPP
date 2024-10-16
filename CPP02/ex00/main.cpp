#include "Fixed.hpp"

int     main()
{
    Fixed   a;
    Fixed   b(a);
    Fixed   c;
        
    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

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