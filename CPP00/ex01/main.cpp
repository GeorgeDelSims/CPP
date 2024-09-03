#include "Phonebook.hpp"

int	main(void)
{
	Phonebook		_phonebook;
	std::string		str;
	
	while (str != "EXIT")
	{
		std::cout << "Enter a command : ";
		std::getline(std::cin, str);
		if (str == "ADD")
			_phonebook.add();
		else if (str == "SEARCH")
		{	
			_phonebook.search();
			std::cout << "Enter an index : ";
			std::getline(std::cin, str);
			_phonebook.search_index(str);
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
