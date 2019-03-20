#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "readData/ReadData.h"

class ExpToStack {
private:
	std::vector<std::stack<char>> m_ExpStack;
	std::stack<char> m_OutPut;
public:
	ExpToStack(){};
	ExpToStack(const std::vector<std::string>& vec_str);
	~ExpToStack();
	std::vector<std::stack<char>>& Transfer(const std::vector<std::string>& vec_str);
	std::stack<char>& ToChar(const std::string& str);
	inline std::vector<std::stack<char>> GetExpStack()const { return m_ExpStack; }

};