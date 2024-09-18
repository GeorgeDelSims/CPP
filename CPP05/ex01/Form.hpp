#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form 
{
    public:
        Form(const std::string name, const int to_sign, const int to_exec); // constructor
        Form(const Form& other); //copy constructor
        Form&  operator=(const Form& other); // copy assignment operator
        ~Form(); // destructor 

        // Methods:
        const std::string   getName() const;
        bool                isSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;
        void                beSigned(Bureaucrat& b);

        class GradeTooHighException :  public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return  ("Grade is too high.\n");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return ("Grade is too low.\n");
            }
        };

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        const std::string   _Name;
        bool                _Signed;
        const int           _GradeToSign;
        const int           _GradeToExec;

};

std::ostream&   operator<<(std::ostream& outputStream, const Form& form);

#endif // Form_HPP
