#include "Zombie.hpp"

int	main(int ac, char *av[])
{
	int					N;
	std::stringstream	s_stream(av[1]);
	Zombie				*horde;

	if (ac < 3)
	{	
		std::cout << "You forgot to say how many zombies you want. Execute with number of zombies + name as arguments" << std::endl;
		return (0);
	}
	s_stream >> N;
	if (!N || N <= 0) 
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
