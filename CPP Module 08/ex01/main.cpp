/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:58 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/04 14:13:29 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	sp(3);
	
	try {
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);	
}