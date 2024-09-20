#include "ShrubberyCreationForm.hpp"

//Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") 
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

//Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec())
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

//Copy assignment operator
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    std::cout << "ShrubberyCreationForm copy operator overload called" << std::endl;
    if (this != &other)
    {
        // Nothing to do here as all member variables are consts 
    }
    return (*this);
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

// Getters
std::string     ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

// Methods:

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // std::ofstream outfile creates a file of name (Target_shrubbery) if it doesnt already exist
	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
    
	// loop to fill the outfile 
	for (int i = 0; i < 5; i++)
	{
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		std::endl;
	}
	outfile.close();

	std::cout << executor.getName() << " creaated a shrubbery"<< std::endl;
}

// Output operator overload to print instances of the class 
std::ostream    &operator<<(std::ostream &os, ShrubberyCreationForm *shrub)
{
    os << "AForm " << shrub->getName() <<
    ":\n\tsign-grade:\t" << shrub->getGradeToSign() <<
    "\n\texec-grade:\t" << shrub->getGradeToExec() <<
    "\n\tis signed:\t" << shrub->isSigned() <<
    std::endl;

	return (os);
}
