/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** move_functions.c
*/

#include "../../include/struct.h"

int move_lr_sprite(anim_t *ani, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (game->scene_idx == 0) {
        left_movement(ani, window, game, time_set);
        right_movement(ani, window, game, time_set);
    }
    return (0);
}

int move_ud_sprite(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (game->scene_idx == 0) {
        up_movement(anim, window, game, time_set);
        down_movement(anim, window, game, time_set);
    }
    return (0);
}