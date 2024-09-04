#include <iostream>
/*
	Pointer : points to a memory address containing a value (a pointer is just a memory address)
	Reference : is a copy (within the scope of the function) of a value. Cannot be NULL, cannot be changed 
*/
int	main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string&	stringREF = str;
	//std::string&	stringREF2 = str; not possible to have a second reference on a value
	//std::string&	stringREF2; not possible to have an uninitialised reference --> it can't be changed so will always be equal to NULL.

	std::cout << "memory address of str : " << &str << std::endl;
	std::cout << "memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "memory address held by stringREF : " << &stringREF << std::endl;

	std::cout << "value of str : " << str << std::endl;
	std::cout << "value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF : " << stringREF << std::endl;
	return (0);
}
