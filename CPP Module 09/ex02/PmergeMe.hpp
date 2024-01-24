/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:29 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/24 21:24:03 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class	PmergeMe {

	private:
		PmergeMe(){};
		PmergeMe(PmergeMe const &src){*this = src;};
		~PmergeMe(){};
		PmergeMe	&operator=(PmergeMe const &rhs);

	public:
		static void	vectorPmergeMe(int argc, char **argv);
		static void	dequePmergeMe(int argc, char **argv);

	class	InvalidValueFoundException : public std::exception {
		virtual const char* what() const throw() { return "Invalid Value Found"; }
	};

};

#endif