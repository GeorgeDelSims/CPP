#include "Bureaucrat.hpp"
#include "AForm.hpp"

//Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _Name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        this->_Grade = grade;
    std::cout << "Bureaucrat Constructor called for " << this->getName() << " with grade " << this->getGrade() << "\n";
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _Name(other._Name), _Grade(other._Grade) 
{
    std::cout << "Bureaucrat Copy Constructor called for " << this->getName() << " with grade " << this->getGrade() << "\n";
}

//Copy assignment operator
Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other)
    {
        if (other._Grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (other._Grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else 
            this->_Grade = other._Grade;
    }
    return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat() {}


// Getters:
int     Bureaucrat::getGrade() const
{
    return (this->_Grade);
}

const std::string&       Bureaucrat::getName() const
{
    return (this->_Name);
}

// Methods:
void    Bureaucrat::incrementGrade()
{
    if (this->_Grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else
        --this->_Grade;
    std::cout << "Grade incremented" << "\n";
}

void    Bureaucrat::decrementGrade()
{
    if (this->_Grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else
        ++this->_Grade;
    std::cout << "Grade decremented" << "\n";
}

void    Bureaucrat::signForm(AForm& form)
{
    if (form.isSigned() != true)
    {
        if (this->_Grade <= form.getGradeToSign())
            form.beSigned(*this);
        else
            std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << this->getName() << "'s grade is too low\n";
    }
    else
        std::cout << form.getName() << " has already been signed\n";
}

void    Bureaucrat::executeForm(AForm& form)
{
    try
    {
        form.performExecute(*this);
    }
    catch (const std::exception &e) 
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

// ostream operator overload:
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os); // Return the output stream to allow chaining (e.g., std::cout << b1 << b2;)
}
