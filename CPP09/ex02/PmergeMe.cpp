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

    _vect.insert(_vect.end(), number);
}

void    PmergeMe::printVects()
{
    std::vector<int>::iterator  it;

    std::cout << "Before : ";
    for (it = _vect.begin(); it != _vect.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After : ";
    for (it = _sorted_vect.begin(); it != _sorted_vect.end(); it++)
        std::cout << *it << " ";

    std::cout << "lists: " << std::endl;
    for (std::vector<std::list<int> >::iterator it = _listsVect.begin(); it != _listsVect.end(); it++)
    {
        std::list<int>::iterator    listIt = it->begin();
        std::cout << "[ " << *(listIt) << " ";
        std::advance(listIt, 1);
    
        std::cout << *(listIt) << "]" << std::endl;
    }
}

void    PmergeMe::mergeSort()
{
    std::cout << "\nCalled mergeSort function" << std::endl;
    
    for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
    {
        if (std::distance(it, _vect.end()) > 1)
        {
            std::list<int>  lst;
            
            lst.push_back(*it);
            lst.push_back(*(it + 1));
            _listsVect.insert(_listsVect.end(), lst); // store the lists of 2 into a vect
            ++it;
        }
        if (_vect.size() % 2 != 0)
            _leftover = *(_vect.end() - 1);
    }
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