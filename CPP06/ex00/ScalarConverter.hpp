#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <climits>
#include <stdexcept>
#include <cstdlib>
#include <cfloat>
#include <cmath>

typedef enum e_Type 
{
    CHAR = 0,
    INT = 1,
    DOUBLE = 2,
    FLOAT = 3,
    POSITIVE_INF = 4,
    NEGATIVE_INF = 5,
    NANF = 6,
    UNDEFINED = 7
}               Type;


class ScalarConverter 
{
    public:
        ScalarConverter(); // constructor
        ScalarConverter(const ScalarConverter& other); //copy constructor
        ScalarConverter&  operator=(const ScalarConverter& other); // copy assignment operator
        ~ScalarConverter(); // destructor 

        // Methods: 
        static char         ConvertToChar(double d);
        static int          ConvertToInt(double d);
        static float        ConvertToFloat(double d);
        static double       ConvertToDouble(double d);

        static void         convert(const std::string str);
        static int          getType(const std::string str);
    
        // static int      getType(const std::string str);

        // Exceptions: 
        class impossible : public std::exception
        {
            public:
                const char  *what() const throw()
                {
                    return ("impossible");
                };
        };

        class NonDisplayable : public std::exception
        {
            public: 
                const char  *what() const throw()
                {
                    return ("Non displayable");
                };
        };




    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
        // class exception
};

#endif // ScalarConverter_HPP
