#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void	iter(T	*array, std::size_t length, F	func)
{
	for (std::size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

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


#endif