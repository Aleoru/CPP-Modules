/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/08 14:22:42 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void){
	std::cout << "Span default constructor called" << std::endl;
}
Span::Span(unsigned int N) : _N(N) {
	_nums.reserve(_N);
	//std::cout << "Span parametized constructor called" << std::endl;

}
Span::Span(Span &src){
	*this = src;
	//std::cout << "Span copy constructor called" << std::endl;

}
Span::~Span(void){
	//std::cout << "Span destructor called" << std::endl;

}

Span	&Span::operator=(Span const &rhs){

	if (this != &rhs)
		*this = rhs;
	return *this;
	
}

void	Span::addNumber(int	num){

	if (_nums.size() == _nums.capacity())
		throw Span::MaxCapacityReachedExpception();
	else
		_nums.push_back(num);

}

int	Span::shortestSpan(void){
	
	int	aux;
	int	res;
	
}

int	Span::longestSpan(void){
	
}