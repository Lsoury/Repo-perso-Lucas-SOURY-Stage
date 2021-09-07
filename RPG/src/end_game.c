/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** end_game.c
*/

#include "../include/myrpg.h"
#include "../include/templates/fight.h"

int init_end(game_t *game)
{
    game->t_last[0] = sfTexture_createFromFile("ressources/GameOver.png", \
    NULL);
    game->t_last[1] = sfTexture_createFromFile("ressources/Victory.png", \
    NULL);
    game->last_screen = sfSprite_create();
    if (game->t_last[0] == NULL || game->t_last[1] == NULL || \
    game->last_screen == NULL)
    sfSprite_setTexture(game->last_screen, game->t_last[1], sfFalse);
    sfSprite_setPosition(game->last_screen, (sfVector2f) {0, 0});
    sfSprite_setScale(game->last_screen, (sfVector2f) {2.35, 1.73});
}

sfBool wait_for_closing(game_t *game)
{
    sfTime time;

    time = sfClock_getElapsedTime(game->clock);
    if (sfTime_asMilliseconds(time) >= 1000) {
        sfClock_restart(game->clock);
        return sfTrue;
    }
    return sfFalse;
}

void draw_end(game_t *game, sfRenderWindow *window)
{
    if (wait_for_closing(game) == sfTrue)
        game->which_scene++;
    sfSprite_setTexture(game->last_screen, \
    game->t_last[game->endgame - 1], sfFalse);
    sfRenderWindow_drawSprite(window, game->last_screen, NULL);
    sfRenderWindow_display(window);
    if (game->which_scene == 5)
        game->player_choice == -1;
}

void check_end_game(game_t *game, battle_t *fight)
{
    if (game->which_ennemy == 0 && fight->life_ennemy <= 0)
        game->endgame = 2;
    else if (fight->life_player <= 0)
        game->endgame = 1;
    else
        game->endgame = 0;
}