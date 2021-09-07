##
## EPITECH PROJECT, 2020
## my_sokoban
## File description:
## Makefile
##

SRCS	=	./flags_functions/flag_bin.c \
			./flags_functions/flag_c.c \
			./flags_functions/flag_d.c \
			./flags_functions/flag_i.c \
			./flags_functions/flag_oct.c \
			./flags_functions/flag_s.c \
			./flags_functions/flag_u.c \
			./lib_functions/my_getnbr.c \
			./lib_functions/my_put_nbr.c \
			./lib_functions/my_put_nbrbin.c \
			./lib_functions/my_put_oct.c \
			./lib_functions/my_putchar.c \
			./lib_functions/my_putstr.c \
			./lib_functions/my_unsigned.c \
			./lib_functions/my_strlen.c	\
			./my_printf.c

OBJS	= $(SRCS:.c=.o)

NAME	= libmy.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
