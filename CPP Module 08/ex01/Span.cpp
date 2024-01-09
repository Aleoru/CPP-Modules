/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:46:55 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/09 20:02:49 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {
	std::cout << "Span default constructor called" << std::endl;
}
Span::Span(unsigned int N) : _N(N) {
	this->_nums.reserve(_N);
	//std::cout << "Span parametized constructor called" << std::endl;

}
Span::Span(const Span &src){
	*this = src;
	//std::cout << "Span copy constructor called" << std::endl;

}
Span::~Span(void){
	//std::cout << "Span destructor called" << std::endl;

}

Span	&Span::operator=(Span const &rhs){

	if (this != &rhs) {
		this->_N = rhs._N;
		this->_nums = rhs._nums;
	}
	return (*this);
	
}

void	Span::addNumber(int	num){

	if (_nums.size() == _nums.capacity())
		throw Span::MaxCapacityReachedExpception();
	else
		_nums.push_back(num);

}

int	Span::shortestSpan(void){
	
	std::vector<int>	copy(_nums.size());

	std::copy(this->_nums.begin(), this->_nums.end(), copy.begin());
	std::sort(copy.begin(), copy.end());

	int	span = std::abs(copy[1] - copy[0]);

	for(std::vector<int>::const_iterator it = copy.begin(); it < copy.end(); ++it){

		if (std::abs(*(it + 1) - *it) < span)
			span = *(it + 1) - *it;

	}
	return (span);	
}

int	Span::longestSpan(void){
	
	std::vector<int>	copy(_nums.size());

	std::copy(this->_nums.begin(), this->_nums.end(), copy.begin());
	std::sort(copy.begin(), copy.end());

	return(std::abs(copy.back() - copy.front()));

}

int RandomNumber () {
	return (std::rand());
}

void	Span::fillSpan(unsigned int n){

	unsigned int	size = this->_nums.size();

	if (size + n > this->_N)
		throw Span::MaxCapacityReachedExpception();

	std::srand(unsigned(std::time(0)));
	_nums.resize(size + n);
	std::generate(_nums.begin() + size, _nums.end(), RandomNumber);

}

void	Span::printSpan(void) {

	for (std::vector<int>::const_iterator it = _nums.begin(); it != _nums.end(); ++it){
		std::cout << *it << std::endl;
	}

}