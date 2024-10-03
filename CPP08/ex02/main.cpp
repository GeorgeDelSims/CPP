#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int>    mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    std::cout << "Elements in MutantStack (using forward iterator):" << std::endl;

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Elements in MutantStack (using reverse iterator):" << std::endl;

    for (MutantStack<int>::rev_iterator it = mstack.end() - 1; it != mstack.begin() - 1; --it)
        std::cout << *it << std::endl;

    return (0);
}
