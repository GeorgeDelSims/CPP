
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
