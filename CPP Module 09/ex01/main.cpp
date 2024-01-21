/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:25:28 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/21 20:34:50 by aoropeza         ###   ########.fr       */
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
		RPN	calc(argv[1]);
	}
	return (0);
}