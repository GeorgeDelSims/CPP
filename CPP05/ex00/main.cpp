#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat      b1 = Bureaucrat("Bob", 3);
        b1.incrementGrade();
        std::cout << b1 << std::endl;
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
        Bureaucrat      b2 = Bureaucrat("Barry", -1);
        b2.decrementGrade();
        std::cout << b2 << std::endl;
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
        Bureaucrat      b3 = Bureaucrat("Gazza", 149);
        b3.decrementGrade();
        std::cout << b3 << std::endl;
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
        Bureaucrat      b4 = Bureaucrat("Melody", 14);
        std::cout << b4 << std::endl;
        b4.incrementGrade();
        Bureaucrat      b5 = Bureaucrat(b4);
        std::cout << b5 << std::endl;
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