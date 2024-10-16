#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon 
{
    public:
        Weapon(std::string type); // Constructor
        Weapon(const Weapon& other); // Copy Constructor
        ~Weapon(); // Destructor 
        Weapon& operator=(const Weapon& other); // Copy Assignment Operator

        // Add methods here
        std::string     getType();
        void            setType(std::string type);

    private:
        // Add member variables here
        std::string     _type;
};

#endif // Weapon_HPP
