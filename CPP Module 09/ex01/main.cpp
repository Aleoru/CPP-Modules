/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:28 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 21:41:06 by aoropeza         ###   ########.fr       */
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
			int	res = RPN::calculate(argv[1]);
			std::cout << "Final res = " << res << std::endl;
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}