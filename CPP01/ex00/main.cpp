#include "Zombie.hpp"

int	main()
{
	Zombie	*z;
	
	z = newZombie("Jean-Michel");
	z->announce();
	delete (z);
	randomChump("Patrick");
	randomChump("Benoit");
	return (0);
}
