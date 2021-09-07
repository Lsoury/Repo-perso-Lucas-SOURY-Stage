/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** scenes_handling.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int scene_handling(game_t *game, sfRenderWindow *window, \
anim_t *anim, battle_t *fight)
{
    if (game->which_ennemy == -1) {
        if (game->scene_idx == 0) {
            level1(game, window, anim);
        } else if (game->scene_idx == 1) {
            level2(game, window, anim);
        } else {
            level3(game, window, anim);
        }
        print_ennemy(game, window);
        if_ennemy(game, window);
        print_quest(game, fight->life_player, window);
    } else
        if (init_fight(game, fight, window) == 1)
            return (1);
    return (0);
}