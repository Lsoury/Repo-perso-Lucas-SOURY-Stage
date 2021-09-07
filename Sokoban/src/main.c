/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/functions.h"
#include "../include/game_struct.h"
#include "../include/map_struct.h"
#include "../include/my_printf_lib.h"

int main(int ac, char **av)
{
    int verif_map = 0;
    char *str;
    game_struct_t game;
    map_t *map = malloc(sizeof(map));
    player_t *player = malloc(sizeof(player));

    if (ac == 2) {
        check_usage(ac, av);
        str = open_file(av[1], game);
        stop_if_map_is_wrong(verif_map, str, map);
        map->arr = fill_tab(str);
        map->arr_save = fill_tab(str);
        check_malloc_arr(map);
        display_map(map, player, str);
        free_mallocs(map, str);
        return (0);
    } else {
        return (84);
    }
}