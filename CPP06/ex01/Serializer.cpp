#include "Serializer.hpp"

//Constructor
Serializer::Serializer() {}

//Copy constructor
Serializer::Serializer(const Serializer& other) 
{
	(void)other;
}

//Copy assignment operator
Serializer&  Serializer::operator=(const Serializer& other) 
{
	(void)other;
	return (*this);
}

//Destructor
Serializer::~Serializer() {}

// Methods:
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
