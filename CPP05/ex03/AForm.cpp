#include "AForm.hpp"

//Constructor
AForm::AForm(const std::string name, const int to_sign, const int to_exec) 
: _Name(name), _Signed(false), _GradeToSign(to_sign), _GradeToExec(to_exec) 
{
    std::cout << "Form Default Constructor called" <<  std::endl;
}

//Copy constructor
AForm::AForm(const AForm& other) : _Name(other._Name), _Signed(other._Signed), _GradeToSign(other._GradeToSign), _GradeToExec(other._GradeToExec) 
{
        std::cout << "Form Copy Constructor called" <<  std::endl;
}

//Copy assignment operator
AForm&  AForm::operator=(const AForm& other) 
{
    std::cout << "Form Copy Assignment Operator called" <<  std::endl;
    if (this != &other)
        this->_Signed = other._Signed;
    return (*this);
}

//Destructor
AForm::~AForm() 
{
    std::cout << "Form Destructor called" <<  std::endl;
}

// Methods:

// Getters: 

const std::string   AForm::getName() const
{
    return (this->_Name);
}

bool    AForm::isSigned() const
{
    if (this->_Signed == true)
        return (true);
    return (false);
}

int   AForm::getGradeToSign() const
{
    return (this->_GradeToSign);
}

int   AForm::getGradeToExec() const
{
    return (this->_GradeToExec);
}

// Other Methods: 

void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= this->_GradeToSign)
    {
        this->_Signed = true;
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
    }
    else
        throw AForm::GradeTooLowException();
}

void    AForm::performExecute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw (FormNotSignedException());
    if (executor.getGrade() > this->getGradeToExec())
        throw (GradeTooLowException());
    std::cout << executor.getName() << " executed "<< this->_Name << std::endl; 
    this->execute(executor);
}

// ostream operator overload:
std::ostream&   operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << ", grade to sign " << form.getGradeToSign() << ", signed: " << form.isSigned() << ".";
    return (os); // Return the output stream to allow chaining (e.g., std::cout << b1 << b2;)
}

 