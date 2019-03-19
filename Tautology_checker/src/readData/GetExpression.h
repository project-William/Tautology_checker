#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class GetExpression {

public:
	GetExpression(){}
	virtual ~GetExpression(){}

	virtual inline std::vector<std::string> GetSource()const = 0;
};