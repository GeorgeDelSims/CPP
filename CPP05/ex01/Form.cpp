#include "Form.hpp"

//Constructor
Form::Form(const std::string name, const int to_sign, const int to_exec) 
: _Name(name), _Signed(false), _GradeToSign(to_sign), _GradeToExec(to_exec) {}

//Copy constructor
Form::Form(const Form& other) : _Name(other._Name), _Signed(other._Signed), _GradeToSign(other._GradeToSign), _GradeToExec(other._GradeToExec) {}

//Copy assignment operator
Form&  Form::operator=(const Form& other) 
{
    if (this != &other)
        this->_Signed = other._Signed;
    return (*this);
}

//Destructor
Form::~Form() {}

// Methods:

const std::string   Form::getName() const
{
    return (this->_Name);
}

bool    Form::isSigned() const
{
    if (this->_Signed == true)
        return (true);
    return (false);
}

int   Form::getGradeToSign() const
{
    return (this->_GradeToSign);
}

int   Form::getGradeToExec() const
{
    return (this->_GradeToExec);
}

void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= this->_GradeToSign)
    {
        this->_Signed = true;
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
    }
    else
        throw Form::GradeTooLowException();
}

// ostream operator overload:
std::ostream&   operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", grade to sign " << form.getGradeToSign() << ", signed: " << form.isSigned() << ".";
    return (os); // Return the output stream to allow chaining (e.g., std::cout << b1 << b2;)
}

 