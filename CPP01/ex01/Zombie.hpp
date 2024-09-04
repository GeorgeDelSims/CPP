#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie 
{
    public:
        Zombie(); // Constructor
        Zombie(std::string name);  //  Constructor with name 
        Zombie(const Zombie& other); // copy Constructor
        ~Zombie(); // Destructor 
        Zombie& operator=(const Zombie& other); //  Copy assignment constructor 
        
        
        void    announce(void);
        void    setName(std::string name);

    private:
        std::string     _name;
};

// Returns pointer to Zombie object allocated on the stack with new
Zombie	*newZombie(std::string name);
// Creates new Zombie stored on the heap, which announces itself
// Zombie is automatically destroyed at the end of the function scope
void	randomChump(std::string name);
// allocates N Zombie objects, initialises zombies with name
// returns pointer to the first zombie in the horde
Zombie  *zombieHorde(int N, std::string name);

#endif
