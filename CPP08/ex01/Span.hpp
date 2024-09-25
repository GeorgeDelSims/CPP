#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <bits/stdc++.h>
#include <stdexcept>

class Span 
{
    public:
        Span(unsigned int N); // constructor
        Span(const Span& other); //copy constructor
        Span&  operator=(const Span& other); // copy assignment operator
        ~Span(); // destructor 

        // Methods:
        template <typename InputIterator>
        void    addRange(InputIterator begin, InputIterator end)
        {
            if (std::distance(begin, end) + _vect.size() > _maxSize)
                throw (std::runtime_error("Not enough space in Span to add all elements of the range."));
            _vect.insert(_vect.end(), begin, end);
        }

        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
    protected:
        // Protected member variables & utils functions:
        
    private:
        std::vector<int>    _vect;
        unsigned int        _maxSize;
        // Private member variables & utils functions:
};

#endif // Span_HPP
