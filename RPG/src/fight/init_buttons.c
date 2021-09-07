/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_buttons.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void draw_buttons(battle_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, HUD->attack1, NULL);
    sfRenderWindow_drawRectangleShape(window, HUD->attack2, NULL);
    sfRenderWindow_drawRectangleShape(window, HUD->attack3, NULL);
    sfRenderWindow_drawRectangleShape(window, HUD->attack4, NULL);
    sfRenderWindow_drawText(window, HUD->n_attack1, NULL);
    sfRenderWindow_drawText(window, HUD->n_attack2, NULL);
    sfRenderWindow_drawText(window, HUD->n_attack3, NULL);
    sfRenderWindow_drawText(window, HUD->n_attack4, NULL);
}