/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:57:48 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/31 16:02:36 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

enum Status { charType, intType, floatType, doubleType, invalidType };

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