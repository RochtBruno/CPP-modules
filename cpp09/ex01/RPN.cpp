#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN &RPN::operator=(const RPN &other){
	if(this != &other){
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::process(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (token.size() == 1 && isdigit(token[0])) {
			_stack.push(token[0] - '0');
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			applyOperation(token);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");
}

void RPN::applyOperation(const std::string& op) {
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int b = _stack.top(); _stack.pop();
	int a = _stack.top(); _stack.pop();
	int result;

	if (op == "+") result = a + b;
	else if (op == "-") result = a - b;
	else if (op == "*") result = a * b;
	else if (op == "/") {
		if (b == 0) throw std::runtime_error("Error");
		result = a / b;
	} else {
		throw std::runtime_error("Error");
	}

	_stack.push(result);
}

int RPN::getResult() const {
	return _stack.top();
}
