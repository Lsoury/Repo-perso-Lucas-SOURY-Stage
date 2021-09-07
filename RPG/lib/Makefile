##
## EPITECH PROJECT, 2020
## B-MUL-200-BDX-2-1-myrpg-lucas.soury
## File description:
## Makefile
##

SRC	=	count_lines.c 		 	\
		count_char_on_line.c 	\
		my_strlen.c 			\
		my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc  $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean