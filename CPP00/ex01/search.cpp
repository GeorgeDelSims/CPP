#include "Phonebook.hpp"

// Function that shortens the string to the max width given
static std::string truncate(const std::string &str, const int width)
{
	if ((int)str.length() > width)
		return (str.substr(0, width - 1)) + ".";
	return (str);
}

void	Phonebook::search(void)
{
	const int	width = 10;
	int			i;

	std::cout << " | " << std::setw(width) << std::right << "Index" << " | "
					<< std::setw(width) << std::right << "First Name" << " | "
					<< std::setw(width) << std::right << "Last Name" << " | "
					<< std::setw(width) << std::right << "Nickame" << " | " << std::endl;
	std::cout << std::string((width + 4) * 4, '-') << std::endl;
	
	for (i = 0; i < 8; i++)
	{
		std::cout << " | " << std::setw(width) << std::right << i << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_firstname(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_lastname(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_nickname(), width) << " | " << std::endl;
	}
	return ;
}

bool is_numeric(const std::string &str) 
{
    size_t		i;

	for (i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i])) 
            return (false); 
    }
    return (true);
}


void	Phonebook::search_index(std::string str)
{
	int					index;

    while (1) 
	{
        if (is_numeric(str)) 
		{
	        std::stringstream ss(str);
            ss >> index; 
	        if (index >= 0 && index <= 7) 
			    break;
        }
		std::cout << "Enter a valid index (0 to 7): ";
        std::getline(std::cin, str);
    }
	std::cout << "Index : " << index << std::endl;
	std::cout << "First Name : " << this->_contacts[index].get_firstname() << std::endl;
	std::cout << "Last Name : " << this->_contacts[index].get_lastname() << std::endl;
	std::cout << "Nickname : " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->_contacts[index].get_number() << std::endl;
	std::cout << "Darkest Secret : " << this->_contacts[index].get_secret() << std::endl;
}
