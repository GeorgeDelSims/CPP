#include "Brain.hpp"

//Constructor
Brain::Brain() 
{
    std::cout << "Brain created" << std::endl;
}

//Copy constructor
Brain::Brain(const Brain& other) 
{
    *this = other;
    std::cout << "Brain copied" << std::endl;
}

//Copy assignment operator
Brain&  Brain::operator=(const Brain& other) 
{
    if (this != &other)
    {
        for (int i = 0; i < MAX_IDEAS; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

//Destructor
Brain::~Brain() 
{
    std::cout << "Brain destroyed" << std::endl;
}
