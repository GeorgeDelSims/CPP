#include "Fixed.hpp"
#include "Point.hpp"


/*

cross product : (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax)

*/

bool    bsp(const Point a, const Point b, const Point c, const Point point)
{
    int crossProductA;
    int crossProductB;
    int crossProductC;

    // crossproductA = (b._x - a._x) 


}


int     main()
{
    Point const a(1.3f, 2.7f);
    Point const b(0.5f, 4.9f);
    Point const c(6.06f, 3.43f);
    Point const point(4.2f, 1.05f);

    if (bsp(a, b, c, point) == true)
        std::cout << "The point " << point << "is in the triangle." << std::endl;
    else
        std::cout << "The point " << point << "is NOT in the triangle." << std::endl;
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