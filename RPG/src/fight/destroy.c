/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** destroy.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void destroy_hit(game_t *game, battle_t *fight)
{
    sfSprite_destroy(fight->attack);
    sfTexture_destroy(fight->t_attack);
    sfMusic_pause(MUSIC->attack);
    sfMusic_destroy(MUSIC->attack);
}

void destroy_fight(game_t *game, battle_t *fight)
{
    sfSprite_destroy(fight->background);
    sfSprite_destroy(fight->player);
    sfSprite_destroy(fight->ennemy);
    sfSprite_destroy(fight->hp_ennemy_bar);
    sfSprite_destroy(fight->hp_player_bar);
    sfTexture_destroy(fight->t_background);
    sfTexture_destroy(fight->t_player);
    sfTexture_destroy(fight->t_ennemy);
    sfTexture_destroy(fight->t_hp_bar[0]);
    sfTexture_destroy(fight->t_hp_bar[1]);
    sfTexture_destroy(fight->t_hp_bar[2]);
    sfMusic_pause(MUSIC->battle);
    sfMusic_destroy(MUSIC->battle);
    sfText_destroy(HUD->n_attack1);
    sfText_destroy(HUD->n_attack2);
    sfText_destroy(HUD->n_attack3);
    sfText_destroy(HUD->n_attack4);
    sfRectangleShape_destroy(HUD->attack1);
    sfRectangleShape_destroy(HUD->attack2);
    sfRectangleShape_destroy(HUD->attack3);
    sfRectangleShape_destroy(HUD->attack4);
}