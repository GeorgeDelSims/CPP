#include "PmergeMe.hpp"

//Constructor
PmergeMe::PmergeMe() {}

//Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _vect(other._vect), _sorted_vect(other._sorted_vect), _pairs(other._pairs), _deq(other._deq), _sorted_deque(other._sorted_deque), _deqPairs(other._deqPairs), _isUneven(other._isUneven), _leftover(other._leftover), _DequeisUneven(other._DequeisUneven), _Dequeleftover(other._Dequeleftover) {}

//Copy assignment operator
PmergeMe&  PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other)
    {
        this->_vect = other._vect;
        this->_sorted_vect = other._sorted_vect;
        this->_pairs = other._pairs;
        this->_deq = other._deq;
        this->_sorted_deque = other._sorted_deque;
        this->_deqPairs = other._deqPairs;
        this->_isUneven = other._isUneven;
        this->_leftover = other._leftover;
        this->_DequeisUneven = other._DequeisUneven;
        this->_Dequeleftover = other._Dequeleftover;
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
/*
    std::cout << "\nlists: " << std::endl;
    for (std::vector<std::list<int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
    {
        std::list<int>::iterator    listIt = it->begin();
        std::cout << "[ " << *(listIt) << " ";
        std::advance(listIt, 1);
    
        std::cout << *(listIt) << "]" << std::endl;
    }
*/
}

void    PmergeMe::createPairs()
{    
    for (std::vector<int>::iterator it = _vect.begin(); it != _vect.end(); it++)
    {
        if (std::distance(it, _vect.end()) > 1)
        {
            std::list<int>  lst;
            
            lst.push_back(*it);
            lst.push_back(*(it + 1));
            _pairs.insert(_pairs.end(), lst); // store the lists of 2 into a vect
            ++it;
        }
        if (_vect.size() % 2 != 0)
        {
            _isUneven = 1;
            _leftover = *(_vect.end() - 1);
        }
        else
            _isUneven = 0;
    }
}

// make the highest number of the pair always be the first 
void    PmergeMe::sortPairs()
{
    for (std::vector<std::list<int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
    {
        std::list<int>::iterator    first = it->begin();
        std::list<int>::iterator    second = it->begin();
        std::advance(second, 1);

        if (*first < *second)
        {
            int temp;

            temp = *first;
            *first = *second;
            *second = temp;
        }
    }
}

// compare pairs according to their first element
static bool    compareFirstElement(const std::list<int>& a, const std::list<int>& b)
{
    return (a.front() < b.front());
}

// switches them if previous element is larger
void    PmergeMe::preSortLists()
{
    std::sort(_pairs.begin(), _pairs.end(), compareFirstElement);
}

// Recursively insert values according to binary search algorithm
static void     recBinSearchInsert(std::vector<int>& vect, int left, int right, int num)
{
    if (left >= right)
    {
        vect.insert(vect.begin() + left, num);
        return ;
    }

    int     mid = left + ((right - left) / 2);
    
    if (vect[mid] == num)
    {
        vect.insert(vect.begin() + mid, num);
        return ;
    }
    else if (vect[mid] < num)
        recBinSearchInsert(vect, mid + 1, right, num);
    else
        recBinSearchInsert(vect, left, mid, num);

}

void    PmergeMe::addLargerElements()
{
    for (std::vector<std::list<int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
    {
        _sorted_vect.push_back(*(it->begin()));
    }
    if (_isUneven == 1)
        recBinSearchInsert(_sorted_vect, 0, _sorted_vect.size(), _leftover);
}

// call recursive binary search function for second value of each list
void    PmergeMe::binarySearchInsert()
{
    for (std::vector<std::list<int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++)
    {
        std::list<int>::iterator    listIt = it->begin();
        std::advance(listIt, 1); // Make sure that iterator is always accessing second value of list
        int secondValue = *listIt;

        if (_sorted_vect.empty())
            _sorted_vect.push_back(secondValue);
        else
            recBinSearchInsert(_sorted_vect, 0, _sorted_vect.size(), secondValue);
    }
}


/* --------------------  DEQUE IMPLEMENTATION --------------------*/


void    PmergeMe::Deque_add_number(const char *num)
{
    int     number = atoi(num);

    _deq.insert(_deq.end(), number);
}

void    PmergeMe::printDeqs()
{
    std::deque<int>::iterator  it;

    std::cout << "Before : ";
    for (it = _deq.begin(); it != _deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After : ";
    for (it = _sorted_deque.begin(); it != _sorted_deque.end(); it++)
        std::cout << *it << " ";
}

void    PmergeMe::Deque_createPairs()
{    
    for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++)
    {
        if (std::distance(it, _deq.end()) > 1)
        {
            std::list<int>  lst;
            
            lst.push_back(*it);
            lst.push_back(*(it + 1));
            _deqPairs.insert(_deqPairs.end(), lst); // store the lists of 2 into a deq
            ++it;
        }
        if (_deq.size() % 2 != 0)
        {
            _DequeisUneven = 1;
            _Dequeleftover = *(_deq.end() - 1);
        }
        else
            _DequeisUneven = 0;
    }
}

// make the highest number of the pair always be the first 
void    PmergeMe::Deque_sortPairs()
{
    for (std::deque<std::list<int> >::iterator it = _deqPairs.begin(); it != _deqPairs.end(); it++)
    {
        std::list<int>::iterator    first = it->begin();
        std::list<int>::iterator    second = it->begin();
        std::advance(second, 1);

        if (*first < *second)
        {
            int temp;

            temp = *first;
            *first = *second;
            *second = temp;
        }
    }
}

// compare pairs according to their first element
static bool    DequecompareFirstElement(const std::list<int>& a, const std::list<int>& b)
{
    return (a.front() < b.front());
}

// switches them if previous element is larger
void    PmergeMe::Deque_preSortLists()
{
    std::sort(_deqPairs.begin(), _deqPairs.end(), DequecompareFirstElement);
}

// Recursively insert values according to binary search algorithm
static void     Deque_recBinSearchInsert(std::deque<int>& deq, int left, int right, int num)
{
    if (left >= right)
    {
        deq.insert(deq.begin() + left, num);
        return ;
    }

    int     mid = left + ((right - left) / 2);
    
    if (deq[mid] == num)
    {
        deq.insert(deq.begin() + mid, num);
        return ;
    }
    else if (deq[mid] < num)
        Deque_recBinSearchInsert(deq, mid + 1, right, num);
    else
        Deque_recBinSearchInsert(deq, left, mid, num);

}

void    PmergeMe::Deque_addLargerElements()
{
    for (std::deque<std::list<int> >::iterator it = _deqPairs.begin(); it != _deqPairs.end(); it++)
    {
        _sorted_deque.push_back(*(it->begin()));
    }
    if (_DequeisUneven == 1)
        Deque_recBinSearchInsert(_sorted_deque, 0, _sorted_deque.size(), _leftover);
}

// call recursive binary search function for second value of each list
void    PmergeMe::Deque_binarySearchInsert()
{
    for (std::deque<std::list<int> >::iterator it = _deqPairs.begin(); it != _deqPairs.end(); it++)
    {
        std::list<int>::iterator    listIt = it->begin();
        std::advance(listIt, 1); // Make sure that iterator is always accessing second value of list
        int secondValue = *listIt;

        if (_sorted_deque.empty())
            _sorted_deque.push_back(secondValue);
        else
            Deque_recBinSearchInsert(_sorted_deque, 0, _sorted_deque.size(), secondValue);
    }
}


/* ------------------------FINAL FUNCTIONS --------------------------*/

void    PmergeMe::sortElementsVect()
{
    clock_t     start = clock();

    createPairs();
    sortPairs();
    preSortLists();
    addLargerElements();
    binarySearchInsert();
    printVects();
    clock_t     end = clock();

    double      elapsed_time_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "\n\nTime to process range of " << _vect.size() << " elements with std::vector : " << elapsed_time_ms << " ms" << std::endl;
}

void    PmergeMe::sortElementsDeque()
{
    clock_t     start = clock();

    Deque_createPairs();
    Deque_sortPairs();
    Deque_preSortLists();
    Deque_addLargerElements();
    Deque_binarySearchInsert();
    // printDeqs();
    clock_t     end = clock();

    double      elapsed_time_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "\nTime to process range of " << _deq.size() << " elements with std::deque : " << elapsed_time_ms << " ms" << std::endl;
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