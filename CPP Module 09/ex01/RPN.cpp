/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:32 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/21 21:01:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string str){

	std::string	token;
	size_t pos = 0;
	while ((pos = str.find(" ")) != std::string::npos){
		token = str.substr(0, pos);
		if (std::isdigit(token[0]) && std::stoi(token) < 10)
			_nums.push_back(std::stoi(token));
		else if ()
		std::cout << token << " " << std::endl;
		str.erase(0, pos + 1);
	}
	token = str.substr(0, pos);
	if (std::stoi(token) < 10)
		_nums.push_back(std::stoi(token));
	std::cout << token << " " << std::endl;
	str.erase(0, pos + 1);
	
}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN	& RPN::operator=(RPN const & rhs) {
	(void)rhs;
	return *this;
}