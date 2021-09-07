##
## EPITECH PROJECT, 2020
## my_sokoban
## File description:
## Makefile
##

CC	= gcc

DEBUG	=	-g

RM	= rm -f

CFLAGS = -I./include -L./lib -lmy -g

CFLAGS += -Wall -Wextra

SRCS	=	src/array_handling.c	\
			src/display_map.c	\
			src/get_stats.c	\
			src/main.c	\
			src/open_map.c	\
			src/check_map.c	\
			src/check_return.c	\
			src/usage.c	\
			src/move_player.c	\
			src/get_player_pos.c	\
			src/win_lose.c	\

OBJS	= $(SRCS:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

lib:
	$(MAKE) -C lib

$(NAME):	lib		$(OBJS)
	$(CC) $(DEBUG) -o $(NAME) $(OBJS) $(CFLAGS) -lncurses

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib

re: fclean all
	$(MAKE) re -C lib

.PHONY: lib all clean fclean re