/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:06:12 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 19:47:10 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <algorithm>
# include <fcntl.h>
# include <map>

class BitcoinExchange
{
private:
    BitcoinExchange(){};
    BitcoinExchange(const BitcoinExchange & src){*this = src;};
    ~BitcoinExchange(){};
    BitcoinExchange & operator=(const BitcoinExchange & src);

public:
    static void bitcoinExchange(std::string file);
    
class	InvalidDateException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Date input"; }
};

class	InvalidValueException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Value input"; }
};

class	NotPositiveNumberException : public std::exception {
		virtual const char* what() const throw() { return "not a positive number."; }
};

class	TooLargeNumberException : public std::exception {
		virtual const char* what() const throw() { return "too large a number."; }
};

};



#endif