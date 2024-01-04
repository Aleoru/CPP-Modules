/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:08:07 by aoropeza          #+#    #+#             */
/*   Updated: 2023/12/18 20:54:10 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

enum	e_type{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERALS
};

class	ScalarConverter {

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter(void);
		ScalarConverter & operator=(const ScalarConverter & rhs);
	
	public:
		static void	convert(const std::string str);

	class	ScalarConverterException : public std::exception {
		virtual const char* what() const throw() { return "Unknown type"; }
	};
};

#endif