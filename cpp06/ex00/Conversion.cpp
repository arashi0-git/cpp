#include "Conversion.hpp"

Conversion() {}

Conversion::(const Conversion &other) { (void)other}

Conversion &Conversion::operator=(const Conversion &other) { 
    (void)other
    return *this;
}

Conversion::~Conversion() {}

bool Conversion::IsInt(const std::string &arg) {
    size_t i = 0;
    if (arg[i] == '+' || arg[i] == '-')
        i++;
    if (arg.length() == i)
        return false;
    for (; i < arg.length(); i++) {
        if (!std::isdigit(arg[i]))
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
        } else if (!std::isdigit(arg[i]))
            return false;
    }
    return hasDot;
}

int Conversion::CheckArg(const std::string &arg) {
    if (arg.empty())
        return TYPE_INVALID;
    if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "nanf" || arg == "-inff" || arg == "+inff")
        return TYPE_PSEUDO;
    if (arg.length() == 1 && !std::isdigit(arg[0]))
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
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    int i = static_cast<int>(c);
        std::cout << "int: " << i << std::endl;
    
    float f = static_cast<float>(c);
        std::cout << "float: " << f << ".0f" << std::endl;

    double d = static_cast<double>(c);
        std::cout << "double: " << d << ".0" << std::endl;
}

void Conversion::ConvertFromInt(int n) {
    if (n >= 0 && n <= 127 && std::isprint(static_cast<char>(n)))
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << n << std::endl;

    float f = static_cast<float>(n);
    std::cout << "float: " << f << ".0f" << std::endl;

    double d = static_cast<double>(n);
    std::cout << "double: " << d << ".0" << std::endl;
}

void Conversion::ConvertFromFloat(float f) {
    if (f >= 0 && f <= 127 && std::isprint(static_cast<char>(f)))
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    int i = static_cast<int>(f);
    std::cout << "int: " << i << std::endl;

    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    double d = static_cast<double>(f);
    std::cout << "double: " << d <<  ".0" << std::endl;
}

void Conversion::ConvertFromDouble(double d) {
    if (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    int i = static_cast<int>(d);
    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(d);
    std::cout << "float: " << f << ".0f" << std::endl;

    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void Conversion::ConvertFromPseudo(const std::string &arg) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (arg.back() == 'f') {
        std::cout << "float: " << arg << std::endl;
        std::cout << "double: " << arg.substr(0, arg.length() - 1) << std::endl;
    } else {
        std::cout << "float: " << arg << "f" << std::endl;
        std::cout << "double: " << arg << std::endl;
    }
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
        case TYPE_PSEUDO:
            ConvertFromPseudo(arg);
            break;
        case TYPE_INVALID:
        default:
            std::cerr << "Error: invalid argument" << std::endl;
            break;
    }
}