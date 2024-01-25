/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:22:34 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 13:50:30 by aoropeza         ###   ########.fr       */
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
	clock_t	time;

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
	std::cout << "Before: ";
	for(size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	
	time = clock();
	vectorMergeSort(array);
	time = clock() - time;
	std::cout << "After: ";
	for(size_t i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
	/* << std::fixed << std::setprecision(5) */ << 1e6 * static_cast<double>(time) / (double)CLOCKS_PER_SEC << " us" << std::endl;


}

static void	dequeMerge(std::deque<int> lArray, std::deque<int> rArray, std::deque<int> &array) {

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

static void	dequeMergeSort(std::deque<int> &array){

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
	dequeMergeSort(lArray);
	dequeMergeSort(rArray);
	dequeMerge(lArray, rArray, array);

}

void	PmergeMe::dequePmergeMe(int argc, char **argv){
	
	std::deque<int>	array;
	clock_t	time;

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
	time = clock();
	dequeMergeSort(array);
	time = clock() - time;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : "
	/* << std::fixed << std::setprecision(5) */ << 1e6 * static_cast<double>(time) / (double)CLOCKS_PER_SEC << " us" << std::endl;

}