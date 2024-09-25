#include "easyfind.hpp"

int main()
{
    int                 arr1[] = {1, 2, 3, 4, 5};
    int                 arr2[] = {10, 20, 30, 40, 50};
    std::vector<int>    vect(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    std::list<int>      lst(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    try
    {
        std::vector<int>::iterator  vectit = easyfind(vect, 3);
        std::cout << "Found in vector " << *vectit << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try 
    {
        std::list<int>::iterator    lstit = easyfind(lst, 23);
        std::cout << "Found in list " << *lstit << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}