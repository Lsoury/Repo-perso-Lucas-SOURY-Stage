/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_fight.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

int other_textures(game_t *game, battle_t *fight)
{
    fight->t_background = \
    sfTexture_createFromFile("ressources/Battle_sprites/Grassland.png", \
    NULL);
    if (game->which_ennemy != 0)
        MUSIC->battle = \
        sfMusic_createFromFile("ressources/Battle_sounds/Battle1.ogg");
    else
        MUSIC->battle = \
        sfMusic_createFromFile("ressources/Battle_sounds/Battle3.ogg");
    if (MUSIC->battle == NULL)
        return (1);
    sfMusic_setVolume(MUSIC->battle, 2.50);
    sfMusic_setLoop(MUSIC->battle, sfTrue);
    if (game->which_ennemy == 0)
        fight->life_ennemy = 1500;
    else
        fight->life_ennemy = 500;
    return (0);
}

int create_texture(game_t *game, battle_t *fight)
{
    fight->t_player = \
    sfTexture_createFromFile("ressources/Battle_sprites/Actor1_3.png", NULL);
    if (game->which_ennemy == 0)
        fight->t_ennemy = \
        sfTexture_createFromFile("ressources/Battle_sprites/Actor1_7.png", \
        NULL);
    if (game->which_ennemy == 1)
        fight->t_ennemy = \
        sfTexture_createFromFile("ressources/Battle_sprites/Cockatrice.png", \
        NULL);
    if (game->which_ennemy == 2)
        fight->t_ennemy = \
        sfTexture_createFromFile("ressources/Battle_sprites/Gazer.png", NULL);
    if (game->which_ennemy == 3)
        fight->t_ennemy = \
        sfTexture_createFromFile("ressources/Battle_sprites/Hornet.png", NULL);
    if (fight->t_player == NULL || fight->t_ennemy == NULL || \
    (other_textures(game, fight) == 1) || \
    fight->t_background == NULL || create_hud(game, fight) == 1)
        return (1);
    return (0);
}

int create_sprite(game_t *game, battle_t *fight)
{
    fight->player = sfSprite_create();
    fight->ennemy = sfSprite_create();
    fight->background = sfSprite_create();
    if (fight->player == NULL || fight->ennemy == NULL || \
    fight->background == NULL || init_life(game, fight) == 1)
        return (1);
    sfSprite_setTexture(fight->player, fight->t_player, sfFalse);
    sfSprite_setTexture(fight->ennemy, fight->t_ennemy, sfFalse);
    sfSprite_setTexture(fight->background, fight->t_background, sfFalse);
    sfSprite_setPosition(fight->player, fight->pos_player);
    sfSprite_setPosition(fight->ennemy, fight->pos_ennemy);
    sfSprite_setPosition(fight->background, fight->pos_background);
    sfSprite_setScale(fight->background, (sfVector2f) {1.92, 1.46});
    return (0);
}

int battle(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    mouse_gestion(game, fight, window);
    draw_background(fight, window);
    change_life(game->which_ennemy, fight, window);
    if (fight->current_step == -1) {
        draw_buttons(fight, window);
        select_attack(game, fight, window);
        player_turn(game, fight, window);
    }
    if (fight->which_attack == 0) {
        if (apply_hit(game, fight, 2, window) == 1)
            return (1);
    }
    if (fight->which_attack > 0) {
        if (apply_hit(game, fight, 1, window) == 1)
            return (1);
    }
    sfRenderWindow_display(window);
    return (0);
}

int init_fight(game_t *game, battle_t *fight, sfRenderWindow *window)
{
    if (fight->in_fight == 0) {
        if (create_texture(game, fight) == 1 || \
        create_sprite(game, fight) == 1)
            return (1);
        sfMusic_play(MUSIC->battle);
        fight->in_fight = 1;
        fight->which_attack = -1;
        fight->current_step = -1;
    }
    if (battle(game, fight, window) == 1)
        return (1);
    if ((fight->life_player <= 0 || fight->life_ennemy <= 0) && \
    fight->current_step == -1) {
        fight->in_fight = 0;
        check_end_game(game, fight);
        game->which_ennemy = -1;
        fight->bonus_attack += 20;
        sfMusic_play(game->music->theme);
        destroy_fight(game, fight);
    }
    return (0);
}