/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** second_level.c
*/

#include "../../../include/myrpg.h"
#include "../../../include/level2.h"

int level2(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    int time_set = 100;

    if (LVL2_STRUCT == NULL)
        return (84);
    if (checktime(game, time_set) == sfTrue) {
        open_map(game, window, anim);
        animation_cycle(anim);
    }
    return (0);
}