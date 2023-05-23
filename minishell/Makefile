NAME = minishell

FLAGS = -g -Wall -Werror -Wextra

INCS =	./global.h ./executor.h ./parser/parser.h ./lexer.h \
		./glob.h

SRCS =	./signals.c \
		./main.c \
		./free_structs.c \
		./init.c \
		./prompt.c \
		./lexer.c \
		./lexer_splitter.c \
		./lexer_syntax.c \
		./parser/parser.c \
		./parser/ps_utils.c \
		./parser/ps_write.c \
		./parser/ps_utils_2.c \
		./parser/ps_flags_red.c \
		./executor.c \
		./ft_execv.c \
		./pipe.c \
		./redirpipe.c \
		./redir.c \
		./executor_process.c \
		./expander.c \
		./expander_utils.c \
		./redirector.c \
		./builtin/unset.c \
		./builtin/cd.c \
		./builtin/echo.c \
		./builtin/env.c \
		./builtin/pwd.c \
		./builtin/exit.c \
		./builtin/export.c \
		./builtin/export2.c \
		./builtin/export3.c \
		./builtin/export_utils2.c \
		./dirty.c

READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib


OBJS =	$(SRCS:.c=.o)

%.o:%.c $(INCS)
		gcc $(FLAGS) -I$(READLINE)  -c $< -o $@
%.o:%.c $(INCS)
		gcc $(FLAGS) -I$(READLINE_DIR)/include  -c $< -o $@

LIBFT=./libft/libft.a

 #READLINE = -L/usr/include -lreadline -L$(HOME)/.brew/opt/readline/lib \
 				-I$(HOME)/.brew/opt/readline/include

$(NAME): $(OBJS) $(LIBFT)
		gcc $(FLAGS) $(SRCS) $(LIBFT) $(READLINE_LIB) -o $(NAME)
#$(READLINE)

$(LIBFT):
		$(MAKE) -C ./libft/

all:	$(NAME)

clean:
		rm -f *.o
		rm -f main/*.o
		rm -f parser/*.o
		rm -f lexer/*.o
		rm -f builtin/*.o
		rm -f expander/*.o
		rm -f executor/*.o
		$(MAKE) clean -C ./libft

fclean: clean
		rm -f $(NAME)
		$(MAKE) fclean -C ./libft

re: fclean all
