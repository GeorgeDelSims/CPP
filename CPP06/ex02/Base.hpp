#ifndef BASE_HPP
# define BASE_HPP

#include <string>
#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <typeinfo>

class Base 
{
    public:
        Base(); // constructor
        virtual ~Base(); // destructor 

        // Methods: 
    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

class A : public Base 
{
    public:
        A();
        ~A();
};

class B : public Base 
{
    public:
        B();
        ~B();
};

class C : public Base 
{
    public:
        C();
        ~C();
};

// Functions: 
Base        *generate(void);
void        identify(Base* ptr);
void        identify(Base& ref);

#endif // Base_HPP
