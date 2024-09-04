#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

class Megaphone {

public: 

	char *str;

	Megaphone(char *str_input);
	~Megaphone();
    Megaphone(const Megaphone& other);               // Copy Constructor
    Megaphone& operator=(const Megaphone& other);    // Copy Assignment Operator

}


#endif