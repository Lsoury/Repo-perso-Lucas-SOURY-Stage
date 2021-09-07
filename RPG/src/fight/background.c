/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** background.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void draw_background(battle_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->background, NULL);
}