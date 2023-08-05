NAME = so_long
SRC = main.c matrice.c matrice2.c utils.c movements.c updates.c movenemy.c check.c open.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/*.c
FLAG = -Wall -Werror -Wextra -g
GET_NEXT_LINE = get_next_line/get_next_line.h
PRINTF = ft_printf/ft_printf.h
PRINTF = ft_printf/ft_printf.h
MLX_FLAG = -l mlx -framework openGL -framework AppKit

$(NAME):
		gcc $(SRC) -o $(NAME)  $(MLX_FLAG)

all:	$(NAME)

clean:
			rm -f $(NAME)

fclean:	clean

re:		fclean all

.PHONY:	all clean fclean re