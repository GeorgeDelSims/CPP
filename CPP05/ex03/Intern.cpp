#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Out of Class functions : 
AForm* createShrubberyForm(const std::string& target) 
{
    return (new ShrubberyCreationForm(target));
}

AForm* createRobotomyForm(const std::string& target) 
{
    return (new RobotomyRequestForm(target));
}

AForm* createPresidentialForm(const std::string& target) 
{
    return (new PresidentialPardonForm(target));
}

//Constructor
Intern::Intern() {}

//Copy constructor
Intern::Intern(const Intern& other) 
{
	(void)other;
}

//Copy assignment operator
Intern&  Intern::operator=(const Intern& other) 
{
	(void)other;
	return (*this);
}

//Destructor
Intern::~Intern() {}

// Methods:

// Careful this method leaves a "new" instance of the form that needs to be deleted manually after. 
AForm*	Intern::makeForm(const std::string form_name, const std::string target)
{
	const std::string		forms[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm*					(*FormConstructors[])(const std::string&) = {createShrubberyForm, createRobotomyForm, createPresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			AForm*	form = FormConstructors[i](target);
			
			std::cout << "Intern creates " << form_name << std::endl;
			return (form);
		}
	}
	throw (WrongInputException());
}