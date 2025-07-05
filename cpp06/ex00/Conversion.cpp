#include "Conversion.hpp"

bool Conversion::IsInt(const std::string &arg) {
    size_t i = 0;
    if (arg[i] == '+' || arg[i] == '-')
        i++;
    if (arg.length() == i)
        return false;
    for (; i < arg.length(); i++) {
        if (!isdigit(arg[i]))
            return false;
    }
    return true;
}

bool Conversion::IsDecimal(const std::string &arg) {
    size_t i = 0;
    bool hasDot = false;
    if (arg[i] == '+' || arg[i] == '-')
        i++;
    if (arg.length() == i)
        return false;
    for (; i < arg.length(); i++) {
        if (arg[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!isdigit(arg[i]))
            return false;
    }
    return hasDot;
}

int Conversion::CheckArg(const std::string &arg) {
    if (arg.empty())
        return TYPE_INVALID;
    if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "nanf" || arg == "-inff" || arg == "+inff")
        return TYPE_PSEUDO;
    if (arg.length() == 1 && !isdigit(arg[0]))
        return TYPE_CHAR;
    if (IsInt(arg))
        return TYPE_INT;
    if (IsDecimal(arg))
        return TYPE_DOUBLE;
    if (arg.back() == 'f' && IsDecimal(arg.substr(0, arg.length() -1)))
        return TYPE_FLOAT;

    return TYPE_INVALID;
}

void Conversion::ConvertFromChar(char c) {
    std::cout << "char: " << c << std::endl;
    std::cout << "int: Non displayable" << std::endl;
    std::cout << "double: Non displayable" << std::endl;
    std::cout << "float: Non displayable" << std::endl;
}

void Conversion::ConvertFromInt(int n) {

}

void Conversion::Convert(const std::string &arg, int type) {
    switch (type) {
        case TYPE_CHAR:
            ConvertFromChar(arg[0]);
            break;
        case TYPE_INT:
            ConvertFromInt(std::atoi(arg.c_str()));
            break;
        case TYPE_DOUBLE:
            ConvertFromDouble(std::strtod(arg.c_str(), NULL));
            break;
        case TYPE_FLOAT:
            ConvertFromFloat(std::strtof(arg.c_str(), NULL));
            break;
        case TYPE_INVALID:
        default:
            std::cerr << "Error: invalid argument" << std::endl;
            break;
    }
}