#include "Phonebook.hpp"

// Function to trim whitespace from both ends of a string
static std::string trim(const std::string& str) 
{
	size_t	start = 0;
	size_t	end;

	while (start < str.size() && std::isspace(str[start]))
		++start;
	end = str.size();
	while (end > start && std::isspace(str[end -1]))
		--end;
	return (str.substr(start, end - start));		
}


// Function to add a contact to the phonebook
void	Phonebook::add(void)
{
	std::string	str;

	str = "";
	if (_index > 7)
	{
		std::cout << "Current index: " << _index << ", Using slot: " << _index % 8 << std::endl;
		std::cout << "Warning: Overwriting info about " << this->_contacts[this->_index % 8].get_firstname() << std::endl;
	}
	this->_index = this->_index % 8;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input first name: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].set_firstname(trim(str)); 
		}
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_lastname(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_nickname(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_number(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_secret(trim(str)); 
	}
	str = "";
	this->_index++;
}
