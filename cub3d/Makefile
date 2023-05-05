NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
GNL = libft/get_next_line
FLGS = -Wall -Wextra -Werror
MLX = #-l mlx -framework openGL -framework AppKit

$(NAME):
	make -C libft
	gcc $(SRC) $(FLGS) -c $(MLX)
	gcc $(OBJ) -o $(NAME) libft/libft.a

all : $(NAME)

clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all
