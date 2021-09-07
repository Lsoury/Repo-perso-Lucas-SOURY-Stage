/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_ennemies.c
*/

#include "../../include/myrpg.h"
#include "../../include/level2.h"

void init_pos(game_t *game)
{
    game->ennemy->pos[0] = (sfVector2f) {game->w / 2, 120};
    game->ennemy->pos[1] = (sfVector2f) {game->w / 3, 690};
    game->ennemy->pos[2] = (sfVector2f) {game->w / 6, 920};
    game->ennemy->pos[3] = (sfVector2f) {game->w / 2 + 250, game->h / 2};
    game->ennemy->pos[4] = (sfVector2f) {game->w / 2, 120};
}

void init_ennemy_texture(game_t *game, int const idx)
{
    if (idx == 0)
        game->ennemy->t_mob[idx] = \
        sfTexture_createFromFile("ressources/Battle_sprites/Cockatrice.png", \
        NULL);
    if (idx == 1)
        game->ennemy->t_mob[idx] = \
        sfTexture_createFromFile("ressources/Battle_sprites/Hornet.png", \
        NULL);
    if (idx == 2)
        game->ennemy->t_mob[idx] = \
        sfTexture_createFromFile("ressources/Battle_sprites/Gazer.png", \
        NULL);
    if (idx == 3)
        game->ennemy->t_mob[idx] = \
        sfTexture_createFromFile("ressources/Battle_sprites/Gazer.png", \
        NULL);
    if (idx == 4)
        game->ennemy->t_mob[idx] = \
        sfTexture_createFromFile("ressources/Battle_sprites/Actor1_7.png", \
        NULL);
}

int init_ennemy_pos(game_t *game)
{
    init_pos(game);
    for (int idx = 0; idx != 5; idx++) {
        init_ennemy_texture(game, idx);
        game->ennemy->mob[idx] = sfSprite_create();
        if (game->ennemy->t_mob[idx] == NULL || game->ennemy->mob[idx] == NULL)
            return (1);
        sfSprite_setTexture(game->ennemy->mob[idx], game->ennemy->t_mob[idx], \
        sfFalse);
        sfSprite_setPosition(game->ennemy->mob[idx], game->ennemy->pos[idx]);
        sfSprite_setScale(game->ennemy->mob[idx], (sfVector2f) {0.33, 0.33});
    }
    return (0);
}