#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
    public:

        Zombie(std::string name);
        Zombie(const Zombie& other);
        ~Zombie();
        Zombie& operator=(const Zombie& other);
        
        void    announce(void);

    private:
        std::string     _name;
};

// Returns pointer to Zombie object allocated on the stack with new
Zombie	*newZombie(std::string name);
// Creates new Zombie stored on the heap, which announces itself
// Zombie is automatically destroyed at the end of the function scope
void	randomChump(std::string name);

#endif
