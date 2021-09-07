/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** hit.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void next_sprite(battle_t *fight)
{
    if (fight->current_step >= 5) {
        fight->current_step = -1;
        fight->rect.left = 0;
    } else if (fight->current_step < 5) {
        fight->rect.left = fight->rect.width * fight->current_step;
        fight->current_step++;
        sfSprite_setTextureRect(fight->attack, fight->rect);
    }
}

void draw_attack(battle_t *fight, sfRenderWindow *window)
{
    next_sprite(fight);
    if (fight->which_attack != 0) {
        sfRenderWindow_drawSprite(window, fight->player, NULL);
        if (fight->current_step % 2 == 1) {
            sfRenderWindow_drawSprite(window, fight->ennemy, NULL);
            sfRenderWindow_display(window);
        }
    } else if (fight->which_attack == 0) {
        sfRenderWindow_drawSprite(window, fight->ennemy, NULL);
        if (fight->current_step % 2 == 1) {
            sfRenderWindow_drawSprite(window, fight->player, NULL);
            sfRenderWindow_display(window);
        }
    }
    sfRenderWindow_drawSprite(window, fight->attack, NULL);
    sfRenderWindow_display(window);
}