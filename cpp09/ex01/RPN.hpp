#pragma once

#include <stack>
#include <string>

class RPN {
private:
	std::stack<int> _stack;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	void process(const std::string& expression);
	void applyOperation(const std::string& op);
	int getResult() const;
};
