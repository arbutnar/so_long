NAME = megaphone
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
FLG = -Wall -Wextra -Werror -c

$(NAME):
	c++ $(SRC) $(FLG)
	c++ $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:		fclean all