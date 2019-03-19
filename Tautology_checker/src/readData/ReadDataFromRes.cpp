#include "ReadDataFromRes.h"


ReadDataRes::ReadDataRes(const std::string& filepath)
	:m_FilePath(filepath)
{
	mv_Expression = ParseExpressionSource(filepath);
}

ReadDataRes::~ReadDataRes() {

}

std::vector<std::string>& ReadDataRes::ParseExpressionSource(const std::string& filepath) {
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss;

	while (std::getline(stream,line))
	{
		ss << line;
		mv_Expression.push_back(ss.str());
		ss.str("");
	}

	return mv_Expression;
}

