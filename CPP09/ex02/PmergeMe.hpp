#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

class PmergeMe 
{
    public:
        PmergeMe(); // constructor
        PmergeMe(const PmergeMe& other); //copy constructor
        PmergeMe&  operator=(const PmergeMe& other); // copy assignment operator
        ~PmergeMe(); // destructor 

        // Methods: 
        void    add_number(const char *num);
        void    printVects();
        void    mergeSort();

    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        std::vector<int>    _vect;
        std::vector<int>    _sorted_vect;
};

#endif // PmergeMe_HPP
