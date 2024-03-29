/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:20:13 by aoropeza          #+#    #+#             */
/*   Updated: 2024/01/19 18:39:35 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "\033[33;1m[    SUBJECT TEST    ]\033[0m" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::cout << "\033[33;1m[    LIST TEST    ]\033[0m" << std::endl;
		std::list<int> li;
		li.push_back(5);
		li.push_back(17);
		std::cout << li.back() << std::endl;
		li.pop_back();
		std::cout << li.size() << std::endl;
		li.push_back(3);
		li.push_back(5);
		li.push_back(737);
		li.push_back(0);
		std::list<int>::iterator lit = li.begin();
		std::list<int>::iterator lite = li.end();
		++lit;
		--lit;
		while (lit != lite)
		{
		std::cout << *lit << std::endl;
		++lit;
		}
		std::list<int> sl(li);
	}
	return 0;
}