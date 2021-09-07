/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** menu.h
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "struct.h"

void destroy_rect_pause(game_t *game);
void destroy_rect_menu(game_t *game);
void destroy_texts_menu(game_t *game);
void destroy_texts_pause(game_t *game);
void menu(game_t *game, sfRenderWindow *window);
void mouse_gestion_menu(game_t *game, sfRenderWindow *window);
void init_menu(game_t *game);
void init_menu2(game_t *game);
void do_pause(game_t *game, sfRenderWindow *window);
void mouse_gestion_pause(game_t *game, sfRenderWindow *window);
void init_pause(game_t *game);
void handle_buttons_menu(game_t *game, sfRenderWindow *window);
void handle_buttons_pause(game_t *game, sfRenderWindow *window);
void init_texts_pause(game_t *game);
void init_texts_menu(game_t *game);

#endif /* MENU_H_ */