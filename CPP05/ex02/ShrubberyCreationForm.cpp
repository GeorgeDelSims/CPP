#include "ShrubberyCreationForm.hpp"

//Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default") {}

//Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(_target) 
{

    
}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {}

//Copy assignment operator
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Methods:
