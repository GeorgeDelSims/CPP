#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat 
{
    public:
        Bureaucrat(const std::string name, int grade); // constructor
        Bureaucrat(const Bureaucrat& other); //copy constructor
        Bureaucrat&  operator=(const Bureaucrat& other); // copy assignment operator
        ~Bureaucrat(); // destructor 

        // Methods: 
        int                 getGrade() const;
        const std::string&  getName() const;
        void                incrementGrade();
        void                decrementGrade();
        void                signForm(Form& form);

        // Protected member variables & utils functions:
        
        class GradeTooHighException : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Grade is too high, maximum allowed is 1.\n");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Grade is too low, minimum allowed is 150.\n");
                }
        };

    protected:
    
    private:
        // Private member variables & utils functions:
        const std::string   _Name;
        int                 _Grade;
};

std::ostream&   operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);

#endif // Bureaucrat_HPP
