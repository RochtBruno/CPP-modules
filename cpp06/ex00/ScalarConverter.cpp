#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		// não existe atributos para serem copiados
	}
	return *this;
}


void ScalarConverter::printChar(char c) {
	if (std::isprint(c)) {
		std::cout << "char: '" << c << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(int i) {
		std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
    if (f < -std::numeric_limits<float>::max() || f > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double d) {
    if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
    } else {
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
}

int toInt(const std::string& s) {
    std::istringstream iss(s);
    long long temp;
    iss >> temp;

    if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max()) {
        throw std::out_of_range("Integer overflow");
    }
    return static_cast<int>(temp);
}

float toFloat(const std::string& s) {
    std::istringstream iss(s);
    double temp;
    iss >> temp;

    if (temp < -std::numeric_limits<float>::max() || temp > std::numeric_limits<float>::max()) {
        throw std::out_of_range("Float overflow");
    }
    return static_cast<float>(temp);
}

double toDouble(const std::string& s) {
    std::istringstream iss(s);
    long double temp;
    iss >> temp;

    if (temp < -std::numeric_limits<double>::max() || temp > std::numeric_limits<double>::max()) {
        throw std::out_of_range("Double overflow");
    }
    return static_cast<double>(temp);
}

void ScalarConverter::convert(const std::string &literal) {
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
if (literal.length() == 1 && !std::isdigit(literal[0])) {
		char c = literal[0];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
		return;
	}
 try {
        double d = toDouble(literal);
        try {
            if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
                std::cout << "float: impossible (overflow)" << std::endl;
            } else {
                printFloat(static_cast<float>(d));
            }
        } catch (...) {
            std::cout << "float: impossible" << std::endl;
        }
        try {
            int i = toInt(literal);
            printInt(i);
            printChar(static_cast<char>(i));
        } catch (const std::out_of_range& e) {
            std::cout << "int: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
    }
}
