#include "ScalarConverter.hpp"

//Constructor
ScalarConverter::ScalarConverter() {}

//Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
	*this = other;
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

char	ScalarConverter::ConvertToChar(double d)
{
	if (isnan(d))
		throw (ScalarConverter::impossible());
	if (d < 32.0 || d > 127.0)
		throw (ScalarConverter::NonDisplayable());
	return (static_cast<char>(d));
}

int		ScalarConverter::ConvertToInt(double d)
{
	if (isnan(d) || isinf(d))
		throw (ScalarConverter::impossible());
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
		throw (ScalarConverter::impossible());
	return (static_cast<int>(d));
}

float	ScalarConverter::ConvertToFloat(double d)
{
	if (d > FLT_MAX || d < -FLT_MAX)
		throw (ScalarConverter::impossible());
	return (static_cast<float>(d));
}

double	ScalarConverter::ConvertToDouble(double d)
{
	return (static_cast<double>(d));
}

void	ScalarConverter::convert(const std::string str)
{
	double		value = std::atof(str.c_str());
	bool		hasDecimal = true;
	char		_char;

	if (std::floor(value) == value)
		hasDecimal = false;	

	std::cout << "string : " << str << std::endl;
	if (getType(str) == UNDEFINED) 
	{
		std::cout << "char : Non displayable\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
		return ;
	}
	else if (getType(str) == POSITIVE_INF)
	{
		std::cout << "char : Non displayable\nint : impossible\nfloat : +inff\ndouble : +inff" << std::endl;
		return ;
	}
	else if (getType(str) == NEGATIVE_INF)
	{
		std::cout << "char : Non displayable\nint : impossible\nfloat : -inff\ndouble : -inff" << std::endl;
		return ;
	}
	try // CHAR
	{
		std::cout << "char : ";
		_char = ConvertToChar(value);
		std::cout << "'" << _char << "'" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try // INT
	{
		std::cout << "int : ";
		std::cout << ConvertToInt(value) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try // FLOAT 
	{
		std::cout << "float : ";
		std::cout << ConvertToFloat(value);
		if (hasDecimal == false)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try // DOUBLE
	{
		std::cout << "double : ";
		std::cout << ConvertToDouble(value);
		if (hasDecimal == false)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
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
			isChar += 1;
		i++;
	}
	if  (isChar)
	{
		if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])))
			return (CHAR);
		else if (dot == 1 && isChar == 1 && str[str.length() - 1] == 'f')
			return (FLOAT);
		else
			return (UNDEFINED);
	}
	if (dot == 1 && str[str.length() - 1] != 'f')
		return (DOUBLE);
	else if (!isChar && !dot)
		return (INT);
	return (UNDEFINED);
}
