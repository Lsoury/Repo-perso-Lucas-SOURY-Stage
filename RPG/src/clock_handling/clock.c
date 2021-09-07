/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** clock.c
*/

#include "../../include/struct.h"

sfBool checktime(game_t *game, int time_set)
{
    sfTime time;

    time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asMilliseconds(time) > time_set) {
        sfClock_restart(game->clock);
        return sfTrue;
    }
    return sfFalse;
}