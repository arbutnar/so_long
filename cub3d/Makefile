NAME = cub3d
SRC = *.c
FLG = -Wall -Wextra -Werror
LIB = libft.a
MLX = libmlx.dylib

$(NAME):
		make -C libft && mv libft/libft.a .
		make -C mlx && mv mlx/libmlx.dylib .
		gcc $(SRC) -o $(NAME) $(LIB) $(MLX)
		

clean:
		rm -rf $(NAME)
		rm -rf $(LIB)
		rm -rf $(MLX)

fclean:	clean
	make fclean -C libft
	make clean -C mlx

all:	$(NAME)

re:		fclean all