/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** mouse_gestion.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void select_attack2(game_t *game, battle_t *fight, sfRenderWindow *window, \
sfVector2i cursor)
{
    sfVector2f t_attack = sfRectangleShape_getPosition(HUD->attack3);
    sfVector2f fth_attack = sfRectangleShape_getPosition(HUD->attack4);

    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= t_attack.x) && \
    (cursor.x <= t_attack.x + HUD->size.x) && \
    (cursor.y >= t_attack.y) && \
    (cursor.y <= t_attack.y + HUD->size.y)) {
        fight->which_attack = 3;
        do_attack(fight, window, 50 + fight->bonus_attack, 1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= fth_attack.x) && \
    (cursor.x <= fth_attack.x + HUD->size.x) && \
    (cursor.y >= fth_attack.y) && \
    (cursor.y <= fth_attack.y + HUD->size.y)) {
        fight->which_attack = 4;
        do_attack(fight, window, 500 + fight->bonus_attack, 1);
    }
}

void select_attack(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f f_attack = sfRectangleShape_getPosition(HUD->attack1);
    sfVector2f s_attack = sfRectangleShape_getPosition(HUD->attack2);

    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= f_attack.x) && \
    (cursor.x <= f_attack.x + HUD->size.x) && \
    (cursor.y >= f_attack.y) && \
    (cursor.y <= f_attack.y + HUD->size.y)) {
        fight->which_attack = 1;
        do_attack(fight, window, 150 + fight->bonus_attack, 1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    (cursor.x >= s_attack.x) && \
    (cursor.x <= s_attack.x + HUD->size.x) && \
    (cursor.y >= s_attack.y) && \
    (cursor.y <= s_attack.y + HUD->size.y)) {
        fight->which_attack = 2;
        do_attack(fight, window, 200 + fight->bonus_attack, 1);
    }
    select_attack2(game, fight, window, cursor);
}

void mouse_gestion2(game_t *game, battle_t *fight, sfRenderWindow *window, \
sfVector2i cursor)
{
    sfVector2f t_attack = sfRectangleShape_getPosition(HUD->attack3);
    sfVector2f fth_attack = sfRectangleShape_getPosition(HUD->attack4);

    if ((cursor.x >= t_attack.x) && \
    (cursor.x <= t_attack.x + HUD->size.x) && \
    (cursor.y >= t_attack.y) && \
    (cursor.y <= t_attack.y + HUD->size.y))
        sfRectangleShape_setFillColor(HUD->attack3, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(HUD->attack3, game->menu_color);
    if ((cursor.x >= fth_attack.x) && \
    (cursor.x <= fth_attack.x + HUD->size.x) && \
    (cursor.y >= fth_attack.y) && \
    (cursor.y <= fth_attack.y + HUD->size.y))
        sfRectangleShape_setFillColor(HUD->attack4, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(HUD->attack4, game->menu_color);
}

void mouse_gestion(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    sfVector2f f_attack = sfRectangleShape_getPosition(HUD->attack1);
    sfVector2f s_attack = sfRectangleShape_getPosition(HUD->attack2);

    if ((cursor.x >= f_attack.x) && \
    (cursor.x <= f_attack.x + HUD->size.x) && \
    (cursor.y >= f_attack.y) && \
    (cursor.y <= f_attack.y + HUD->size.y))
        sfRectangleShape_setFillColor(HUD->attack1, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(HUD->attack1, game->menu_color);
    if ((cursor.x >= s_attack.x) && \
    (cursor.x <= s_attack.x + HUD->size.x) && \
    (cursor.y >= s_attack.y) && \
    (cursor.y <= s_attack.y + HUD->size.y))
        sfRectangleShape_setFillColor(HUD->attack2, game->m_menu_color);
    else
        sfRectangleShape_setFillColor(HUD->attack2, game->menu_color);
    mouse_gestion2(game, fight, window, cursor);
}