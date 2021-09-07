/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** main.c
*/

#include "../../include/myrpg.h"

int check_env(char const **env)
{
    char const *check = "DISPLAY\0";
    int return_value = 0;

    for (int idx = 0; env[idx] != NULL; idx++) {
        for (int s_idx = 0; env[idx][s_idx] != '=' || \
        check[s_idx] != '\0'; s_idx++) {
            return_value = 0;
            if (env[idx][s_idx] != check[s_idx]) {
                return_value = 1;
                break;
            }
        }
        if (return_value == 0)
            return (return_value);
    }
    return (return_value);
}

int main(int const ac, char const **av, char const **env)
{
    if (env[0] == NULL || check_env(env) == 1)
        return (84);
    game_t *game = malloc(sizeof(game_t));
    sfRenderWindow *window;
    sfEvent event;
    game->scene_idx = 0;
    game->scene2_idx = 0;
    game->lvl3_scene_idx = 0;

    if (init_array(game, window, event) == 1)
        return (84);
    free(game);
    return (0);
}