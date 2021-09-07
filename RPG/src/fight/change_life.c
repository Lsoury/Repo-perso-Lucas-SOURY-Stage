/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** change_life.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void change_ennemy_life(int which_ennemy, battle_t *fight)
{
    if (which_ennemy == 0) {
        if (fight->life_ennemy > 500 && fight->life_ennemy <= 1000)
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[1], sfFalse);
        else if (fight->life_ennemy > 1000)
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[0], sfFalse);
        else
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[2], sfFalse);
    } else {
        if (fight->life_ennemy > 150 && fight->life_ennemy <= 350)
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[1], sfFalse);
        else if (fight->life_ennemy > 350)
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[0], sfFalse);
        else
            sfSprite_setTexture(fight->hp_ennemy_bar, \
            fight->t_hp_bar[2], sfFalse);
    }
}

void change_life(int which_ennemy, battle_t *fight, sfRenderWindow *window)
{
    if (fight->life_player > 300 && fight->life_player <= 700)
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[1], sfFalse);
    else if (fight->life_player > 700)
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[0], sfFalse);
    else
        sfSprite_setTexture(fight->hp_player_bar, fight->t_hp_bar[2], sfFalse);
    change_ennemy_life(which_ennemy, fight);
    sfRenderWindow_drawSprite(window, fight->hp_player_bar, NULL);
    sfRenderWindow_drawSprite(window, fight->hp_ennemy_bar, NULL);
}