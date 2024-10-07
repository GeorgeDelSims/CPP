#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>


class BitcoinExchange 
{
    public:
        BitcoinExchange(); // constructor
        BitcoinExchange(const BitcoinExchange& other); //copy constructor
        BitcoinExchange&  operator=(const BitcoinExchange& other); // copy assignment operator
        ~BitcoinExchange(); // destructor 

        // Methods: 
        void                    readCSV(std::string& csv_filename);
        void                    checkValidDate(std::string &date);
        void                    checkValidValue(float price);
        static std::string      trim(const std::string &s);

        class invalidDate : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Invalid date format: ");
                }
        };

        class ValueTooLarge : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Too large a number.");
                }
        };

        class NegativeValue : public std::exception
        {
            public: 
                virtual const char* what() const throw()
                {
                    return ("Not a positive number.");
                }
        };

        std::map<std::string, float>    map;
    protected:
        // Protected member variables & utils functions:
        
    private:
        // Private member variables & utils functions:
};

#endif // BitcoinExchange_HPP
