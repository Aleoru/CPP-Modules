/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:35 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 16:43:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <string>
#include <list>

class	RPN{

	private:
		std::list<int>	_nums;
		RPN(void){};

	public:
		RPN(std::string str);
		RPN(RPN const &src);
		~RPN(void){};

		RPN	&operator=(RPN const & rhs);

		int	calculate(void);

	class	InvalidExpressionException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Reverse Polish Notation Exception"; }
	};

};

#endif