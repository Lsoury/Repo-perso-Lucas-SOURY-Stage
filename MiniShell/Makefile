##
## EPITECH PROJECT, 2020
## bootstrap
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

CFLAGS	=	-I./include
LDLIBS	=	-L./lib -lmy

SRC	=	src/builtin/cd_call.c	\
		src/builtin/env_call.c	\
		src/builtin/setenv_call.c	\
		src/builtin/unsetenv_call.c	\
		src/main.c	\
		src/wait_process.c	\
		src/print_arr.c	\
		src/env_handling.c	\
		src/ptr_functions_arr.c	\
		src/space_handling.c	\
		src/free_env.c	\
		src/system_command.c	\
		src/parser.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

lib:
	$(MAKE) -C lib

$(NAME):	lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C lib

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib

re:	fclean all

.PHONY: re fclean clean all lib