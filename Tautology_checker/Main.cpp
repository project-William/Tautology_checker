#include "src/ExpToStack/readData/ReadData.h"
#include "src/ExpToStack/ExpToStack.h"
#include <memory>


std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& vec_str) {
	for (auto str : vec_str)
		os << str << '\n';
	return os;
}

int main() {
	std::shared_ptr<GetExpression> dataRes(new ReadDataRes("res/LogicExpression.txt"));
	ExpToStack SourceInStack(dataRes->GetSource());
	//std::cout << SourceInStack.GetExpStack() << std::endl;;



	//std::cout << dataRes->GetSource() << std::endl;
	return 0;
}