#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal            *a = new Animal();
    const Animal            *b = new Dog();
    const Animal            *c = new Cat();
    const WrongAnimal       *d = new WrongCat();

    std::cout << "animal a is a "<< a->getType() << std::endl;
    std::cout << "animal b is a "<< b->getType() << std::endl;
    std::cout << "animal c is a "<< c->getType() << std::endl;
    std::cout << "animal d is a "<< d->getType() << std::endl;
    
    c->makeSound(); //will output the cat sound!
    b->makeSound(); // will output dog sound
    a->makeSound(); // will output animal sound 
    d->makeSound(); // will output wronganimal sound

    delete a;
    delete b;
    delete c;
    delete d;
    
    return(0);
}
