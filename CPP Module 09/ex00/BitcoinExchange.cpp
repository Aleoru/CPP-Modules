/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:50:51 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/25 20:18:25 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

static bool	validDate(std::string date) {
	
	int	year, month, day;
	
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 6));
		day  = std::stoi(date.substr(8, 9));
	} catch (const std::exception &e) {
		throw BitcoinExchange::InvalidDateException();
	}
	int	monthLenght[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)
		monthLenght[1] = 29;
	if ((year < 2009 || year > 2022) || (month < 1 || month > 12) || (day < 1 || day > monthLenght[month - 1]))
		throw BitcoinExchange::InvalidDateException();
	return (true);

}

static bool	validValue(std::string value) {

	try {

		float	num = std::stof(value);
		if (num < 0)
			throw BitcoinExchange::NotPositiveNumberException();
		else if (num > 100)
			throw BitcoinExchange::TooLargeNumberException();

	} catch (const BitcoinExchange::NotPositiveNumberException &e) {
			throw BitcoinExchange::NotPositiveNumberException();
	} catch (const BitcoinExchange::TooLargeNumberException &e) {
			throw BitcoinExchange::TooLargeNumberException();
	} catch (const std::exception &e) {
		if (value.find_first_not_of("0123456789") != std::string::npos)
			throw BitcoinExchange::InvalidValueException();
	}
	return (true);

}

static bool	validValue(float num) {

	try {

		if (num < 0)
			throw BitcoinExchange::NotPositiveNumberException();
		else if (num > 100)
			throw BitcoinExchange::TooLargeNumberException();

	} catch (const BitcoinExchange::NotPositiveNumberException &e) {
			throw BitcoinExchange::NotPositiveNumberException();
	} catch (const BitcoinExchange::TooLargeNumberException &e) {
			throw BitcoinExchange::TooLargeNumberException();
	}
	return (true);

}

static std::string	previousDate(std::string date, std::map<std::string, float> db) {
	
	std::map<std::string, float>::iterator	it;
	std::string	prev;

	for (it = db.begin(); it != db.end(); ++it) {
		if (date >= it->first)
			prev = it->first;
	}
	return (prev);	

}

static	std::map<std::string, float>	loadDatabase(const std::string file) {

	std::map<std::string, float>	db;
	std::ifstream					ifs(file);
	std::string						content;
	std::string						key;
	std::string						value;

	if (ifs.is_open()) {

		getline(ifs, content, '\n');
		while (getline(ifs, content, '\n')) {
			if (content.find_first_of(",") == std::string::npos) {
				ifs.close();
				std::cerr << "Error: could not identify key and value from content" << std::endl;
				exit (1);
			}
			key = content.substr(0, content.find(","));
			value = content.substr(content.find(",") + 1);
			try {
				db.insert(std::pair<std::string, float>(key, std::stof(value)));
			} catch (const std::exception &e) {
				std::cerr << "Wrong data => " << content << std::endl;
			}
		}
		ifs.close();

	} else {
		std::cerr << "Error: could not open " << file << std::endl;
		exit (1);
	}
	return (db);

}

void	BitcoinExchange::bitcoinExchange(std::string file) {

	std::map<std::string, float>			db = loadDatabase("data.csv");
	std::map<std::string, float>::iterator	it;
	std::ifstream	ifs(file);
	std::string		content;
	std::string		key;
	std::string		value;
	float			num;

	if (ifs.is_open()) {

		getline(ifs, content, '\n');
		while (getline(ifs, content, '\n')) {
			if (content.find_first_of("|") == std::string::npos)
				std::cerr << "Error: bad input => " << content << std::endl;
			else {
				key = content.substr(0, content.find(" | "));
				value = content.substr(content.find(" | ") + 3);
				try {
					if (validDate(key) || validValue(value)){
						it = db.find(previousDate(key, db));
						num = it->second * std::stof(value);
						if (validValue(num))
							std::cout << key << " => " << value << " = " << num << std::endl;
					}
				} catch (const std::exception &e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
			}
		}
		ifs.close();

	} else {
		std::cerr << "Error: could not open file" << std::endl;
		exit (1);
	}

}