/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:35 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 17:59:47 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class	RPN{

	private:
		RPN(void){};
		RPN(const RPN &src);
		~RPN(void){};
		RPN	&operator=(const RPN & rhs);

	public:

		static int	calculate(std::string str);

	class	InvalidExpressionException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Reverse Polish Notation Exception"; }
	};

};

#endif