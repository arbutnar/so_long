/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:27:14 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/24 19:27:15 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	MutantStack<int> ms;

	ms.push(5);
	ms.push(15);
	ms.push(25);
	ms.push(35);

	ms.top();
	std::cout << ms.size() << std::endl;
	ms.pop();
	std::cout << ms.size() << std::endl;
	ms.top();


	return 0;
}