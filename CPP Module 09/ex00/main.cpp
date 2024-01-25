/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:06:15 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 19:55:11 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) {
		BitcoinExchange::bitcoinExchange(argv[1]);
	} else {
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return (1);
	}
	return (0);
}
