#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>


class RPN 
{
    public:
        RPN(const std::string& inputString); // constructor
        RPN(const RPN& other); //copy constructor
        RPN&  operator=(const RPN& other); // copy assignment operator
        ~RPN(); // destructor 

        // Methods: 
        bool    is_operator(const char c);
        int     calculate(int a, int b, const char op);
        int     algoRPN();
        bool    inputCheck(const std::string& str);


        // Exceptions: 
        class BadInput : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Error: Input must be valid reverse polish notation");
                }
        };

        
    private:
        // Private member variables & utils functions:
        std::string         str;
        std::stack<int>     stk;
};

#endif // RPN_HPP
