#pragma once
#include "GetExpression.h"

class ReadDataInput :public GetExpression {
private:
	std::vector<std::string> mv_Expression;
public:
	ReadDataInput();
	~ReadDataInput();

	std::vector<std::string>& InputExpression();
	inline std::vector<std::string> GetSource()const override { return mv_Expression; }
	
};