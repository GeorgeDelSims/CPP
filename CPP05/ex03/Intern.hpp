#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm*  createShrubberyForm(const std::string& target);
AForm*  createRobotomyForm(const std::string& target);
AForm*  createPresidentialForm(const std::string& target);

class Intern 
{
    public:
        Intern(); // constructor
        Intern(const Intern& other); //copy constructor
        Intern&  operator=(const Intern& other); // copy assignment operator
        ~Intern(); // destructor 

        // Methods: 
        AForm*  makeForm(const std::string form_name, const std::string target);

        class WrongInputException : std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Incorrect form name\n");
                }
        };
        
    protected:
    private:
};

#endif // Intern_HPP
