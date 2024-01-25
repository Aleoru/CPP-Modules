/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:34 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 18:06:07 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe	&PmergeMe::operator=(const PmergeMe & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

static void	vectorMergeSort(std::vector<int> lArray, std::vector<int> rArray, std::vector<int> &array) {

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

static void	vectorPmergeMe(std::vector<int> &array){

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
	vectorPmergeMe(lArray);
	vectorPmergeMe(rArray);
	vectorMergeSort(lArray, rArray, array);

}

static void	dequeMergeSort(std::deque<int> lArray, std::deque<int> rArray, std::deque<int> &array) {

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

static void	dequePmergeMe(std::deque<int> &array){

	if (array.size() < 2)
		return ;
	size_t	mid = array.size() / 2;
	std::deque<int>	lArray;
	std::deque<int>	rArray;

	for (size_t i = 0; i < array.size(); i++) {
		if (i < mid)
			lArray.push_back(array[i]);
		else
			rArray.push_back(array[i]);
	}
	dequePmergeMe(lArray);
	dequePmergeMe(rArray);
	dequeMergeSort(lArray, rArray, array);

}

void	PmergeMe::sortPmergeMe(int argc, char **argv){

	std::vector<int>	vecArray;
	std::deque<int>		deqArray;
	std::string			str;
	clock_t				vecTime;
	clock_t				deqTime;

	try {
		for(int i = 1; i < argc; i++) {
			str = argv[i];
			if (str.find_first_not_of("0123456789") != std::string::npos)
				throw InvalidValueFoundException();
			if (std::stoi(argv[i]) > 0) {
				vecArray.push_back(std::stoi(argv[i]));
				deqArray.push_back(std::stoi(argv[i]));
			}
			else
				throw InvalidValueFoundException();
		}
	} catch(std::exception &e) {
		throw InvalidValueFoundException();
	}

	std::cout << "Before: ";
	for(size_t i = 0; i < vecArray.size(); i++)
		std::cout << vecArray[i] << " ";
	std::cout << std::endl;
	vecTime = clock();
	vectorPmergeMe(vecArray);
	vecTime = clock() - vecTime;
	deqTime = clock();
	dequePmergeMe(deqArray);
	deqTime = clock() - deqTime;
	std::cout << "After: ";
	for(size_t i = 0; i < vecArray.size(); i++)
		std::cout << vecArray[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
	<< static_cast<double>(vecTime) / (double)CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : "
	<< static_cast<double>(deqTime) / (double)CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

}