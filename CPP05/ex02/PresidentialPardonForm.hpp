#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string target); // constructor
        PresidentialPardonForm(const PresidentialPardonForm& other); //copy constructor
        PresidentialPardonForm&  operator=(const PresidentialPardonForm& other); // copy assignment operator
        ~PresidentialPardonForm(); // destructor 

        // Methods: 
    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::string     _target;
        
        PresidentialPardonForm(); 
        // Default constructor is private because Orthodox Canonical Form but also only one constructor asked for in the consigne
};

#endif // PresidentialPardonForm_HPP
