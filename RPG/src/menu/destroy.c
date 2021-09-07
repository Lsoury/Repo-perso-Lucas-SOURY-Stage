/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** destroy.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void destroy_texts_pause(game_t *game)
{
    sfText_destroy(game->text->g_exit);
    sfText_destroy(game->text->g_resume);
}

void destroy_texts_menu(game_t *game)
{
    sfText_destroy(game->text->g_exit);
    sfText_destroy(game->text->g_play);
}

void destroy_rect_menu(game_t *game)
{
    sfRectangleShape_destroy(game->menu->play);
    sfRectangleShape_destroy(game->menu->exit);
}

void destroy_rect_pause(game_t *game)
{
    sfRectangleShape_destroy(game->menu->p_exit);
    sfRectangleShape_destroy(game->menu->p_resume);
}