#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cout << "Wrong number of arguments: ./RPN <reverse polish notation>" << std::endl;
    
    RPN     rpn = RPN(av[1]);
    
    

    return (0);
}