# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 05:59:15 by arbutnar          #+#    #+#              #
#    Updated: 2022/02/16 14:39:08 by arbutnar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRCS =	 *.c
OBJS =	$(SRCS:.c=.o)
HDRS =	ft_printf.h
FLAGS =	-Wall -Wextra -Werror

$(NAME):
		gcc -c -I $(FLAGS) $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus: all

all: 	$(NAME)

clean:	
		rm -f $(OBJS)
	
fclean:	clean
		rm -f $(NAME)
	
re:		fclean all

.PHONY: all clean fclean re
