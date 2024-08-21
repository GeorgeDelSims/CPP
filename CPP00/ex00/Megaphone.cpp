#include <iostream>
#include <string>
#include <cctype>

unsigned char to_upper(unsigned char c) 
{
    return std::toupper(c);
}

int	main (int ac, char *av[])
{
	int				i;
	size_t			j;
	std::string		concatenated_str;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < ac; ++i)
		{	
			concatenated_str += av[i];
			if (std::concatenated_str.back() != ' ')
				concatenated_str += " ! ";
		}
	}
	
	for(j = 0; j < concatenated_str.length(); ++j)
	{
		concatenated_str[j] = std::toupper(static_cast<unsigned char>(concatenated_str[j]));
	}

    std::cout << concatenated_str << std::endl;

	return (0);
}
