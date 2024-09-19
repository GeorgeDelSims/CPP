#include "PresidentialPardonForm.hpp"

//Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137), _target("default") 
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

//Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target) 
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

//Copy assignment operator
PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
    std::cout << "PresidentialPardonForm copy operator overload called" << std::endl;
    if (this != &other)
    {
        // Nothing to do here as all member variables are consts 
    }
    return (*this);
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// Getters
std::string     PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}


// Methods:
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox using the " << this->getTarget() << " form." << std::endl;
}

// Output operator overload to print instances of the class 
std::ostream    &operator<<(std::ostream &os, PresidentialPardonForm *pres)
{
    os << "AForm " << pres->getName() <<
    ":\n\tsign-grade:\t" << pres->getGradeToSign() <<
    "\n\texec-grade:\t" << pres->getGradeToExec() <<
    "\n\tis signed:\t" << pres->isSigned() <<
    std::endl;

    return  (os);
}
