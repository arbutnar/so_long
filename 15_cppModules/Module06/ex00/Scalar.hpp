/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:57:48 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/01 15:04:56 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <float.h>

#ifndef NAN
#define NAN (0.0/0.0)
#endif

enum Status { charType, intType, floatType, doubleType, invalidType };
// enum PseudoFloat { nanf, -inff, +inff };
// enum PseudoDouble { nan, -inf, +inf };

class Scalar {

    private:
        std::string literal;
        Status type;

    public:
        Scalar(char *str);
        Scalar(const Scalar &src);
        Scalar &operator=(const Scalar &src);
        ~Scalar();

        std::string getLiteral();
		char	*toChar(int i);
        int     setStatus(std::string literal);
        void    convert(std::string literal);
};