/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "level2.h"
#include "level3.h"

#define LVL2_STRUCT game->lvl_struct
#define LVL3_STRUCT game->lvl3_struct
#define MUSIC game->music
#define QUEST game->quest

typedef struct game_s
{
    struct image_template *image;
    lvl2_t *lvl_struct;
    lvl3_t *lvl3_struct;
    struct text *text;
    struct menu *menu;
    struct sound *music;
    struct quest *quest;
    struct ennemy *ennemy;

    int scene_idx;
    int scene2_idx;
    int lvl3_scene_idx;
    int sound;
    int w;
    int h;

    sfClock *clock;

    int player_choice;
    int endgame;

    int which_ennemy;
    int which_scene;

    sfColor menu_color;
    sfColor m_menu_color;

    sfTexture *t_last[2];
    sfSprite *last_screen;
} game_t;

typedef struct anim_s
{
    int current_step;
    int check_stop;

    sfVector2f pos;
    sfVector2f hitbox_pos;
    sfVector2f hitbox_size;

    sfTexture *up_texture;
    sfTexture *down_texture;
    sfTexture *left_texture;
    sfTexture *right_texture;

    sfRectangleShape *sprite_hitbox;

    sfIntRect rect_left;
    sfIntRect rect_right;
    sfIntRect rect_down;
    sfIntRect rect_up;

    sfSprite *move;
} anim_t;

struct text
{
    sfFont *police_char;
    sfText *g_play;
    sfText *g_resume;
    sfText *g_exit;
    sfText *p_exit;
};

struct menu
{
    sfRectangleShape *play;
    sfRectangleShape *exit;

    sfRectangleShape *p_resume;
    sfRectangleShape *p_exit;

    sfTexture *t_back;
    sfSprite *background;

    sfRenderStates *b_play;
    sfRenderStates *b_exit;
    sfRenderStates *b_resume;

    sfVector2f size;
};

struct sound
{
    sfMusic *battle;
    sfMusic *attack;
    sfMusic *theme;
};

struct quest
{
    sfRectangleShape *hud;
    sfTexture *t_hp[3];
    sfSprite *hp_player;
    sfText *quest;
};

struct ennemy
{
    sfTexture *t_mob[5];
    sfSprite *mob[5];
    sfVector2f pos[5];
};

sfIntRect initRect(sfTexture *texture, sfIntRect target, anim_t *anim);
void move_condition(anim_t *anim, sfRenderWindow *window, game_t *game);
sfBool checktime(game_t *game, int time_set);
void next_step(anim_t *anim, sfIntRect *rect, sfSprite *sprite);
int init_textures(anim_t *anim);
int set_base_lr_sprite(anim_t *anim, sfRenderWindow *window);
int set_base_ud_sprite(anim_t *anim, sfRenderWindow *window);
void sprite_display(sfSprite *sprite, sfTexture *texture, sfIntRect rect, \
sfVector2f pos);
int move_lr_sprite(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set);
int move_ud_sprite(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set);
int left_movement(anim_t *ani, sfRenderWindow *window, game_t *game, \
int time_set);
int right_movement(anim_t *ani, sfRenderWindow *window, game_t *game, \
int time_set);
int up_movement(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set);
int down_movement(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set);

void menu(game_t *game, sfRenderWindow *window);
void mouse_gestion_menu(game_t *game, sfRenderWindow *window);
int init_menu(game_t *game);
int init_menu2(game_t *game);
void do_pause(game_t *game, sfRenderWindow *window);
void mouse_gestion_pause(game_t *game, sfRenderWindow *window);
int init_pause(game_t *game);
void handle_buttons_menu(game_t *game, sfRenderWindow *window);
void handle_buttons_pause(game_t *game, sfRenderWindow *window);
int init_texts_pause(game_t *game);
int init_texts_menu(game_t *game);
int init_menu_var(game_t *game);

int init_quest(game_t *game);
void print_quest(game_t *game, int player_life, sfRenderWindow *window);

void print_ennemy(game_t *game, sfRenderWindow *window);
void if_ennemy(game_t *game, sfRenderWindow *window);
int init_ennemy_pos(game_t *game);

#endif /* STRUCT_H_ */