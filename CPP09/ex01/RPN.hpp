#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>

class RPN 
{
    public:
        RPN(const std::string& inputString); // constructor
        RPN(const RPN& other); //copy constructor
        RPN&  operator=(const RPN& other); // copy assignment operator
        ~RPN(); // destructor 

        // Methods: 
        bool    is_operator(char c);

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::string         rpnString;
        std::stack<char>    rpnStack;
};

#endif // RPN_HPP
