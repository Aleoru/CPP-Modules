/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:20:19 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/16 19:47:06 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class	MutantStack : public std::stack<T> {

	public:
		MutantStack(void){};
		MutantStack(const MutantStack &src);
		~MutantStack(void){};

		MutantStack &operator=(MutantStack const &rhs);

		typedef typename	std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void);
		iterator	end(void);


};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src){
	this = src;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs){
	if (*this != rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template<typename T>
typename	MutantStack<T>::iterator	MutantStack<T>::begin(void){
	return (std::stack<T>::c.begin());
}

template<typename T>
typename	MutantStack<T>::iterator	MutantStack<T>::end(void){
	return (std::stack<T>::c.end());
}


#endif