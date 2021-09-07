/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** third_level.c
*/

#include "../../../include/myrpg.h"
#include "../../../include/level3.h"

int level3(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    int time_set = 100;

    if (LVL3_STRUCT == NULL)
        return (84);
    if (checktime(game, time_set) == sfTrue)
        lv3_open_map(game, window, anim);
        animation_cycle(anim);
    return (0);
}