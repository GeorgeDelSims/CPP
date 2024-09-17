#include "Bureaucrat.hpp"

//Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    try
    {
        if (grade > 150)
            throw (Bureaucrat::GradeTooHighException);
        else if (grade < 1)
            throw (Bureaucrat::GradeTooLowException);
        else 
            this->_grade = grade;
    }
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

//Copy assignment operator
Bureaucrat&  Bureaucrat::operator=(Bureaucrat& other) 
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    return (*this)
}

//Destructor
Bureaucrat::~Bureaucrat() {}

// Methods:
int     Bureaucrat::getGrade()
{
    return (this->_grade);
}

const std::string       Bureaucrat::getName()
{
    return (this->_name);
}

void    Bureaucrat::incrementGrade()
{
    try
    {
        ++this->_grade;
        if (this->_grade > 150)
            throw (Bureaucrat::GradeTooHighException);
    }
}

void    Bureaucrat::decrementGrade()
{
    try
    {
        --this->_grade;
        if (this->_grade < 1)
            throw(Bureaucrat:::GradeTooLowException);
    }
}
