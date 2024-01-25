/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:29 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 17:59:46 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <deque>

class	PmergeMe {

	private:
		PmergeMe(){};
		PmergeMe(const PmergeMe &src){*this = src;};
		~PmergeMe(){};
		PmergeMe	&operator=(const PmergeMe  &rhs);

	public:
		static void	sortPmergeMe(int argc, char **argv);

	class	InvalidValueFoundException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Value Found"; }
	};

};

#endif