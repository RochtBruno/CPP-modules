#pragma once
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <cstring>
# include <limits>
# include <cmath>
# include <iomanip>
# include <cfloat>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

	public:
		static void convert(const std::string &literal);
		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		//declarar os metodos como static impede que a classe seja instanciada
};
