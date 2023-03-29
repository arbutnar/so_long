NAME = phonebook
SRC = *.cpp
FLG = -Wall -Wextra -Werror

$(NAME):
	c++ $(FLG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all