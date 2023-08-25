/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:27:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/24 19:48:37 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack: public std::stack<T> {

    public:
        MutantStack() {
            std::cout << "MutantSatck default constructor called\n";
        }
        MutantStack(const MutantStack &src) {
            std::cout << "MutantSatck copy constructor called\n";
            *this = src;
        }
        ~MutantStack() {
            std::cout << "MutantSatck deconstructor called\n";
        }

        MutantStack &operator=(const MutantStack &src);        
};