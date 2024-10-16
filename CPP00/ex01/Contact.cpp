#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

// Copy Constructor
Contact::Contact(const Contact& other)
{
    this->_firstname = other._firstname;
    this->_lastname = other._lastname;
    this->_nickname = other._nickname;
    this->_number = other._number;
    this->_secret = other._secret;
}

// Copy Assignment Operator
Contact& Contact::operator=(const Contact& other)
{
    if (this != &other) // Check for self-assignment
    {
        this->_firstname = other._firstname;
        this->_lastname = other._lastname;
        this->_nickname = other._nickname;
        this->_number = other._number;
        this->_secret = other._secret;
    }
    return (*this);
}

void	Contact::set_firstname(std::string str)
{
	this->_firstname = str;
}

void	Contact::set_lastname(std::string str)
{
	this->_lastname = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_number(std::string str)
{
	this->_number = str;
}

void	Contact::set_secret(std::string str)
{
	this->_secret = str;
}

std::string		Contact::get_firstname(void) const
{
	return (this->_firstname);
}

std::string		Contact::get_lastname(void) const
{
	return (this->_lastname);
}

std::string		Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string		Contact::get_number(void) const
{
	return (this->_number);
}

std::string		Contact::get_secret(void) const
{
	return (this->_secret);
}
