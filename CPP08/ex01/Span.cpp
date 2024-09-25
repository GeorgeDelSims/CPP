#include "Span.hpp"

//Constructor
Span::Span(unsigned int N) : _maxSize(N)
{
    _vect.reserve(N);
};

//Copy constructor
Span::Span(const Span& other) : _vect(other._vect), _maxSize(other._maxSize) {}

//Copy assignment operator
Span&  Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _vect = other._vect;
        _maxSize = other._maxSize;
    }
    return (*this);
}

//Destructor
Span::~Span() {}

// Methods:

void    Span::addNumber(int number)
{
    if (_vect.size() >= _maxSize)
        throw (std::runtime_error("Span is full"));
    _vect.push_back(number);
}

int     Span::shortestSpan()
{
    if (_vect.size() < 2)
        throw (std::runtime_error("Not enough numbers to calculate span"));

    std::vector<int>     sorted = _vect;
    std::sort(sorted.begin(), sorted.end());

    int     minSpan = sorted[1] - sorted[0];           
    for (size_t i = 2; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

int     Span::longestSpan()
{
    if (_vect.size() < 2)
        throw (std::runtime_error("Not enough numbers to calculate span"));

    std::vector<int>::iterator  minInt = std::min_element(_vect.begin(), _vect.end());
    std::vector<int>::iterator  maxInt = std::max_element(_vect.begin(), _vect.end());
    
    return (*maxInt - *minInt);
}