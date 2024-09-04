#include "Harl.hpp"


//Constructor
Harl::Harl() {}

// Copy Constructor
Harl::Harl(const Harl& other)
{
    (void)other;
}

//Destructor
Harl::~Harl() {}

// Copy Assignment Operator
Harl& Harl::operator=(const Harl& other)
{
    if (this != &other) 
    {
        // Since there are no non-static members currently, nothing to copy
    }
    return (*this);
}

// initialising function array and level array
const std::string       Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const Harl::HarlMemFn   Harl::functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

// Methods:
void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    }
    std::cerr << "Invalid level: " << level << std:: endl;
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
