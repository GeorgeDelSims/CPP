#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat      b1 = Bureaucrat("Bob", 3);
    Form            f1 = Form("The_Big_One", 1, 1);
    Form            f2 = Form("The_Not_So_Big_One", 15, 10);
        
    try
    {
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f2);
    }
    catch (const Bureaucrat::GradeTooHighException& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }    

    try
    {
        Bureaucrat      b2 = Bureaucrat("Leonie", 1);
        std::cout << b2 << std::endl;
        b2.signForm(f1);
        b2.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}