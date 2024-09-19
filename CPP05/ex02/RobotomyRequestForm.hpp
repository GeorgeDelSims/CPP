#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string target); // constructor
        RobotomyRequestForm(const RobotomyRequestForm& other); //copy constructor
        RobotomyRequestForm&  operator=(const RobotomyRequestForm& other); // copy assignment operator
        ~RobotomyRequestForm(); // destructor 

        // Methods: 
        std::string     getTarget() const;
        void            execute(Bureaucrat const &executor) const;

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::string     _target;

        RobotomyRequestForm(); // Default Constructor
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm *robo);

#endif // ROBOTOMYREQUESTFORM_HPP
