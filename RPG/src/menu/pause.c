/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** pause.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int init_pause(game_t *game)
{
    sfVector2f p_pos = {1920 / 4 + 50, 1080 / 2 - game->menu->size.y / 2};
    sfVector2f e_pos = {(1920 / 4 - 100) * 3, p_pos.y};

    game->menu->p_exit = sfRectangleShape_create();
    game->menu->p_resume = sfRectangleShape_create();
    if (game->menu->p_exit == NULL || game->menu->p_resume == NULL)
        return (1);
    sfRectangleShape_setPosition(game->menu->p_exit, p_pos);
    sfRectangleShape_setPosition(game->menu->p_resume, e_pos);
    sfRectangleShape_setSize(game->menu->p_exit, game->menu->size);
    sfRectangleShape_setSize(game->menu->p_resume, game->menu->size);
    sfRectangleShape_setFillColor(game->menu->p_exit, game->menu_color);
    sfRectangleShape_setFillColor(game->menu->p_resume, game->menu_color);
    sfRectangleShape_setOutlineThickness(game->menu->p_exit, 2);
    sfRectangleShape_setOutlineThickness(game->menu->p_resume, 2);
    sfRectangleShape_setOutlineColor(game->menu->p_exit, sfBlack);
    sfRectangleShape_setOutlineColor(game->menu->p_resume, sfBlack);
    if (init_texts_pause(game) == 1)
        return (1);
    return (0);
}

void mouse_gestion_pause(game_t *game, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f exit_button = sfRectangleShape_getPosition(game->menu->p_exit);
    sfVector2f r_button = sfRectangleShape_getPosition(game->menu->p_resume);

    if ((cursor.x >= exit_button.x) && \
    (cursor.x <= exit_button.x + game->menu->size.x) && \
    (cursor.y >= exit_button.y) && \
    (cursor.y <= exit_button.y + game->menu->size.y))
        sfRectangleShape_setFillColor(game->menu->p_exit, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(game->menu->p_exit, game->menu_color);
    if ((cursor.x >= r_button.x) && \
    (cursor.x <= r_button.x + game->menu->size.x) && \
    (cursor.y >= r_button.y) && \
    (cursor.y <= r_button.y + game->menu->size.y))
        sfRectangleShape_setFillColor(game->menu->p_resume, \
        game->m_menu_color);
    else
        sfRectangleShape_setFillColor(game->menu->p_resume, game->menu_color);
}

void do_pause(game_t *game, sfRenderWindow *window)
{
    mouse_gestion_pause(game, window);
    handle_buttons_pause(game, window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->menu->background, NULL);
    sfRenderWindow_drawRectangleShape(window, game->menu->p_exit, \
    game->menu->b_exit);
    sfRenderWindow_drawRectangleShape(window, game->menu->p_resume, \
    game->menu->b_resume);
    sfRenderWindow_drawText(window, game->text->p_exit, \
    game->menu->b_exit);
    sfRenderWindow_drawText(window, game->text->g_resume, \
    game->menu->b_resume);
    sfRenderWindow_display(window);
}