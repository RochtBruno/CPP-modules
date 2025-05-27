# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::BitcoinExchange(const std::string &inputFile) : _inputFile(inputFile) {}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src) {
		_data = src._data;
		_inputFile = src._inputFile;
	}
	return *this;
}


void	BitcoinExchange::loadDatabase(const std::string &filename){
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw OpenFileError();
	}

	std::string line;
	std::getline(file,line);
	while(std::getline(file,line)){
		std::stringstream ss(line);
		std::string data;
		std::string rateStr;
		double rate;

		if(!std::getline(ss,data,',')) continue;
		if(!std::getline(ss,rateStr)) continue;

		std::stringstream convert(rateStr);
		convert >> rate;
		if(convert.fail()) continue;

		_data[data] = rate;
	}
	file.close();
}

double BitcoinExchange::getExchangedRate(const std::string &date){
	std::map<std::string, double>::iterator it = _data.find(date);

	if(it != _data.end())
		return it->second;
	else{
		it = _data.lower_bound(date);
		if(it == _data.begin())
			throw std::runtime_error("Error: no available exchange rate for this date.");
		--it;
		return it->second;
	}
}

std::string trim(const std::string &str) {
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

void BitcoinExchange::readExecInput() {
	std::ifstream file(_inputFile.c_str());
	if (!file.is_open()) {
		throw OpenFileError();
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));
		double value;

		std::stringstream convert(valueStr);
		convert >> value;
		if (convert.fail()) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try {
			double rate = getExchangedRate(date);
			double result = rate * value;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}



const char *BitcoinExchange::OpenFileError::what() const throw() {
	return "Error opening file.";
}



