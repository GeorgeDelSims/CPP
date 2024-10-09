#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>

class PmergeMe 
{
    public:
        PmergeMe(); // constructor
        PmergeMe(const PmergeMe& other); //copy constructor
        PmergeMe&  operator=(const PmergeMe& other); // copy assignment operator
        ~PmergeMe(); // destructor 

        // Methods: 
        void    add_number(const char *num);
        void    Deque_add_number(const char *num);
        void    printVects();
        void    printDeqs();
        void    createPairs();
        void    Deque_createPairs();        
        void    sortPairs();
        void    preSortLists();
        void    addLargerElements();
        void    binarySearchInsert();
        void    Deque_sortPairs();
        void    Deque_preSortLists();
        void    Deque_addLargerElements();
        void    Deque_binarySearchInsert();
        void    sortElementsVect();
        void    sortElementsDeque();
        
        
    private:
        // Private member variables & utils functions:
        std::vector<int>                _vect;
        std::vector<int>                _sorted_vect;
        std::vector<std::list<int> >    _pairs;

        std::deque<int>                 _deq;
        std::deque<int>                 _sorted_deque;
        std::deque<std::list<int> >     _deqPairs;

        int                             _isUneven;
        int                             _leftover;
        int                             _DequeisUneven;
        int                             _Dequeleftover;
};

#endif // PmergeMe_HPP
