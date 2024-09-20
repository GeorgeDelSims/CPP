#include "ScalarConverter.hpp"

//Constructor
ScalarConverter::ScalarConverter() {}

//Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
	(void)other;
}

//Copy assignment operator
ScalarConverter&  ScalarConverter::operator=(const ScalarConverter& other) 
{
	(void)other;
	return (*this);
}

//Destructor
ScalarConverter::~ScalarConverter() {}

// Methods:

void	ScalarConverter::convert(const std::string str)
{
	// (void)str;
	int		type = ScalarConverter::getType(str);
	// if (type == UNDEFINED)
		

	switch (type)
	{
		case CHAR:
			std::cout << "char : " << str[0] << "\n";
			std::cout << "int : " << static_cast<int>(str[0]) << "\n";
			std::cout << "float : " << static_cast<float>(str[0]) << "\n";
			std::cout << "double : " << static_cast<double>(str[0]) << std::endl;
			break;
		case INT:
			std::cout << "char : " << static_cast<char>(std::stoi(str)) << "\n";
			std::cout << "int : " << std::stoi(str) << "\n";
			std::cout << "float : " << static_cast<float>(std::stoi(str)) << "\n";
			std::cout << "double : " << static_cast<double>(std::stoi(str)) << std::endl;
			break;
		case DOUBLE:
			std::cout << "char : " << std::stod(str) << "\n";
			std::cout << "int : " << static_cast<int>(std::stod(str)) << "\n";
			std::cout << "float : " << std::stof(str) << "\n";
			std::cout << "double : " << static_cast<double>(std::stod(str)) << std::endl;
			break;
		case FLOAT:
			std::cout << "char : " << static_cast<char>(std::stof(str)) << "\n";
			std::cout << "int : " << static_cast<int>(std::stof(str)) << "\n";
			std::cout << "float : " << std::stof(str) << "\n";
			std::cout << "double : " << static_cast<double>(std::stof(str)) << std::endl;
			break;
		case POSITIVE_INF:
			std::cout << "char : impossible" << "\n";
			std::cout << "int : impossible" << "\n";
			std::cout << "float : +inff" << "\n";
			std::cout << "double : +inf" << std::endl;
			break;
		case NEGATIVE_INF:
			std::cout << "char : impossible" << "\n";
			std::cout << "int : impossible" << "\n";
			std::cout << "float : -inff" << "\n";
			std::cout << "double : -inf" << std::endl;
			break;
		case NANF:
			std::cout << "char : impossible" << "\n";
			std::cout << "int : impossible" << "\n";
			std::cout << "float : nanf" << "\n";
			std::cout << "double : nan" << std::endl;
			break;
		case UNDEFINED:
			std::cout << "UNDEFINED" << std::endl;
		// 	std::cout << "char : " << str << "\n";
		// 	std::cout << "int : " << str << "\n";
		// 	std::cout << "float : " << str << "\n";
		// 	std::cout << "double : " << str << std::endl;
			break;
	}
}


int	ScalarConverter::getType(const std::string str)
{
	int i = 0;
	int dot = 0;
	int isChar = 0;

	if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
		return (POSITIVE_INF);
	else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
		return (NEGATIVE_INF);
	else if (str.compare("nanf") == 0 || str.compare("nan") == 0)
		return (NANF);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (std::isdigit((int)(str[i])))
			;
		else if (str[i] == '.')
			dot++;
		else
			isChar = 1;
		i++;
	}
	if (dot == 1 && str.back() != 'f')
		return (DOUBLE);
	else if (dot == 1 && str.back() == 'f')
		return (FLOAT);
	else if (!isChar && !dot)
		return (INT);
	else if (isChar && !dot && str.length() == 1)
		return (CHAR);
	return (UNDEFINED);
}


