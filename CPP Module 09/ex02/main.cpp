/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:37 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 17:31:40 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2) {
		try {
			PmergeMe::sortPmergeMe(argc, argv);
		} catch(std::exception &e) {
			std::cerr << "Error" << std::endl;
		}
	}
	else
		std::cout << "Insert at least 2 numbers to start the program" << std::endl;
	return (0);
}