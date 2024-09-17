#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat 
{
    public:
        Bureaucrat(const std::string name, int grade); // constructor
        Bureaucrat(const Bureaucrat& other); //copy constructor
        Bureaucrat&  operator=(Bureaucrat& other); // copy assignment operator
        ~Bureaucrat(); // destructor 

        // Methods: 
        int                 getGrade();
        const std::string   getName();
        void                incrementGrade();
        void                decrementGrade();

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        const std::string   _name;
        int                 _grade;

        class GradeTooHighException : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Grade is too high, maximum allowed is 150.\n");
                }
        }
        class GradeTooLowException : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Grade is too low, minimum allowed is 1.\n");
                }
        }

};

std::ostream&   operator<<(std::ostream& outputStream, int& grade);

#endif // Bureaucrat_HPP
