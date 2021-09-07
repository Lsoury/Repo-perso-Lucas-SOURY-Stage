/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** fight.h
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../myrpg.h"

#define HUD fight->hud

struct buttons
{
    sfRectangleShape *attack1;
    sfRectangleShape *attack2;
    sfRectangleShape *attack3;
    sfRectangleShape *attack4;

    sfText *n_attack1;
    sfText *n_attack2;
    sfText *n_attack3;
    sfText *n_attack4;

    sfVector2f size;
    sfVector2f pos;
};

typedef struct fight
{
    struct buttons *hud;

    int in_fight;

    int bonus_attack;

    int life_player;
    int life_ennemy;

    int which_attack;
    int current_step;

    char *filepath[4];

    sfSprite *player;
    sfSprite *ennemy;
    sfSprite *attack;
    sfSprite *background;
    sfSprite *hp_player_bar;
    sfSprite *hp_ennemy_bar;

    sfTexture *t_player;
    sfTexture *t_ennemy;
    sfTexture *t_attack;
    sfTexture *t_background;
    sfTexture *t_hp_bar[3];

    sfVector2f pos_player;
    sfVector2f pos_ennemy;
    sfVector2f pos_attack;
    sfVector2f pos_background;

    sfIntRect rect;
} battle_t;

void draw_background(battle_t *fight, sfRenderWindow *window);
void player_turn(game_t *game, battle_t *fight, sfRenderWindow *window);
void ennemy_turn(game_t *game, battle_t *fight, sfRenderWindow *window);
void do_attack(battle_t *fight, sfRenderWindow *window, int damage, int who);
void set_text_pos(battle_t *fight);
int create_text_hud(game_t *game, battle_t *fight);
void create_hud2(game_t *game, battle_t *fight);
int create_hud(game_t *game, battle_t *fight);
void next_sprite(battle_t *fight);
void draw_attack(battle_t *fight, sfRenderWindow *window);
int other_textures(game_t *game, battle_t *fight);
int create_texture(game_t *game, battle_t *fight);
int create_sprite(game_t *game, battle_t *fight);
int battle(game_t *game, battle_t *fight, sfRenderWindow *window);
int init_fight(game_t *game, battle_t *fight, sfRenderWindow *window);
void init_create_rect_hit(battle_t *fight);
int create_hit(game_t *game, battle_t *fight, int who);
int apply_hit(game_t *game, battle_t *fight, int who, sfRenderWindow *window);
void select_attack2(game_t *game, battle_t *fight, sfRenderWindow *window, \
sfVector2i cursor);
void select_attack(game_t *game, battle_t *fight, sfRenderWindow *window);
void mouse_gestion2(game_t *game, battle_t *fight, sfRenderWindow *window, \
sfVector2i cursor);
void mouse_gestion(game_t *game, battle_t *fight, sfRenderWindow *window);
void draw_buttons(battle_t *fight, sfRenderWindow *window);
void destroy_fight(game_t *game, battle_t *fight);
void destroy_hit(game_t *game, battle_t *fight);
void change_life(int which_ennemy, battle_t *fight, sfRenderWindow *window);
int init_life(game_t *game, battle_t *fight);

#endif