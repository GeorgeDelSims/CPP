#include "Zombie.hpp"

int	main(int ac, char *av[])
{
	int					N;
	Zombie				*horde;

	if (ac < 3)
	{	
		std::cout << "You forgot to say how many zombies you want. Execute with number of zombies + name as arguments" << std::endl;
		return (0);
	}
	std::stringstream	ss(av[1]);
	ss >> N;
	if (!ss || !N || N <= 0) 
	{
        std::cout << "Invalid number of zombies. Please enter a valid positive integer." << std::endl;
        return (1);
    }
	horde = zombieHorde(N, av[2]);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);
}
