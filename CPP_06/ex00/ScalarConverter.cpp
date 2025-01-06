#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string &s) {
    return (s.size() == 1 && !std::isdigit(s[0]));
}

bool isPseudoFloat(const std::string &s) {
    return (s == "inff" || s == "-inff" || s == "+inff" || s == "nanf");
}

bool isPseudoDouble(const std::string &s) {
    return (s == "inf" || s == "-inf" || s == "+inf" || s == "nan");
}

void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    if (isPseudoFloat(literal)) {
        std::string pseudoFloat = literal.substr(0, literal.size() - 1);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n"; //f
        std::cout << "double: " << pseudoFloat << "\n";
        return;
    }

    if (isPseudoDouble(literal)) {
        std::string pseudoDouble = literal.substr(0, literal.size() - 1);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n"; //f
        std::cout << "double: " << literal << "\n"; //f
        return;

    }

    char *endptr = NULL; //direkt başlatsam?
    double d = std::strtod(literal.c_str(), &endptr);
    if ((*endptr && *endptr != 'f') || (*endptr && *endptr == 'f' && *(endptr + 1))) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    //char
    if ( std::isinf(d) || std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) 
        std::cout << "char: impossible\n";
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else
        std::cout << "char: Non displayable\n";


    //int
    if (std::isinf(d) || std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";

    //float
    {
        float f = static_cast<float>(d);
        if (std::isinf(f))
            std::cout << "float: " << (f < 0 ? "-" : "") << "inff\n";
        else if (std::isnan(f))
            std::cout << "float: nanf\n";
        else
            std::cout << "float: " << f << (f - static_cast<int>(f) == 0 ? ".0f\n" : "f\n");
    }

    //double
    {
        if (std::isinf(d))
            std::cout << "double: " << (d < 0 ? "-" : "") << "inf\n";
        else if (std::isnan(d))
            std::cout << "double: nan\n";
        else
            std::cout << "double: " << d << (d - static_cast<int>(d) == 0 ? ".0\n" : "\n");
    }
    
}