#include "Phonebook.hpp"

//Constructor
Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Welcome to phonebook, feel free to add your contacts" << std::endl;
	return ;
}

//Destructor
Phonebook::~Phonebook(void)
{
	std::cout << "Arrivederci" << std::endl;
	return ;
}

//Copy Constructor
Phonebook::Phonebook(const Phonebook& other)
{
	this->_contacts[8] = other._contacts[8];
	this->_index = other._index;
}

// Copy Assignment Operator
Phonebook&	Phonebook::operator=(const Phonebook& other)
{
	if (this != &other)
	{
		this->_contacts[8] = other._contacts[8];
		this->_index = other._index;
	}
	return (*this);
}
