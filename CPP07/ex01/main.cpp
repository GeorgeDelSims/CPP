#include "iter.hpp"

template<typename T>
void	print(const T&	element)
{
	std::cout << element << std::endl;
}

template<typename T>
void	increment(T& element)
{
	++element;
}

int main()
{
	int						int_arr[5] = {0, 1, 2, 3, 4};
	const std::string		str_arr[5] = {"Hello", "Hola", "Ciao", "dobredan", "Hallo"};

	iter<int, void (*)(const int&)>(int_arr, 5, print);
	iter<const std::string, void (*)(const std::string&)>(str_arr, 5, print);

	iter<int, void (*)(int&)>(int_arr, 5, increment);
	std::cout << "after increment" << std::endl;
	iter<int, void (*)(const int&)>(int_arr, 5, print);

	return (0);
}
