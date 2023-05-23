NAME = philo_bonus
SRC = *.c
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror -c #-fsanitize=address -g3

$(NAME):
	gcc $(FLG) $(SRC)
	gcc $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all