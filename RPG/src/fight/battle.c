/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** battle.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void do_attack(battle_t *fight, sfRenderWindow *window, int damage, int who)
{
    if (who == 1) {
        fight->life_ennemy -= damage;
        if (fight->which_attack == 3)
            fight->life_player += damage;
    } else {
        fight->life_player -= damage;
    }
    if (fight->life_player > 1000)
        fight->life_player = 1000;
    fight->current_step = -1;
}

void ennemy_turn(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->player, NULL);
    sfRenderWindow_drawSprite(window, fight->ennemy, NULL);
}

void player_turn(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->player, NULL);
    sfRenderWindow_drawSprite(window, fight->ennemy, NULL);
}