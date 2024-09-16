#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
    public:
        WrongAnimal(); // constructor
        WrongAnimal(const WrongAnimal& other); //copy constructor
        WrongAnimal&  operator=(const WrongAnimal& other); // copy assignment operator
        virtual ~WrongAnimal(); // destructor 

        // Methods: 
        void            makeSound() const;
        std::string     getType() const;

    protected:
        std::string    type;
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

#endif // WrongAnimal_HPP
