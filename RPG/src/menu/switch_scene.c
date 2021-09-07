/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-erwan.baillon
** File description:
** switch_scene.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void handle_buttons_menu(game_t *game, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f play_button = sfRectangleShape_getPosition(game->menu->play);
    sfVector2f exit_button = sfRectangleShape_getPosition(game->menu->exit);

    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= play_button.x) && \
    (cursor.x <= play_button.x + game->menu->size.x) && \
    (cursor.y >= play_button.y) && \
    (cursor.y <= play_button.y + game->menu->size.y)) {
        game->player_choice = 1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= exit_button.x) && \
    (cursor.x <= exit_button.x + game->menu->size.x) && \
    (cursor.y >= exit_button.y) && \
    (cursor.y <= exit_button.y + game->menu->size.y)) {
        game->player_choice = -1;
    }
}

void handle_buttons_pause(game_t *game, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f exit_button = sfRectangleShape_getPosition(game->menu->p_exit);
    sfVector2f r_button = sfRectangleShape_getPosition(game->menu->p_resume);

    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= exit_button.x) && \
    (cursor.x <= exit_button.x + game->menu->size.x) && \
    (cursor.y >= exit_button.y) && \
    (cursor.y <= exit_button.y + game->menu->size.y))
        game->player_choice = -1;
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= r_button.x) && \
    (cursor.x <= r_button.x + game->menu->size.x) && \
    (cursor.y >= r_button.y) && \
    (cursor.y <= r_button.y + game->menu->size.y))
        game->player_choice = 1;
}