#include "Functions.hpp"

int main()
{
	int		a = 10, b = 5;
	float	x = 4.67, y = 10.54;
	char 	c = 'g', d = 'x';

	std::cout << "before swap :\n";
	std::cout << "a : " << a << "\nb : " << b << std::endl;
	swap(a, b);
	std::cout << "after swap :\n";
	std::cout << "a : " << a << "\nb : " << b << std::endl;

	std::cout << "before swap :\n";
	std::cout << "x : " << x << "\ny : " << y << std::endl;
	swap(x, y);
	std::cout << "after swap :\n";
	std::cout << "x : " << x << "\ny : " << y << std::endl;

	std::cout << "before swap :\n";
	std::cout << "c : " << c << "\nd : " << d << std::endl;
	swap(c, d);
	std::cout << "after swap :\n";
	std::cout << "c : " << c << "\nd : " << d << std::endl;

	std::cout << "\nMax of a & b : " << max(a,b) << "\n";
	std::cout << "min of a & b : " << min(a,b) << "\n";
	std::cout << "Max of x & y : " << max(x,y) << "\n";
	std::cout << "Min of x & y : " << min(x,y) << "\n";
	std::cout << "Max of c & d : " << max(c,d) << "\n";
	std::cout << "Min of c & d : " << min(c,d) << "\n";

	return (0);
}
