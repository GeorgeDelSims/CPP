#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

// Phonebook Class 
class Phonebook {

public: 
	Phonebook(void);
	~Phonebook(void);
	Phonebook(const Phonebook& other);
	Phonebook& operator=(const Phonebook& other);

	void	add();
	void	search();
	void	search_index(std::string str);
	void	print(Contact contact);

private:
	Contact	_contacts[8];
	int		_index;

};

#endif