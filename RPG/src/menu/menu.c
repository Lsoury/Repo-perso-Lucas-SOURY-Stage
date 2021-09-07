/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** menu.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int init_menu2(game_t *game)
{
    sfRectangleShape_setOutlineThickness(game->menu->play, 2);
    sfRectangleShape_setOutlineThickness(game->menu->exit, 2);
    sfRectangleShape_setOutlineColor(game->menu->play, sfBlack);
    sfRectangleShape_setOutlineColor(game->menu->exit, sfBlack);
    sfSprite_setTexture(game->menu->background, game->menu->t_back, sfFalse);
    sfSprite_setPosition(game->menu->background, (sfVector2f) {0, 0});
    sfSprite_setScale(game->menu->background, (sfVector2f) {1.92, 1.46});
    if (init_texts_menu(game) == 1)
        return (1);
}

int init_menu(game_t *game)
{
    sfVector2f p_pos = {1920 / 4 + 75, 1080 / 2 - game->menu->size.y / 2};
    sfVector2f e_pos = {p_pos.x * 2, p_pos.y};

    game->menu->play = sfRectangleShape_create();
    game->menu->exit = sfRectangleShape_create();
    game->menu->t_back = \
    sfTexture_createFromFile("ressources/Battle_sprites/Grassland.png", \
    sfFalse);
    game->menu->background = sfSprite_create();
    if (game->menu->play == NULL || game->menu->exit == NULL || \
    game->menu->t_back == NULL || game->menu->background == NULL)
        return (1);
    sfRectangleShape_setPosition(game->menu->play, p_pos);
    sfRectangleShape_setPosition(game->menu->exit, e_pos);
    sfRectangleShape_setSize(game->menu->play, game->menu->size);
    sfRectangleShape_setSize(game->menu->exit, game->menu->size);
    sfRectangleShape_setFillColor(game->menu->play, game->menu_color);
    sfRectangleShape_setFillColor(game->menu->exit, game->menu_color);
    if (init_menu2(game) == 1)
        return (1);
    return (0);
}

void mouse_gestion_menu(game_t *game, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f play_button = sfRectangleShape_getPosition(game->menu->play);
    sfVector2f exit_button = sfRectangleShape_getPosition(game->menu->exit);

    if ((cursor.x >= play_button.x) && \
    (cursor.x <= play_button.x + game->menu->size.x) && \
    (cursor.y >= play_button.y) && \
    (cursor.y <= play_button.y + game->menu->size.y))
        sfRectangleShape_setFillColor(game->menu->play, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(game->menu->play, game->menu_color);
    if ((cursor.x >= exit_button.x) && \
    (cursor.x <= exit_button.x + game->menu->size.x) && \
    (cursor.y >= exit_button.y) && \
    (cursor.y <= exit_button.y + game->menu->size.y))
        sfRectangleShape_setFillColor(game->menu->exit, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(game->menu->exit, game->menu_color);
}

void menu(game_t *game, sfRenderWindow *window)
{
    mouse_gestion_menu(game, window);
    handle_buttons_menu(game, window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->menu->background, NULL);
    sfRenderWindow_drawRectangleShape(window, game->menu->play, \
                                        game->menu->b_play);
    sfRenderWindow_drawRectangleShape(window, game->menu->exit, \
                                        game->menu->b_exit);
    sfRenderWindow_drawText(window, game->text->g_play, NULL);
    sfRenderWindow_drawText(window, game->text->g_exit, NULL);
    sfRenderWindow_display(window);
}