#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm 
{
    public:
        AForm(const std::string name, const int to_sign, const int to_exec); // constructor
        AForm(const AForm& other); //copy constructor
        AForm&  operator=(const AForm& other); // copy assignment operator
        virtual ~AForm(); // destructor 

        // Getters:
        virtual const std::string   getName() const;
        virtual bool                isSigned() const;
        virtual int                 getGradeToSign() const;
        virtual int                 getGradeToExec() const;
        
        // Public Methods
        virtual void                beSigned(Bureaucrat& b);
        virtual void                execute(Bureaucrat const &executor) const = 0;
        // Non-virtual method to handle common execution conditions
        void                        performExecute(Bureaucrat const &executor) const;

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

        class FormNotSignedException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return ("Form not signed\n");
            }
        };

    protected:
        // Protected member variables & utils functions:
        const std::string   _Name;
        bool                _Signed;
        const int           _GradeToSign;
        const int           _GradeToExec;

    private:
        // Private member variables & utils functions:
};

std::ostream&   operator<<(std::ostream& outputStream, const AForm& form);

#endif // Form_HPP
