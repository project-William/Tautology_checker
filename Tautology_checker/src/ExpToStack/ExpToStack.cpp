#include "ExpToStack.h"

ExpToStack::ExpToStack(const std::vector<std::string>& vec_str) {
	m_ExpStack = Transfer(vec_str);
}

ExpToStack::~ExpToStack() {

}

std::vector<std::stack<char>>& ExpToStack::Transfer(const std::vector<std::string>& vec_str) {
	for (auto str : vec_str) 
		m_ExpStack.push_back(ToChar(str));
	return m_ExpStack;
}


std::stack<char>& ExpToStack::ToChar(const std::string& str) {
	std::stack<char> m_Temp;

	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (ch >= 'A' && ch <= 'Z') {
			m_OutPut.push(ch);
		}
		else {
			switch (ch){
			case '~': m_Temp.push(ch); break;
			case '(': m_Temp.push(ch); break;
			case ')':while (m_Temp.top()!='('){
						m_OutPut.push(m_Temp.top());
						m_Temp.pop();
					}
					 if (m_Temp.top() == '(')
						 m_Temp.pop();
					 break;
			case '&':while (m_Temp.top() == '~') {
						m_OutPut.push(m_Temp.top());
						m_Temp.pop();
					}
					 m_Temp.push(ch);
					 break;
			case '|':while (m_Temp.top() == '~'|| m_Temp.top()=='&') {
						m_OutPut.push(m_Temp.top());
						m_Temp.pop();
					}
					 m_Temp.push(ch);
					 break;
			}
		}
	}
	while (m_Temp.top()){
		char ob = m_Temp.top();
		m_OutPut.push(ob);
		m_Temp.pop();
	}
	return m_OutPut;
}