NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
FLGS = #-Wall -Wextra -Werror
LIBFT = ./libft/libft.a

$(NAME):
	make -C libft
	gcc $(SRC) $(FLGS) -c
	gcc $(OBJ) -o $(NAME) $(LIBFT)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
