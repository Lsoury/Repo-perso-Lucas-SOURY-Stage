/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_quest.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void init_hud(game_t *game)
{
    sfRectangleShape_setPosition(QUEST->hud, \
    (sfVector2f) {game->w - 250, 0});
    sfRectangleShape_setSize(QUEST->hud, (sfVector2f) {250, 150});
    sfRectangleShape_setFillColor(QUEST->hud, game->menu_color);
    sfRectangleShape_setOutlineThickness(QUEST->hud, 2);
    sfRectangleShape_setOutlineColor(QUEST->hud, sfBlack);
}

void init_text_hud(game_t *game)
{
    sfText_setString(QUEST->quest, "QUEST : TAKE \nBACK YOUR \nDOG");
    sfText_setColor(QUEST->quest, sfWhite);
    sfText_setFont(QUEST->quest, game->text->police_char);
    sfText_setPosition(QUEST->quest, (sfVector2f) {game->w - 240, 5});
}

void init_sprite_hud(game_t *game)
{
    sfSprite_setTexture(QUEST->hp_player, QUEST->t_hp[0], sfFalse);
    sfSprite_setPosition(QUEST->hp_player, \
    (sfVector2f) {game->w - 50, 100});
    sfSprite_setScale(QUEST->hp_player, (sfVector2f) {0.5, 0.5});
    sfSprite_setRotation(QUEST->hp_player, 90.0);
}

int init_quest(game_t *game)
{
    QUEST->hud = sfRectangleShape_create();
    QUEST->t_hp[0] = \
    sfTexture_createFromFile("ressources/life/full_bar.png", NULL);
    QUEST->t_hp[1] = \
    sfTexture_createFromFile("ressources/life/middle_bar.png", NULL);
    QUEST->t_hp[2] = \
    sfTexture_createFromFile("ressources/life/low_bar.png", NULL);
    QUEST->quest = sfText_create();
    QUEST->hp_player = sfSprite_create();
    if (QUEST->hud == NULL || QUEST->t_hp[0] == NULL || \
    QUEST->t_hp[1] == NULL || QUEST->t_hp[2] == NULL || \
    QUEST->hp_player == NULL || QUEST->quest == NULL)
        return (1);
    init_hud(game);
    init_text_hud(game);
    init_sprite_hud(game);
    return (0);
}