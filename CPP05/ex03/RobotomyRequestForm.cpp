#include "RobotomyRequestForm.hpp"
#include <cstdlib>

//Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") 
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

//Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

//Copy assignment operator
RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    std::cout << "RobotomyRequestForm copy operator overload called" << std::endl;
    if (this != &other)
    {
        // Nothing to do here as all member variables are consts 
    }
    return (*this);
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

// Getters
std::string     RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

// Methods:
static int robot_fail = 0;

// Execute Method
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::cout << "^#$^*#%^%$@#^#$ << DRILLING SOUNDS >> ^#$^*#%^%$@#^#$" << std::endl;
    if (robot_fail++ % 2 == 0)
    {
        std::cout << this->getTarget() << " has been succesfully Robotomized by " << executor.getName() << std::endl;
    }
    else
    {
        std::cout << executor.getName() << " has failed Robotomization process of " << this->getTarget() << std::endl;
    }    
}

// Output operator overload to print instances of the class 
std::ostream    &operator<<(std::ostream &os, RobotomyRequestForm *robo)
{
    os << "AForm " << robo->getName() <<
    ":\n\tsign-grade:\t" << robo->getGradeToSign() <<
    "\n\texec-grade:\t" << robo->getGradeToExec() <<
    "\n\tis signed:\t" << robo->isSigned() <<
    std::endl;
    return (os);
}
