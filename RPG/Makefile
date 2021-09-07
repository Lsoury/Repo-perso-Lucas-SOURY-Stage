##
## EPITECH PROJECT, 2020
## MyDefender
## File description:
## Makefile
##

CC	=	gcc -g

LDLIBS	=	-L./lib -I include -lmy -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

SRC	=	src/main/main.c	\
		src/window/create_window.c	\
		src/wallpaper/set_image.c	\
		src/clock_handling/clock.c	\
		src/malloc_handling/malloc_handling.c	\
		src/hitbox_handling/create_hitbox.c	\
		src/levels/1lvl/first_level_hitboxes/set_first_level_hitboxes.c	\
		src/levels/1lvl/first_level_hitboxes/first_hitboxes_data.c	\
		src/levels/1lvl/first_level_hitboxes/border_hitboxes.c	\
		src/levels/1lvl/first_level.c	\
		src/levels/2lvl/second_level.c	\
		src/levels/2lvl/map/map_handling.c	\
		src/levels/2lvl/map/create_graphic_map.c	\
		src/levels/2lvl/map/lv_2_sprite_anim.c	\
		src/levels/3lvl/map/create_lv3_graphic_map.c	\
		src/levels/3lvl/map/lv3_map_handling.c	\
		src/levels/3lvl/map/lv_3_sprite_anim.c	\
		src/levels/3lvl/third_level.c	\
		src/scenes_handling/scenes_handling.c	\
		src/init.c	\
		src/sprite_animation/move_condition.c	\
		src/sprite_animation/sprite_anim.c	\
		src/sprite_animation/set_base_sprite.c	\
		src/sprite_animation/move_functions.c	\
		src/sprite_animation/first_screen_mvt.c	\
		src/sprite_animation/animation_cycle.c	\
		src/menu/destroy.c 				\
		src/menu/init_menu.c 			\
		src/menu/menu.c 				\
		src/menu/pause.c   				\
		src/menu/switch_scene.c 		\
		src/menu/texts_menu.c 			\
		src/fight/background.c \
		src/fight/battle.c \
		src/fight/create_hud.c \
		src/fight/hit.c \
		src/fight/init_buttons.c \
		src/fight/init_fight.c \
		src/fight/init_hits.c \
		src/fight/mouse_gestion.c \
		src/fight/destroy.c \
		src/fight/init_life.c \
		src/fight/change_life.c \
		src/quest/init_quest.c \
		src/quest/print_quest.c \
		src/music/init_music.c \
		src/destroy_all.c \
		src/battle_handling/init_ennemies.c \
		src/battle_handling/battle_handling.c \
		src/end_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

lib:
	@$(MAKE)	-C lib

$(NAME):	lib $(OBJ)
	$(CC)	-o	$(NAME)	$(OBJ)	$(LDLIBS)

clean:
	rm -rf $(OBJ)
	rm -f vgcore*
	@$(MAKE) clean	-C lib

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean	-C lib

re: fclean all
	@$(MAKE) re	-C lib

.PHONY: all lib clean fclean re