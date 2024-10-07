#include "RPN.hpp"


//Constructor
RPN::RPN(const std::string& inputString) : rpnString(inputString)
{
    try
    {
        for (std::size_t i = 0; i < rpnString.length(); i++)
        {
            if (std::isdigit(rpnString[i]) || this->is_operator(rpnString[i]))
                rpnStack.push(rpnString[i]);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error: Bad input" << e.what() << std::endl;
    }
}

//Copy constructor
RPN::RPN(const RPN& other) : rpnString(other.rpnString), rpnStack(other.rpnStack) {}

//Copy assignment operator
RPN&  RPN::operator=(const RPN& other) 
{
    if (this != &other)
    {
        this->rpnStack = other.rpnStack;
        this->rpnString = other.rpnString;
    }
    return (*this);
}

//Destructor
RPN::~RPN() {}

// Methods:

bool    RPN::is_operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int     RPN::calculate()
{
    char    c;
    char    temp_op;

    for (std::size_t i = 0; i < this->rpnString.length(); ++i)
    {
        c = this->rpnStack.pop();
        if (this->is_operator(c)) // if first element is operator
        {
            while (this->is_operator(this->rpnStack.top())) // while next element is operator
            {

            }
        }
    }
}