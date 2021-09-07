/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** battle_handling.c
*/

#include "../../include/myrpg.h"
#include "../../include/level2.h"

void print_ennemy(game_t *game, sfRenderWindow *window)
{
    if (game->scene_idx == 1) {
        sfRenderWindow_drawSprite(window, game->ennemy->mob[0], NULL);
        sfRenderWindow_drawSprite(window, game->ennemy->mob[1], NULL);
        sfRenderWindow_display(window);
    } else if (game->scene_idx == 2) {
        sfRenderWindow_drawSprite(window, game->ennemy->mob[2], NULL);
        sfRenderWindow_drawSprite(window, game->ennemy->mob[3], NULL);
        sfRenderWindow_drawSprite(window, game->ennemy->mob[4], NULL);
        sfRenderWindow_display(window);
    }
}

void which_ennemy(game_t *game, int const idx)
{
    if (idx == 0)
        game->which_ennemy = 1;
    if (idx == 1)
        game->which_ennemy = 3;
    if (idx == 2)
        game->which_ennemy = 2;
    if (idx == 3)
        game->which_ennemy = 2;
    if (idx == 4)
        game->which_ennemy = 0;
}

void if_ennemy(game_t *game, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);

    if (game->scene_idx == 1) {
        for (int idx = 0; idx != 2; idx++) {
            if (sfMouse_isButtonPressed(sfMouseLeft) && \
            ((cursor.x >= game->ennemy->pos[idx].x && \
            cursor.x <= game->ennemy->pos[idx].x + 100) && \
            (cursor.y >= game->ennemy->pos[idx].y && \
            cursor.y <= game->ennemy->pos[idx].y + 100)))
                which_ennemy(game, idx);
        }
    } else if (game->scene_idx == 2) {
        for (int idx = 2; idx != 5; idx++) {
            if (sfMouse_isButtonPressed(sfMouseLeft) && \
            ((cursor.x >= game->ennemy->pos[idx].x && \
            cursor.x <= game->ennemy->pos[idx].x + 100) && \
            (cursor.y >= game->ennemy->pos[idx].y && \
            cursor.y <= game->ennemy->pos[idx].y + 100)))
                which_ennemy(game, idx);
        }
    }
}