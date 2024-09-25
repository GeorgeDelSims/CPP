#include "Phonebook.hpp"

// Function to trim whitespace from both ends of a string
static std::string trim(const std::string& str) 
{
	size_t	start = 0;
	size_t	end = str.size();

	while (start < end && (std::isspace(str[start]) || std::iscntrl(str[start])))
		++start;
	while (end > start && (std::isspace(str[end -1]) || std::iscntrl(str[end - 1])))
		--end;
	return (str.substr(start, end - start));		
}

void Phonebook::add(void)
{
    std::string str;

    str = "";
    if (_index > 7)
    {
        std::cout << "Current index: " << _index << ", Using slot: " << _index % 8 << std::endl;
        std::cout << "Warning: Overwriting info about " << this->_contacts[this->_index % 8].get_firstname() << std::endl;
    }
    this->_index = this->_index % 8;
    // Input first name
    while (!std::cin.eof())
    {
        std::cout << "Input first name: ";
        std::getline(std::cin, str);
        str = trim(str);  // Trim the input
        if (!str.empty())  // Check if trimmed string is not empty
        {
            this->_contacts[this->_index].set_firstname(str); 
            break;  // Exit loop if valid input
        }
    }
    // Input last name
    while (!std::cin.eof())
    {
        std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s last name: ";
        std::getline(std::cin, str);
        str = trim(str);
        if (!str.empty())
        {
            this->_contacts[this->_index].set_lastname(str); 
            break;
        }
    }
    // Input nickname
    while (!std::cin.eof())
    {
        std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s nickname: ";
        std::getline(std::cin, str);
        str = trim(str);
        if (!str.empty())
        {
            this->_contacts[this->_index].set_nickname(str); 
            break;
        }
    }
    // Input phone number
    while (!std::cin.eof())
    {
        std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s number: ";
        std::getline(std::cin, str);
        str = trim(str);
        if (!str.empty())
        {
            this->_contacts[this->_index].set_number(str); 
            break;
        }
    }
    // Input darkest secret
    while (!std::cin.eof())
    {
        std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s darkest secret: ";
        std::getline(std::cin, str);
        str = trim(str);
        if (!str.empty())
        {
            this->_contacts[this->_index].set_secret(str); 
            break;
        }
    }
    this->_index++;
}
