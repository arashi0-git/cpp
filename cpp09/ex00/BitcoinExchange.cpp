#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _rates() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    _rates = other._rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string trim(const std::string &string) {
    size_t first = string.find_first_not_of(" \t\r");
    if (first == std::string::npos)
        return "";
    size_t last = string.find_last_not_of(" \t\r");
    std::string dst = string.substr(first, last - first + 1);
    return dst;
}

bool ft_stof(const std::string &str, float &out) {
    std::stringstream ss(str);
    ss >> out;
    return !ss.fail();
}


bool BitcoinExchange::loadDatabase(const std::string &database) {
    std::ifstream datafile(database);
    if (!datafile.is_open()) {
        std::cerr << "Error: could not open data.csv file" << std::endl;
        return false;
    }

    std::string line;
    std::getline(datafile, line);
    while (std::getline(datafile, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        if (date == "")
            continue;
        std::string rate = trim(line.substr(pos + 1));
        if (rate == "")
            continue;
        
        float ratevalue;
        if (!ft_stof(rate, ratevalue)) {
            std::cerr << "Error: not a number." << std::endl;
            return false;
        }
        this->_rates[date] = ratevalue;
    }
    return true;
}

bool valid_value(const std::string &value, float &f_value) {
    if (!ft_stof(value, f_value)){
        std::cerr << "Error: not a number." << std::endl;
        return false;
    }
    if (f_value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (f_value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

bool valid_date(const std::string &date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

void BitcoinExchange::evaluate(std::string date, std::string value) {
    float f_value;
    if (!valid_value(value, f_value))
        return;
    if (!valid_date(date))
        return;
    std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
    if (it == _rates.end() || it->first != date) {
        if (it == _rates.begin()) {
            std::cerr << "Error: no rate available before this date" << std::endl;
            return;
        }
        --it;
    }

    float rate = it->second;
    std::cout << date << "=> " << value << " = " << f_value * rate << std::endl;
}