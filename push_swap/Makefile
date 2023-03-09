NAME = push_swap
BNS = checker
SRC = main.c initializer.c lis.c utility.c swap.c rotate.c push.c rev_rotate.c go_away.c algorithm.c checks.c
SRC_BNS = checker.c initializer.c utility.c swap.c push.c rotate.c rev_rotate.c checks.c
OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)
FLG = -Wall -Wextra -Werror -c

$(NAME):
	make -C libft
	gcc $(SRC) $(FLG)
	gcc $(OBJ) -o $(NAME) libft/libft.a

bonus:
	make -C libft
	gcc $(SRC_BNS) $(FLG)
	gcc $(OBJ_BNS) -o $(BNS) libft/libft.a

all: $(NAME) bonus

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BNS)

fclean:	clean
	make fclean -C libft
	rm -rf $(NAME)
	rm -rf $(BNS)

re:	fclean all