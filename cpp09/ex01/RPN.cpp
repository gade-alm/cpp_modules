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
	int			temp = 0;

	for (size_t i = 0; i < strlen(dataEntry); i++) {
		if (dataEntry[i] == ' ') {
			continue;
		}
		if (dataEntry[i + 1] && dataEntry[i + 1] != ' ' && isdigit(dataEntry[i]))
			throw std::out_of_range("Missing spaces between numbers");
		if (isdigit(dataEntry[i])) {
			temp = atoi(&dataEntry[i]);
			if (temp < 0 || temp > 9)
				throw std::out_of_range("Wrong input, please 0 to 9 numbers");
			values.push(atoi(&dataEntry[i]));
			result = temp;
		}
		if (isOperand(dataEntry[i])){
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

	if (values.size() < 2)
		throw std::runtime_error("Missing Numbers");
	
	int	num1 = values.top();
	// std::cout << "NUM1: " << num1 << std::endl;
	values.pop();
	int	num2 = values.top();
	// std::cout << "NUM2: " << num2 << std::endl;
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
			if (num1 == 0 || num2 == 0)
				throw std::out_of_range("No divisions with 0, please, we are not wolfram calculator");
			result = num2 / num1;
			break;
		case '*':
			result = num2 * num1;
			break;
	}
	// std::cout << "RESULT: " << result << std::endl << std::endl;
	return result;
}