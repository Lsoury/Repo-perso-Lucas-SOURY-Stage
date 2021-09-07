/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_life.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int init_hp_ennemy(battle_t *fight)
{
    fight->hp_ennemy_bar = sfSprite_create();

    if (fight->hp_ennemy_bar == NULL)
        return (1);
    sfSprite_setTexture(fight->hp_ennemy_bar, fight->t_hp_bar[0], sfFalse);
    sfSprite_setPosition(fight->hp_ennemy_bar, \
    (sfVector2f) {fight->pos_ennemy.x + 100, fight->pos_ennemy.y - 300});
    sfSprite_setScale(fight->hp_ennemy_bar, (sfVector2f) {0.5, 0.5});
    return (0);
}

int init_hp_player(battle_t *fight)
{
    fight->hp_player_bar = sfSprite_create();

    if (fight->hp_player_bar == NULL)
        return (1);
    if (fight->life_player > 300 && fight->life_player <= 700)
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[1], sfFalse);
    else if (fight->life_player > 700)
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[0], sfFalse);
    else
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[2], sfFalse);
    sfSprite_setPosition(fight->hp_player_bar, \
    (sfVector2f) {fight->pos_player.x + 150, fight->pos_player.y - 300});
    sfSprite_setScale(fight->hp_player_bar, (sfVector2f) {0.5, 0.5});
    return (0);
}

int init_life(game_t *game, battle_t *fight)
{
    fight->t_hp_bar[0] = \
    sfTexture_createFromFile("ressources/life/full_bar.png", NULL);
    fight->t_hp_bar[1] = \
    sfTexture_createFromFile("ressources/life/middle_bar.png", NULL);
    fight->t_hp_bar[2] = \
    sfTexture_createFromFile("ressources/life/low_bar.png", NULL);
    if (fight->t_hp_bar[0] == NULL || fight->t_hp_bar[1] == NULL || \
    fight->t_hp_bar[2] == NULL)
        return (1);
    if (init_hp_ennemy(fight) == 1)
        return (1);
    if (init_hp_player(fight) == 1)
        return (1);
    return (0);
}