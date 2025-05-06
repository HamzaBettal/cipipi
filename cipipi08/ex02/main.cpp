/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:08 by hbettal           #+#    #+#             */
/*   Updated: 2025/04/30 18:15:43 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::cout << "===========[MutantStack]===========\n";
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
    std::cout << "============[std::list]============\n";
    std::list<int> mstack1;
    mstack1.push_back(5);
    mstack1.push_back(17);
    std::cout << mstack1.back() << std::endl;
    mstack1.pop_back();
    std::cout << mstack1.size() << std::endl;
    mstack1.push_back(3);
    mstack1.push_back(5);
    mstack1.push_back(737);
    mstack1.push_back(0);
    std::list<int>::iterator it1 = mstack1.begin();
    std::list<int>::iterator ite1 = mstack1.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    return 0;
}