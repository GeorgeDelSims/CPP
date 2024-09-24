#include "Array.hpp"

/*
Direct initialisation: 
    MyClass object(arguments);

Copy initialisation (what we've done up until now):
    MyClass object = MyClass(arguments);

What it looks like with templates: 

Direct initialisation: 
    Array<int>  arr(5);

Copy initialisation:
    Array<int> arr = Array<int>(5);

*/

int main()
{
    Array<int>          intArray(10);
    Array<std::string>  stringArray(5);

    try
    {
        for (unsigned int i = 0; i < 5; ++i)
            intArray[i] = (i * 10);

        for (unsigned int i = 0; i < 5; ++i)
            stringArray[i] = "Hello";

        for (unsigned int i = 0; i < 5; ++i)
            std::cout << intArray[i] << std::endl;

        std::cout << "trying to access out of bounds access.\n";
        
        for (unsigned int i = 0; i < 8; ++i)
            std::cout << stringArray[i] << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}
