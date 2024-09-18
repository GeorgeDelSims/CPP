#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(const std::string target); // constructor
        ShrubberyCreationForm(const ShrubberyCreationForm& other); //copy constructor
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other); // copy assignment operator
        ~ShrubberyCreationForm(); // destructor 

        // Methods: 
        std::string     getTarget() const;
        void            execute(Bureaucrat const &executor) const;

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::string     _target;

        ShrubberyCreationForm(); // Default Constructor
};

#endif // ShrubberyCreationForm_HPP
