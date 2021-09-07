/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** myrpg.h
*/

#ifndef MYRPG_H_
#define MYRPG_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "struct.h"
#include "templates/fight.h"
#include "mylib.h"
#include "level2.h"
#include "level3.h"

int open_window(game_t *game, sfRenderWindow *window, sfEvent event);
sfRenderWindow *create_window(sfRenderWindow *window);
int game_status(game_t *game, sfRenderWindow *window);
char **fill_tab(char *str);

int level1(game_t *game, sfRenderWindow *window, anim_t *anim);

int level2(game_t *game, sfRenderWindow *window, anim_t *anim);
int open_map(game_t *game, sfRenderWindow *window, anim_t *anim);
int create_map(game_t *game, sfRenderWindow *window, anim_t *anim);
int lv2_sprite_animation(anim_t *anim, game_t *game, sfRenderWindow *window);

int level3(game_t *game, sfRenderWindow *window, anim_t *anim);
int lv3_open_map(game_t *game, sfRenderWindow *window, anim_t *anim);
int lv3_create_map(game_t *game, sfRenderWindow *window, anim_t *anim);
int lv3_sprite_animation(anim_t *anim, game_t *game, sfRenderWindow *window);

int init_array(game_t *game, sfRenderWindow *window, sfEvent event);
int init_all(game_t *game, battle_t *fight);

int scene_handling(game_t *game, sfRenderWindow *window, \
anim_t *anim, battle_t *fight);

int read_settings(game_t *game);
int check_nbr(game_t *game);

int init_music_start(game_t *game);
int init_music_field(game_t *game);
int init_music_lose(game_t *game);
int init_music_win(game_t *game);
void destroy_music(game_t *game);
void free_all(game_t *game, battle_t *fight, anim_t *anim);
int animation_cycle(anim_t *anim);
int init_end(game_t *game);
void draw_end(game_t *game, sfRenderWindow *window);
void check_end_game(game_t *game, battle_t *fight);

#endif /* MYRPG_H_ */