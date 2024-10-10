#include "BitcoinExchange.hpp"

//Constructor
BitcoinExchange::BitcoinExchange() {}

//Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : map(other.map) {}

//Copy assignment operator
BitcoinExchange&  BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other)
    {
        this->map = other.map;
    }
    return (*this);
}

//Destructor
BitcoinExchange::~BitcoinExchange() {}

// Methods:
void    BitcoinExchange::readCSV(std::string& csv_filename)
{
    std::map<std::string, float>    btcdata;
    std::ifstream                   csvFile(csv_filename.c_str());
    std::string                     line;

    if (!csvFile.is_open())
    {
        std::cerr << "Could not open file : " << csvFile << std::endl;
        return ;
    }
    std::getline(csvFile, line);
    while (std::getline(csvFile, line))
    {
        // turn each line into a string stream to make it easier to parse
        std::istringstream  ss(line.c_str());
        std::string         date;
        float               price;

        if (std::getline(ss, date, ',')) // reads line up to ','
        {
            date = trim(date);
            if (ss >> price) // reads rest of line after ',' (automatically converts to float!)
                btcdata[date] = price;
            else
                std::cerr << "Error: Failed to read price after date: " << date << std::endl;
        }
        else 
            std::cerr << "Error: Failed to read date from line: " << line << std::endl;
        
    }
    this->map = btcdata;
}

void    BitcoinExchange::checkValidDate(std::string &date)
{
    date = trim(date);
    if (date.length() < 10 || date.length() > 11)
        throw (BitcoinExchange::invalidDate());
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
            {
                std::cerr << "didn't  find '-'" << std::endl;
                throw (BitcoinExchange::invalidDate());
            }
        }
        else
        {
            if (!std::isdigit(date[i]))
            {
                std::cerr << "isdigit" << std::endl;
                throw (BitcoinExchange::invalidDate());
            }
        }
    }
    if (date.substr(0, 3) <= "2008" || date.substr(0, 3) > "2024" )
        throw (BitcoinExchange::invalidDate());
    if (date.substr(5, 6) >= "13" || date.substr(5, 6) < "00")
        throw (BitcoinExchange::invalidDate());
    if (date.substr(8, 9) > "31" || date.substr(8, 9) < "00")
        throw (BitcoinExchange::invalidDate());
}

void    BitcoinExchange::checkValidValue(float price)
{
    if (price < 0.0)
        throw (BitcoinExchange::NegativeValue());
    if (price > 1000.0)
        throw (BitcoinExchange::ValueTooLarge());
}

// Function to trim leading and trailing whitespace
std::string BitcoinExchange::trim(const std::string &s) 
{
    size_t start = 0;
    size_t end = s.length();

    while (start < end && std::isspace(s[start])) 
    {
        start++;
    }
    while (end > start && std::isspace(s[end - 1])) 
    {
        end--;
    }
    return (s.substr(start, end - start));
}