#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "please provide a range of numbers to sort." << std::endl;
        return (0);
    }
    PmergeMe    pmm = PmergeMe();
    for (int i = 1; i < ac; i++)
    {
        pmm.add_number(av[i]);
        pmm.Deque_add_number(av[i]);
    }
    pmm.sortElementsVect();
    pmm.sortElementsDeque();
    return (0);
}