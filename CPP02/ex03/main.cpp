#include "Fixed.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include <iostream>

/*
cross product : (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax)
*/

// Get a vector between each relevant point with the vector constructor
// calculate the cross product of the triangle vectors and the point vector
bool    bsp(const Point a, const Point b, const Point c, const Point point)
{
    Vector  AB(a, b);
    Vector  BC(b, c); 
    Vector  CA(c, a);

    Vector AP(a, point);
    Vector BP(b, point);
    Vector CP(c, point);

    Fixed cpA = Vector::crossproduct(AB, AP);
    Fixed cpB = Vector::crossproduct(BC, BP);
    Fixed cpC = Vector::crossproduct(CA, CP);

    if (cpA > 0 && cpB > 0 && cpC > 0)
        return (true);
    else if (cpA < 0 && cpB < 0 && cpC < 0)
        return (true);
    else 
        return (false);
}

// 
int     main()
{
    Point const a(1.3f, 2.7f);
    Point const b(7.5f, 2.9f);
    Point const c(4.06f, 6.43f);
    Point const point(4.2f, 3.05f);

    if (bsp(a, b, c, point) == true)
        std::cout << "The point (" << point.get_x() << " : " << point.get_y() << ") is in the triangle." << std::endl;
    else
        std::cout << "The point (" << point.get_x() << " : " << point.get_y() << ") is NOT in the triangle." << std::endl;
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