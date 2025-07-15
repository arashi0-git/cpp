#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2){
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    if (!exchange.loadDatabase("data.csv"))
        return 1;

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        if (pos != std::string::npos) {
            std::string date = trim(line.substr(0, pos));
            std::string value = trim(line.substr(pos + 1));
            exchange.evaluate(date, value);
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    return 0;
}