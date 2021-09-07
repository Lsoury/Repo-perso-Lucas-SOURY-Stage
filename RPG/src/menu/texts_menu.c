/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** texts_menu.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int init_texts_pause(game_t *game)
{
    sfVector2f pos1 = {1920 / 4 + 130, 1080 / 2 - 25};
    sfVector2f pos2 = {(1920 / 4 - 75) * 3, pos1.y};

    game->text->p_exit = sfText_create();
    game->text->g_resume = sfText_create();
    if (game->text->p_exit == NULL || game->text->g_resume == NULL)
        return (1);
    sfText_setString(game->text->p_exit, "EXIT");
    sfText_setString(game->text->g_resume, "RESUME");
    sfText_setFillColor(game->text->p_exit, sfWhite);
    sfText_setFillColor(game->text->g_resume, sfWhite);
    sfText_setFont(game->text->p_exit, game->text->police_char);
    sfText_setFont(game->text->g_resume, game->text->police_char);
    sfText_setPosition(game->text->g_resume, pos2);
    sfText_setPosition(game->text->p_exit, pos1);
    return (0);
}

int init_texts_menu(game_t *game)
{
    sfVector2f pos = {1920 / 4 + 155, 1080 / 2 - 25};
    sfVector2f pos3 = {(1920 / 4 + 120) * 2, pos.y};

    game->text->g_play = sfText_create();
    game->text->g_exit = sfText_create();
    if (game->text->g_exit == NULL || game->text->g_play == NULL)
        return (1);
    sfText_setFont(game->text->g_play, game->text->police_char);
    sfText_setFont(game->text->g_exit, game->text->police_char);
    sfText_setString(game->text->g_play, "PLAY");
    sfText_setString(game->text->g_exit, "EXIT");
    sfText_setFillColor(game->text->g_play, sfWhite);
    sfText_setFillColor(game->text->g_exit, sfWhite);
    sfText_setPosition(game->text->g_play, pos);
    sfText_setPosition(game->text->g_exit, pos3);
    return (0);
}