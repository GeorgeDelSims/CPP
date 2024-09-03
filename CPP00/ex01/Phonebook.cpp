#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Welcome to phonebook, feel free to add your contacts" << std::endl;
	return ;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Arrivederci" << std::endl;
	return ;
}
