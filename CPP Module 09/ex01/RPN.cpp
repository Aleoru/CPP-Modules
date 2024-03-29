/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:32 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 18:06:20 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN	& RPN::operator=(const RPN & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

int	operations(int a, int b, char op) {

	switch (op) {

		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
		default:
			throw RPN::InvalidExpressionException();
			break;
	}
	return (0);

}

int	RPN::calculate(std::string str) {

	std::stack<int>	nums;
	std::string	token;
	size_t pos;
	int		a;
	int		b;

	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw RPN::InvalidExpressionException();
	while ((pos = str.find_first_of(" ")) != std::string::npos || str.size() > 0){
		token = str.substr(0, pos);
		if (std::isdigit(token[0]) && token.size() == 1)
			nums.push(std::stoi(token));
		else if (str.find_first_of("+-*/") != std::string::npos && token.size() == 1) {
			b = nums.top();
			nums.pop();
			a = nums.top();
			nums.pop();
			nums.push(operations(a, b, token[0]));
		}
		else
			throw RPN::InvalidExpressionException();
		if (pos == std::string::npos)
			pos = 0;
		str.erase(0, pos + 1);
	}
	if (nums.size() != 1)
		throw RPN::InvalidExpressionException();
	return (nums.top());

}
