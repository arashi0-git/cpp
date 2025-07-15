#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>

class BitcoinExchange {
    private:
        std::map<std::string, float> _rates;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        bool loadDatabase(const std::string &filename);
        void evaluate(std::string, std::string value);
};

std::string trim(const std::string &string);
bool ft_stof(const std::string &str, float &out);
bool valid_value(const std::string &value, float &f_value);
bool valid_date(const std::string &date);

#endif