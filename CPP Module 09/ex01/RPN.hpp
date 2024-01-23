/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:35 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 22:06:23 by aoropeza         ###   ########.fr       */
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
		RPN(RPN const &src);
		~RPN(void){};
		RPN	&operator=(RPN const & rhs);

	public:

		static int	calculate(std::string str);

	class	InvalidExpressionException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Reverse Polish Notation Exception"; }
	};

};

#endif