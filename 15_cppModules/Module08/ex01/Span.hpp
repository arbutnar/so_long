/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:49:02 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/22 23:30:18 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int	N;
		unsigned int	index;
		std::vector<int> v;

	public:
		class Overflow;
		class SpanNotFound;

		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);

		void	addNumber(int num);
		void	printVec();
		//int	shortestSpan();
		int	longestSpan();
};