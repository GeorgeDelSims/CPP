#include "PmergeMe.hpp"

//Constructor
PmergeMe::PmergeMe() {}

//Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vect(other._vect), _sorted_vect(other._sorted_vect) {}

//Copy assignment operator
PmergeMe&  PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other)
    {
        this->_vect = other._vect;
        this->_sorted_vect = other._sorted_vect;
    }
    return (*this);
}

//Destructor
PmergeMe::~PmergeMe() {}

// Methods:

void    PmergeMe::add_number(const char *num)
{
    int     number = atoi(num);

    this->_vect.insert(this->_vect.end(), number);
}

void    PmergeMe::printVects()
{
    std::vector<int>::iterator  it;

    std::cout << "Before : ";
    for (it = this->_vect.begin(); it != this->_vect.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After : ";
    for (it = this->_sorted_vect.begin(); it != this->_sorted_vect.end(); it++)
        std::cout << *it << " ";
}

void    PmergeMe::mergeSort()
{
    std::cout << "\nCalled mergeSort function" << std::endl;
    

}


/*
Merge Sort: 

- Group elements into pairs, leaving one unpaired if the number of elements is odd.
- Compare each pair and keep the larger elements.
- Recursively sort the larger elements.
- Insert the unpaired element into the sorted sequence.
- Insert the remaining smaller elements using binary search to find the correct position.


std::list<std::pair<int, int>> for the tuples (pairs of elements):
This container is good for handling pairs of elements that need to be processed.

std::vector<int> for the sorted sequence:
This container is ideal for binary search-based insertion and maintaining the final sorted array.


*/