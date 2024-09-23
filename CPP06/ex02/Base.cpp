#include "Base.hpp"

//Constructor
Base::Base() {}

//Destructor
Base::~Base() {}

// Class A: 
// constructor
A::A() 
{
	std::cout << "A constructed" << std::endl;
}

// destructor: 
A::~A() 
{
	std::cout << "A destroyed" << std::endl;
}

// Class B
// constructor
B::B()
{
	std::cout << "B constructed" << std::endl;
}

// destructor 
B::~B()
{
	std::cout << "B destroyed" << std::endl;
}

// Class C
// constructor
C::C()
{
	std::cout << "C constructed" << std::endl;
}
// destructor 
C::~C()
{
	std::cout << "C destroyed" << std::endl;
}


// Other Functions: 
Base        *generate(void)
{
	int		random;
	Base	*ptr;

    random = rand();
	if (random % 3 == 0)
	{
		ptr = new A();
	}
	else if (random % 3 == 1)
	{
		ptr = new B();
	}
	else if (random % 3 == 2)
	{
		ptr = new C();
	}
	else
		ptr = NULL;
	return (ptr);
}

void        identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr)) 
        std::cout << "It's an instance of A\n";
	else if (dynamic_cast<B*>(ptr))
		std::cout << "It's an instance of B\n";
	else if (dynamic_cast<C*>(ptr))
		std::cout << "It's an instance of C\n";
	else
		std::cout << "Unknown type\n";
}

void        identify(Base& ref)
{
	try
	{
		A	a = dynamic_cast<A&>(ref);
		std::cout << "It's an instance of A\n";
	}
	catch (const std::bad_cast& e)
	{
		try
		{
			B	b = dynamic_cast<B&>(ref);
			std::cout << "It's an instance of B\n";
		}
		catch (const std::bad_cast& e)
		{
			try
			{
				C	c = dynamic_cast<C&>(ref);
				std::cout << "It's an instance of C\n";
			}
			catch (const std::bad_cast& e)
			{
				std::cout << "Caught bad_cast" << e.what() << "\n";
			}
		}
	}	
} 
