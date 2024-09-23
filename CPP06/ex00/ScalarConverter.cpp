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

// Static function to check if int input is in range
static int inputChecks(const std::string str, int type)
{
	if (type == INT)
	{
		try
		{
			int num = std::stoi(str);
			(void)num;
		}
		catch (const std::out_of_range& e)
		{
			std::cout << "Invalid input : " << e.what() << std::endl;
			return (-1);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Invalid argument error: " << e.what() << std::endl;
			return (-1);
		}
	}
	return (0);
}

void	ScalarConverter::convert(const std::string str)
{
	int				type = ScalarConverter::getType(str);
	
	if (inputChecks(str, type) == -1)
		return ;
	switch (type)
	{
		case CHAR:
			std::cout << "char : '" << str[0] << "'\n";
			std::cout << "int : " << static_cast<int>(str[0]) << "\n";
			std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << "\n";
			std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
			break;
		case INT:
			if (std::stoi(str) < 33 || std::stoi(str) > 127)
				std::cout << "char : Non displayable\n";
			else 
				std::cout << "char : '" << static_cast<char>(std::stoi(str)) << "'\n";
			std::cout << "int : " << std::stoi(str) << "\n";
			std::cout << "float : " << static_cast<float>(std::stoi(str)) << ".0f" << "\n";
			std::cout << "double : " << static_cast<double>(std::stoi(str)) << ".0" << std::endl;
			break;
		case DOUBLE:
			if (std::stoi(str) < 33 || std::stoi(str) > 127)
				std::cout << "char : Non displayable\n";
			else
				std::cout << "char : '" << static_cast<char>(std::stoi(str)) << "'\n";
			std::cout << "int : " << static_cast<int>(std::stod(str)) << "\n";
			std::cout << "float : " << std::stof(str) << "f" << "\n";
			std::cout << "double : " << static_cast<double>(std::stod(str)) << std::endl;
			break;
		case FLOAT:
			if (std::stoi(str) < 33 || std::stoi(str) > 127)
				std::cout << "char : Non displayable\n";
			else
				std::cout << "char : '" << static_cast<char>(std::stoi(str)) << "'\n";
			std::cout << "int : " << static_cast<int>(std::stof(str)) << "\n";
			std::cout << "float : " << std::stof(str) << "f" << "\n";
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
			std::cout << "char : impossible" << "\n";
			std::cout << "int : impossible" << "\n";
			std::cout << "float : impossible" << "\n";
			std::cout << "double : impossible" << std::endl;
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


