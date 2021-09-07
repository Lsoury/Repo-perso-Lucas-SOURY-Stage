/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** array_handling.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/functions.h"

char **fill_tab(char *str)
{
    int line_idx = 0;
    int col_idx = 0;
    int str_idx = 0;
    char **arr = malloc(sizeof(char *) * get_lines(str));

    arr[line_idx] = malloc(sizeof(char) * get_col(str, str_idx) + 1);
    while (str[str_idx] != '\0') {
        if (str[str_idx] == '\n') {
            arr[line_idx][col_idx] = '\0';
            line_idx++;
            col_idx = 0;
            str_idx++;
            arr[line_idx] = malloc(sizeof(char) * get_col(str, str_idx) + 1);
        }
        arr[line_idx][col_idx] = str[str_idx];
        col_idx++;
        str_idx++;
    }
    arr[line_idx + 1] = NULL;
    return (arr);
}

void reset_map(map_t *map, player_t *player, char *str)
{
    int idx = 0;

    while (map->arr[idx] != NULL) {
        free(map->arr[idx]);
        idx++;
    }
    free(map->arr);
    player->x = player->original_x - 1;
    player->y = player->original_y - 1;
    fill_tab(str);
}

void free_malloc(map_t *map)
{
    int idx = 0;

    while (map->arr[idx] != NULL) {
        free(map->arr[idx]);
        free(map->arr_save[idx]);
        idx++;
    }
    free(map->arr);
}

void free_mallocs(map_t *map, char *str)
{
    free_malloc(map);
    free(str);
}