#include "RPN.hpp"


static bool	isOperand( char value ) {
	return ((value == '+' || value == '-' || value == '/' || value == '*') ? true : false);
}

void	checkValues ( char *dataEntry ) {

	for (size_t i = 0; i < strlen(dataEntry); i++) {
		if (!isdigit(dataEntry[i]) && !isOperand(dataEntry[i]) && dataEntry[i] != ' ')
			throw std::out_of_range("Wrong input values");
	}
	return ;
}

void	calcValue( char* dataEntry ) {

	std::stack<int> values;
	int			result = 0;

	for (size_t i = 0; i < strlen(dataEntry); i++) {
		if (dataEntry[i] == ' ') {
			continue;
		}
		if (isdigit(dataEntry[i]) && values.size() < 3) {
			values.push(atoi(&dataEntry[i]));
		}
		if (isOperand(dataEntry[i]) && values.size() < 4){
			result = resultOperation(values, dataEntry[i]);
			values.push(result);
			continue ;
		}
	}
	if (values.size() != 1)
		throw std::runtime_error("Wrong input values");
	std::cout << result << std::endl;
}

int		resultOperation ( std::stack<int> &values, char operand ) {

	if (values.size() != 2 && values.size() != 3)
		throw std::runtime_error("Wrong operation");
	
	int	num1 = values.top();
	std::cout << "NUM1: " << num1 << std::endl;
	values.pop();
	int	num2 = values.top();
	std::cout << "NUM2: " << num2 << std::endl;
	values.pop();

	int result = 0;

	switch (operand) {
		case '+':
			result = num2 + num1;
			break;
		case '-':
			result = num2 - num1;
			break ;
		case '/':
			result = num2 / num1;
			break;
		case '*':
			result = num2 * num1;
			break;
	}
	std::cout << "RESULT: " << result << std::endl << std::endl;
	return result;
}