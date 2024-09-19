#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat             b1 = Bureaucrat("Bob", 3);
    Bureaucrat             b2 = Bureaucrat("Barry", 120);
    Bureaucrat             b3 = Bureaucrat("Barbara", 36);
    AForm*                 f1 = new ShrubberyCreationForm("make-me-a-shrubbery");
    AForm*                 f2 = new PresidentialPardonForm("Pardon-me-bro");
    AForm*                 f3 = new RobotomyRequestForm("i-wanna-be-robotomized");

    b1.signForm(*f1);
    b1.executeForm(*f1);

    b2.signForm(*f2);
    b2.executeForm(*f2);
    
    b3.signForm(*f3);
    for (int i = 0; i < 5; i++)
        b3.executeForm(*f3);
    
    delete (f1);
    delete (f2);
    delete (f3);

    return (0);
}