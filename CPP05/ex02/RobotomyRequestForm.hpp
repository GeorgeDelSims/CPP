#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string name, const int to_sign, const int to_exec); // constructor
        RobotomyRequestForm(const RobotomyRequestForm& other); //copy constructor
        RobotomyRequestForm&  operator=(const RobotomyRequestForm& other); // copy assignment operator
        ~RobotomyRequestForm(); // destructor 

        // Methods: 
    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

#endif // RobotomyRequestForm_HPP
