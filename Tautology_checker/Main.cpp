#include "src/readData/ReadData.h"
#include <memory>


std::ostream& operator<<(std::ostream& os, const std::vector<std::string> vec_str) {
	for (auto str : vec_str)
		os << str << '\n';
	return os;
}


int main() {

	std::shared_ptr<GetExpression> dataInput(new ReadDataInput());
	std::shared_ptr<GetExpression> dataRes(new ReadDataRes("res/LogicExpression.txt"));
	
	std::cout << dataInput->GetSource() << std::endl;
	std::cout << dataRes->GetSource() << std::endl;

	return 0;
}