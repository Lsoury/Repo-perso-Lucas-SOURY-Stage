/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** create_hud.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void set_text_pos(battle_t *fight)
{
    sfText_setPosition(HUD->n_attack1, (sfVector2f) \
    {sfRectangleShape_getPosition(HUD->attack1).x + 50, \
    sfRectangleShape_getPosition(HUD->attack1).y + 15});
    sfText_setPosition(HUD->n_attack2, (sfVector2f) \
    {sfRectangleShape_getPosition(HUD->attack2).x + 95, \
    sfRectangleShape_getPosition(HUD->attack2).y + 15});
    sfText_setPosition(HUD->n_attack3, (sfVector2f) \
    {sfRectangleShape_getPosition(HUD->attack3).x + 50, \
    sfRectangleShape_getPosition(HUD->attack3).y + 15});
    sfText_setPosition(HUD->n_attack4, (sfVector2f) \
    {sfRectangleShape_getPosition(HUD->attack4).x + 95, \
    sfRectangleShape_getPosition(HUD->attack4).y + 15});
}

int create_text_hud(game_t *game, battle_t *fight)
{
    HUD->n_attack1 = sfText_create();
    HUD->n_attack2 = sfText_create();
    HUD->n_attack3 = sfText_create();
    HUD->n_attack4 = sfText_create();
    if (HUD->n_attack1 == NULL || HUD->n_attack2 == NULL || \
    HUD->n_attack3 == NULL || HUD->n_attack4 == NULL)
        return (1);
    sfText_setString(HUD->n_attack1, "EXPLOSION");
    sfText_setString(HUD->n_attack2, "FIST");
    sfText_setString(HUD->n_attack3, "SUSTAIN");
    sfText_setString(HUD->n_attack4, "MACE");
    sfText_setFillColor(HUD->n_attack1, sfWhite);
    sfText_setFillColor(HUD->n_attack2, sfWhite);
    sfText_setFillColor(HUD->n_attack3, sfWhite);
    sfText_setFillColor(HUD->n_attack4, sfWhite);
    sfText_setFont(HUD->n_attack1, game->text->police_char);
    sfText_setFont(HUD->n_attack2, game->text->police_char);
    sfText_setFont(HUD->n_attack3, game->text->police_char);
    sfText_setFont(HUD->n_attack4, game->text->police_char);
    set_text_pos(fight);
}

void create_hud2(game_t *game, battle_t *fight)
{
    sfRectangleShape_setFillColor(HUD->attack1, game->menu_color);
    sfRectangleShape_setFillColor(HUD->attack2, game->menu_color);
    sfRectangleShape_setFillColor(HUD->attack3, game->menu_color);
    sfRectangleShape_setFillColor(HUD->attack4, game->menu_color);
    sfRectangleShape_setOutlineThickness(HUD->attack1, 2);
    sfRectangleShape_setOutlineThickness(HUD->attack2, 2);
    sfRectangleShape_setOutlineThickness(HUD->attack3, 2);
    sfRectangleShape_setOutlineThickness(HUD->attack4, 2);
    sfRectangleShape_setOutlineColor(HUD->attack1, sfBlack);
    sfRectangleShape_setOutlineColor(HUD->attack2, sfBlack);
    sfRectangleShape_setOutlineColor(HUD->attack3, sfBlack);
    sfRectangleShape_setOutlineColor(HUD->attack4, sfBlack);
}

int create_hud(game_t *game, battle_t *fight)
{
    HUD->attack1 = sfRectangleShape_create();
    HUD->attack2 = sfRectangleShape_create();
    HUD->attack3 = sfRectangleShape_create();
    HUD->attack4 = sfRectangleShape_create();
    if (HUD->attack1 == NULL || HUD->attack2 == NULL || \
    HUD->attack3 == NULL || HUD->attack4 == NULL)
        return (1);
    sfRectangleShape_setPosition(HUD->attack1, HUD->pos);
    sfRectangleShape_setPosition(HUD->attack2, \
    (sfVector2f) {HUD->pos.x * 2, HUD->pos.y});
    sfRectangleShape_setPosition(HUD->attack3, \
    (sfVector2f) {HUD->pos.x * 3, HUD->pos.y});
    sfRectangleShape_setPosition(HUD->attack4, \
    (sfVector2f) {HUD->pos.x * 4, HUD->pos.y});
    sfRectangleShape_setSize(HUD->attack1, HUD->size);
    sfRectangleShape_setSize(HUD->attack2, HUD->size);
    sfRectangleShape_setSize(HUD->attack3, HUD->size);
    sfRectangleShape_setSize(HUD->attack4, HUD->size);
    create_hud2(game, fight);
    if (create_text_hud(game, fight) == 1)
        return (1);
}