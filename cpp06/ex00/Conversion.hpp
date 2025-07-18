#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <iostream>
#include <cctype>

enum Type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};

class Conversion {
    private:
        Conversion();
        Conversion(const Conversion &other);
        Conversion &operator=(const Conversion &other);
        ~Conversion();
        
        static bool IsInt(const std::string &arg);
        static bool IsDecimal(const std::string &arg);
        static void ConvertFromChar(char c);
        static void ConvertFromInt(int n);
        static void ConvertFromDouble(double d);
        static void ConvertFromFloat(float f);
        static void ConvertFromPseudo(const std::string &arg);
    public:
        static int CheckArg(const std::string &arg);
        static void Convert(const std::string &arg, int type);
};

#endif