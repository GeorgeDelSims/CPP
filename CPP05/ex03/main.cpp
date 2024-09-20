#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat              b1 = Bureaucrat("Bob", 3);
    Bureaucrat              b2 = Bureaucrat("Barbara", 120);
    Intern                  someRandomIntern;
    AForm*                  rrf;

    rrf = someRandomIntern.makeForm("RobotomyRequest", "Barbara");
    b1.signForm(*rrf);
    b1.executeForm(*rrf);

    delete (rrf);
    
    return (0);
}