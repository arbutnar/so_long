NAME = philo
SRC = *.c
OBJ = $(SRC:.c=.o)
FLG = -Wall -Wextra -Werror -c

$(NAME):
	gcc $(SRC) -c
	gcc $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all