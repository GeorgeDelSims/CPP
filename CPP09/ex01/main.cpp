#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {    
        std::cout << "Wrong number of arguments: ./RPN <reverse polish notation>" << std::endl;
        return (0);
    }
    
    RPN     rpn = RPN(av[1]);

    try
    {
        int result = rpn.algoRPN();
        std::cout << "Result : " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}