NAME = zombie
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
FLG = -Wall -Wextra -Werror -c

$(NAME):
	c++ $(FLG) $(SRC)
	c++ $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all