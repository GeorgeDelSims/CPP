#include "MutantStack.hpp"

//Constructor
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

//Copy constructor
template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

//Copy assignment operator
template<typename T>
MutantStack<T>&  MutantStack<T>::operator=(const MutantStack& other) 
{
    // Just uses the assignment operator of std::stack (parent class (or underlying container)) 
    if (this != &other)
        std::stack<T>::operator=(other);
    return (*this);
}

//Destructor
template<typename T>
MutantStack<T>::~MutantStack() {}


// Methods:

/*
MutantStack inherits from std::stack: 
It uses the stack's internal container but exposes 
iterators to allow for element traversal.

std::stack does not natively allow element iteration. 
MutantStack bridges that gap by exposing the underlying container's iterators, 
making it possible to traverse the stack's elements.

*/

template<typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator  MutantStack<T>::begin() const
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (std::stack<T>::end());
}

template<typename T>
typename MutantStack<T>::rev_iterator    MutantStack<T>::rbegin()
{
    return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::rev_iterator    MutantStack<T>::rend()
{
    return (std::stack<T>::c.rend());
}

template<typename T>
typename MutantStack<T>::rev_const_iterator  MutantStack<T>::rbegin() const
{
    return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::rev_const_iterator MutantStack<T>::rend() const
{
    return (std::stack<T>::rend());
}

