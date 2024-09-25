#include "Span.hpp"

int main()
{
    int                 range = 10000;
    Span                span1 = Span(range);
    std::vector<int>    randomNumbers;

    // seed random number generator to time(0)
    srand(time(0));
    for (int i = 0; i < range; ++i)
    {
        randomNumbers.push_back(rand());
    }
    
    try
    {
        span1.addRange(randomNumbers.begin(), randomNumbers.end());
        std::cout << "longest span : " << span1.longestSpan() << std::endl;
        std::cout << "shortest span : " << span1.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception thrown : " << e.what() << std::endl;
    }
    return (0);
}