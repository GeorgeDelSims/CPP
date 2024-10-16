#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        this->_grade = grade;
    std::cout << "Bureaucrat Constructor called for " << this->getName() << " with grade " << this->getGrade() << "\n";
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) 
{
    std::cout << "Bureaucrat Copy Constructor called for " << this->getName() << " with grade " << this->getGrade() << "\n";
}

//Copy assignment operator
Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other)
    {
        if (other._grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (other._grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else 
            this->_grade = other._grade;
    }
    return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat() {}


// Methods:
int     Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string&       Bureaucrat::getName() const
{
    return (this->_name);
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else
        --this->_grade;
    std::cout << "Grade incremented" << "\n";
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        ++this->_grade;
    std::cout << "Grade decremented" << "\n";
}

// ostream operator overload:
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os); // Return the output stream to allow chaining (e.g., std::cout << b1 << b2;)
}
