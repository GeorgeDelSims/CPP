#include "ScalarConverter.hpp"

int main()
{
	std::string		s1 = "a43tg";
	std::string		s2 = "-123.43";
	std::string		s3 = "123";
	std::string		s4 = "-12.3f";
	// int				i;


	// i = ScalarConverter::getType(s1);
	// std::cout << s1 << " is of type : " << i << std::endl;

	// i = ScalarConverter::getType(s2);
	// std::cout << s2 << " is of type : " << i << std::endl;

	// i = ScalarConverter::getType(s3);
	// std::cout << s3 << " is of type : " << i << std::endl;

	// i = ScalarConverter::getType(s4);
	// std::cout << s4 << " is of type : " << i << std::endl;

	ScalarConverter::convert(s1);
	ScalarConverter::convert(s2);
	ScalarConverter::convert(s3);
	ScalarConverter::convert(s4);

	return (0);
}
