#include "ReadDataFromInput.h"


ReadDataInput::ReadDataInput() {
	mv_Expression = InputExpression();
}

ReadDataInput::~ReadDataInput() {

}

std::vector<std::string>& ReadDataInput::InputExpression() {
	
	unsigned int exp_num;
	std::string expression;
	std::cout << "Input the number of logic expression: ";
	std::cin >> exp_num;
	mv_Expression.reserve(exp_num);
	for (int i = 0; i < exp_num; i++) {
		std::cout << "Please input the " << i + 1 << " exprssion:";
		std::cin >> expression;
		mv_Expression.push_back(expression);
	}
	return mv_Expression;
}

