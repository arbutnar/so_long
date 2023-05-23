NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
GNL = libft/get_next_line
FLGS = #-Wall -Wextra -Werror
MLX = -l mlx -lGL

$(NAME):
	make -C minilibx
	make -C libft
	gcc $(SRC) $(FLGS) -c $(MLX)
	gcc $(OBJ) -o $(NAME) libft/libft.a minilibx/libmlx.a -lXext -lX11

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all
