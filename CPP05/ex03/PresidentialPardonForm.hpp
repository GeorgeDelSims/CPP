#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string target); // constructor
        PresidentialPardonForm(const PresidentialPardonForm& other); //copy constructor
        PresidentialPardonForm&  operator=(const PresidentialPardonForm& other); // copy assignment operator
        ~PresidentialPardonForm(); // destructor 

        // Methods: 
        std::string     getTarget() const;
        void            execute(Bureaucrat const &executor) const;

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::string     _target;

        PresidentialPardonForm(); // Default Constructor
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm *pres);

#endif // PRESIDENTIALPARDONFORM_HPP
