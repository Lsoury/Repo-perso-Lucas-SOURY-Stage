/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** map_struct.h
*/

#ifndef MAP_STRUCT_H_
#define MAP_STRUCT_H_

typedef struct map_s
{
    int line;
    int line_nb;
    int long_line;
    int count_hole;
    char **arr;
    char **arr_save;
} map_t;

#define LOSING_CONDITION (map->arr[arr_idx][col_idx] == 'X' && \
            ((map->arr[arr_idx][col_idx + 1] == '#' \
            && map->arr[arr_idx + 1][col_idx] == '#' \
            && map->arr_save[arr_idx][col_idx] != 'O') || \
            (map->arr[arr_idx][col_idx - 1] == '#' && \
            map->arr[arr_idx + 1][col_idx] == '#' && \
            map->arr_save[arr_idx][col_idx] != 'O') || \
            (map->arr[arr_idx][col_idx - 1] == '#' \
            && map->arr[arr_idx - 1][col_idx] == '#' && \
            map->arr_save[arr_idx][col_idx] != 'O') \
            || (map->arr[arr_idx][col_idx + 1] == '#' && \
            map->arr[arr_idx - 1][col_idx] == '#' \
            && map->arr_save[arr_idx][col_idx] != 'O')))

#endif