/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:28 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 16:40:52 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		std::cout << "usage: ./RPN [inverted polish mathematical expression]" << std::endl;
	else {
		std::cout << "Hago cosas" << std::endl;
		try {
			RPN	calc(argv[1]);	
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}