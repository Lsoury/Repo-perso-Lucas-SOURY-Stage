/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** print_quest.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void print_quest(game_t *game, int player_life, sfRenderWindow *window)
{
    if (player_life > 300 && player_life <= 700)
        sfSprite_setTexture(QUEST->hp_player, QUEST->t_hp[1], sfFalse);
    else if (player_life > 700)
        sfSprite_setTexture(QUEST->hp_player, QUEST->t_hp[0], sfFalse);
    else
        sfSprite_setTexture(QUEST->hp_player, QUEST->t_hp[2], sfFalse);
    sfRenderWindow_drawRectangleShape(window, QUEST->hud, NULL);
    sfRenderWindow_drawText(window, QUEST->quest, NULL);
    sfRenderWindow_drawSprite(window, QUEST->hp_player, NULL);
    sfRenderWindow_display(window);
}