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

template <typename T>
class MutantStack {

    private:
        unsigned int size;
        unsigned int *idx;

    public:
        MutantStack(T datatype) {
            std::cout << "MutantSatck default constructor called\n";
        }
        MutantStack<T>(const MutantStack<T> &src) {
            std::cout << "MutantSatck copy constructor called\n";
            *this = src;
        }
        ~MutantStack() {
            std::cout << "MutantSatck deconstructor called\n";
        }

        MutantStack<T> &operator=(const Mutantstack<T> &src);
        bool empty() {

        }
        int size() {
            return (this->size);
        }
        //top
        void    push(T num) {
            this
        }
        //pop

        //iterator
};