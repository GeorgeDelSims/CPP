#include "Serializer.hpp"

int main()
{
	Data		*ptr = new Data;
	Data		*ptr2;
	uintptr_t	serial_int;
	
	ptr->name = "Derek";
	ptr->next = NULL;

	std::cout << "ptr address : " << ptr << std::endl;
	std::cout << "ptr name : " << ptr->name << std::endl;

	serial_int = Serializer::serialize(ptr);
	std::cout << "serialized uintptr_t : " << serial_int << std::endl;

	ptr2 = Serializer::deserialize(serial_int);
	std::cout << "ptr2 address : " << ptr2 << std::endl;
	
	std::cout << "ptr2 name : " << ptr2->name << std::endl;

	delete (ptr);

	return (0);
}