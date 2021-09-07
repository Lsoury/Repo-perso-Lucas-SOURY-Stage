/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** init_menu.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int init_menu_var(game_t *game)
{
    game->player_choice = 0;
    game->menu->size.x = 250;
    game->menu->size.y = 125;
    game->menu->b_exit = NULL;
    game->menu->b_play = NULL;
    game->menu->b_resume = NULL;
    if (init_menu(game) == 1 || init_pause(game) == 1)
        return (1);
    return (0);
}