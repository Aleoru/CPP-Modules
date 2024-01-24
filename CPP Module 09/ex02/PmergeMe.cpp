/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:34 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/24 21:28:24 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	vectorMerge(std::vector<int> lArray, std::vector<int> rArray, std::vector<int> &array) {

	size_t	lSize = lArray.size();
	size_t	rSize = rArray.size();
	size_t	i = 0, l = 0, r = 0;

	while (l < lSize && r < rSize){
		if (lArray[l] < rArray[r]) {
			array[i] = lArray[l];
			i++;
			l++;
		} else {
			array[i] = rArray[r];
			i++;
			r++;
		}
	}
	while (l < lSize) {
		array[i] = lArray[l];
		i++;
		l++;
	}
	while (r < rSize) {
		array[i] = rArray[r];
		i++;
		r++;
	}

}

static void	vectorMergeSort(std::vector<int> &array){

	if (array.size() < 2)
		return ;
	size_t	mid = array.size() / 2;
	std::vector<int>	lArray;
	std::vector<int>	rArray;

	for (size_t i = 0; i < array.size(); i++) {
		if (i < mid)
			lArray.push_back(array[i]);
		else
			rArray.push_back(array[i]);
	}
	vectorMergeSort(lArray);
	vectorMergeSort(rArray);
	vectorMerge(lArray, rArray, array);

}

void	PmergeMe::vectorPmergeMe(int argc, char **argv){

	std::vector<int>	array;

	try {
		for(int i = 1; i < argc; i++) {
			if (std::stoi(argv[i]) > 0)
				array.push_back(std::stoi(argv[i]));
			else
				throw InvalidValueFoundException();
		}
	} catch(std::exception &e) {
		throw InvalidValueFoundException();
	}
	std::cout << std::endl;

	vectorMergeSort(array);

}

void	PmergeMe::dequePmergeMe(int argc, char **argv){
	
	std::deque<int>	array;

	try {
		for(int i = 1; i < argc; i++) {
			if (std::stoi(argv[i]) > 0)
				array.push_back(std::stoi(argv[i]));
			else
				throw InvalidValueFoundException();
		}
	} catch(std::exception &e) {
		throw InvalidValueFoundException();
	}
	std::cout << "Deque array: " << std::endl;
	for(size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << ", ";
	std::cout << std::endl;

}