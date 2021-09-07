/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** get_player_pos.c
*/

#include <ncurses.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include "../include/map_struct.h"
#include "../include/player.h"

int get_player_origin_pos(map_t *map, player_t *player)
{
    int line = 0;
    int col = 0;
    player->original_x = 0;
    player->original_y = 0;

    while (map->arr[line] != NULL) {
        while (map->arr[line][col] != '\0') {
            if (map->arr[line][col] == 'P') {
                player->original_x = line + 1;
                player->original_y = col + 1;
                return (0);
            }
            col++;
        }
        line++;
        col = 0;
    }
    return (0);
}

int get_player_coordinates(map_t *map, player_t *player)
{
    int line = 0;
    int col = 0;

    while (map->arr[line] != NULL) {
        while (map->arr[line][col] != '\0') {
            if (map->arr[line][col] == 'P') {
                player->x = line;
                player->y = col;
                return (0);
            }
            col++;
        }
        line++;
        col = 0;
    }
    return (0);
}