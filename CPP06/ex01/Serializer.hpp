#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h> // otherwise uintptr_t won't compile with c++98 standard


typedef struct      Data
{
    std::string     name;
    Data            *next;
}                   Data;

class Serializer 
{
    public:
        Serializer(); // constructor
        Serializer(const Serializer& other); //copy constructor
        Serializer&  operator=(const Serializer& other); // copy assignment operator
        ~Serializer(); // destructor 

        // Methods:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
        
    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

#endif // Serializer_HPP
