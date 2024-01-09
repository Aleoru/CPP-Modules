/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:58 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/09 20:12:55 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	
	try {
		std::cout << "\033[33;1m[    TEST 1    ]\033[0m" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		Span bigsp(10000);
		bigsp.fillSpan(10000);
		std::cout << bigsp.shortestSpan() << std::endl;
		std::cout << bigsp.longestSpan() << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33;1m[    TEST 2    ]\033[0m" << std::endl;
		Span	wsp(5);
		wsp.addNumber(42);
		std::cout << wsp.shortestSpan() << std::endl;
		std::cout << wsp.longestSpan() << std::endl;


	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);	
}