#include "RPN.hpp"


//Constructor
RPN::RPN(const std::string& inputString) : str(inputString)
{

    for (std::size_t i = 0; i < str.length(); i++)
    {
        if (!(std::isdigit(str[i])) && !(this->is_operator(str[i])))
            throw (RPN::BadInput());
    }
}

//Copy constructor
RPN::RPN(const RPN& other) : str(other.str), stk(other.stk) {}

//Copy assignment operator
RPN&  RPN::operator=(const RPN& other) 
{
    if (this != &other)
    {
        this->stk = other.stk;
        this->str = other.str;
    }
    return (*this);
}

//Destructor
RPN::~RPN() {}

// Methods:

bool    RPN::is_operator(const char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int     RPN::calculate(int a, int b, const char op)
{
    if (op == '+')
        return (b + a);
    else if (op == '-')
        return (b - a);
    else if (op == '*')
        return (b * a);
    else if (op == '/')
        return (b / a);
    else
        throw (RPN::BadInput());
}   

int     RPN::algoRPN()
{
    int    a;
    int    b;

    for (std::size_t i = 0; i < this->str.length(); ++i)
    {

        if (std::isdigit(this->str[i]))
        {
            stk.push(this->str[i] - '0');
        }
        else if (RPN::is_operator(this->str[i]))
        {
            if (stk.size() < 2)
                throw (RPN::BadInput());
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(this->calculate(a, b, this->str[i]));
        }
    }
    if (stk.size() != 1)
        throw (RPN::BadInput());
    return (this->stk.top());
}