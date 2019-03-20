#pragma once
#include "GetExpression.h"

class ReadDataRes :public GetExpression {
private:
	std::vector<std::string> mv_Expression;
	const std::string m_FilePath;
	
public:
	ReadDataRes(const std::string& filepath);
	~ReadDataRes();
	
	std::vector<std::string>& ParseExpressionSource(const std::string& filepath);
	inline std::vector<std::string> GetSource()const override{ return mv_Expression; }
	
};

