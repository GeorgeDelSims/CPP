#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    BitcoinExchange     btc;
    std::string         csv = "data.csv";

    if (ac != 2)
    {
        std::cout << "please input : ./btc <filename>" << std::endl;
        return (1);
    }

    btc.readCSV(csv);
    
    // for (std::map<std::string, float>::iterator  it = btc.map.begin(); it != btc.map.end(); ++it)
        // std::cout << it->first << " : " << it->second << std::endl;

    std::string     filename = av[1];
    std::ifstream   fs;
    std::string     line;

    fs.open(filename.c_str());
    while (std::getline(fs, line)) 
    {
        std::istringstream  ss(line); 
        std::string         date;
        float               rate;
        float               result = 0.0f;
        
        if (std::getline(ss, date, '|')) // reads line up to '|'
        {
            date = BitcoinExchange::trim(date);
            try
            {
                btc.checkValidDate(date);
                std::cout << date << " => ";
            }
            catch (std::exception& e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try
            {
                if (ss >> rate) 
                {
                    btc.checkValidValue(rate);
    
                    std::map<std::string, float>::iterator  it = btc.map.find(date);
                    if (it != btc.map.end())
                    {
                        result = it->second * rate;
                        std::cout << rate << " = " << result << std::endl;
                    }
                    else
                    {
                        std::cout << "Error: Date not found in data : " << date << std::endl;
                    }
                }
            }
            catch (std::exception& e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
    }
    fs.close();
    return (0);
}