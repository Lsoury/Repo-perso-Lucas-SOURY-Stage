/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_music.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void destroy_music(game_t *game)
{
    sfMusic_destroy(game->music->theme);
    game->sound = 0;
}

int init_music_win(game_t *game)
{
    destroy_music(game);
    game->music->theme = \
    sfMusic_createFromFile("ressources/Applause2.ogg");
    if (game->music->theme == NULL)
        return (1);
    sfMusic_setVolume(game->music->theme, 2.5);
    sfMusic_setLoop(game->music->theme, sfTrue);
    sfMusic_play(game->music->theme);
    game->sound = 2;
    return (0);
}

int init_music_lose(game_t *game)
{
    destroy_music(game);
    game->music->theme = \
    sfMusic_createFromFile("ressources/Gameover2.ogg");
    if (game->music->theme == NULL)
        return (1);
    sfMusic_setVolume(game->music->theme, 2.5);
    sfMusic_setLoop(game->music->theme, sfTrue);
    sfMusic_play(game->music->theme);
    game->sound = 2;
    return (0);
}

int init_music_field(game_t *game)
{
    game->music->theme = \
    sfMusic_createFromFile("ressources/map_music/Field1.ogg");
    if (game->music->theme == NULL)
        return (1);
    sfMusic_setVolume(game->music->theme, 2.5);
    sfMusic_setLoop(game->music->theme, sfTrue);
    sfMusic_play(game->music->theme);
    game->sound = 1;
    return (0);
}

int init_music_start(game_t *game)
{
    game->music->theme = \
    sfMusic_createFromFile("ressources/map_music/Town2.ogg");
    if (game->music->theme == NULL)
        return (1);
    sfMusic_setVolume(game->music->theme, 2.5);
    sfMusic_setLoop(game->music->theme, sfTrue);
    sfMusic_play(game->music->theme);
    game->sound = 1;
    return (0);
}