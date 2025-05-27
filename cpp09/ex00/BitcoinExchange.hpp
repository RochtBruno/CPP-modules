#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iomanip>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_data;
		std::string					_inputFile;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange(const std::string &inputFile);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);

		void	loadDatabase(const std::string &filename);
		void	readExecInput(void);
		double	getExchangedRate(const std::string &date);

		class OpenFileError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

