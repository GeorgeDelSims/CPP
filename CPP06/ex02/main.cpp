#include "Base.hpp"

int	main()
{
	// seed random number generator at time 0
	srand(time(0));

	Base	*whatisit = generate();
	Base	&whatref = *whatisit;

	identify(whatisit);
	identify(whatref);

	return (0);
}
