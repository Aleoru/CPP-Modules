/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:28 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/24 18:17:36 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		std::cout << "usage: ./RPN [inverted polish mathematical expression]" << std::endl;
	else {
		try {
			std::cout << RPN::calculate(argv[1]) << std::endl;
		} catch (std::exception &e){
			std::cerr << "Error" << std::endl;
		}
	}
	return (0);
}