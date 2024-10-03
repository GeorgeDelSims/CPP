#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>


/*
MutantStack inherits from std::stack 
by default, std::stack uses std::deque as its underlying container
*/

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(); // constructor
        ~MutantStack(); // destructor 
        MutantStack(const MutantStack& other); //copy constructor
        MutantStack&  operator=(const MutantStack<T>& other); // copy assignment operator

        typedef typename std::stack<T>::container_type  under_ctr;
        typedef typename under_ctr::iterator            iterator;
        typedef typename under_ctr::const_iterator      const_iterator;
        typedef typename under_ctr::iterator            rev_iterator;
        typedef typename under_ctr::const_iterator      rev_const_iterator;

        // Methods: 
        iterator        begin();
        iterator        end();
        const_iterator  begin() const;
        const_iterator  end() const;
        iterator        rbegin();
        iterator        rend();
        const_iterator  rbegin() const;
        const_iterator  rend() const;


    protected:
        // Protected member variables & utils functions:
        // a std::stack container always has a protected member variable called c.
        // No need to declare it , it is inherited directly from std::stack 
        // it refers to the (underlying) container that actully holds the stack elements. 
        
    private:
        // Private member variables & utils functions:
};

#include "MutantStack.tpp"

#endif // MutantStack_HPP
