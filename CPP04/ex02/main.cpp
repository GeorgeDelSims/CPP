#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    int         i = 0;
    AAnimal*    zoo[ANIMALS];
    // AAnimal     Tier;

    // Tier.makeSound();
    while (i < ANIMALS)
    {
        if (i % 2 == 0)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
        i++;
    }
    for (int j = 0;  j < ANIMALS; j++)
        zoo[j]->makeSound();
    for (int j = 0;  j < ANIMALS; j++)
        delete zoo[j];
    return (0);
}
