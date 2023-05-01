NAME = cub3d
SRC = *.c
OBJ = $(SRC:.c=.o)
FLGS = #-Wall -Wextra -Werror

$(NAME):
	gcc $(SRC) $(FLGS) -c
	gcc $(OBJ) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
