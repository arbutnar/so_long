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
class MutantStack {

    private:
        std::stack<T> stack;

    public:
        MutantStack() {
            std::cout << "MutantSatck default constructor called\n";
        }
        MutantStack<T>(const MutantStack<T> &src) {
            std::cout << "MutantSatck copy constructor called\n";
            *this = src;
        }
        ~MutantStack() {
            std::cout << "MutantSatck deconstructor called\n";
        }

        MutantStack<T> &operator=(const MutantStack<T> &src);
        bool empty() {
            return (stack.empty());
        }
        int size() {
           return (stack.size());
        }
        void    top() {
            std::cout << stack.top() << std::endl;
        }
        void    push(T num) {
            stack.push(num);
        }
        void    pop() {
            stack.pop();
        }
        
};