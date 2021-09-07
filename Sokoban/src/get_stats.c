/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** get_stats.c
*/

#include "../include/functions.h"
#include <stdlib.h>

int get_col(char *str, int line)
{
    int count = 0;

    while (str[line] != '\0' && str[line] != '\n') {
        line++;
        count++;
    }
    return (count);
}

int get_lines(char *str)
{
    int idx = 0;
    int count = 1;

    while (str[idx] != '\0') {
        if (str[idx] == '\n') {
            count++;
        }
        idx++;
    }
    return (count);
}

int get_arr_lines(map_t *map)
{
    int line = 0;

    while (map->arr[line] != NULL) {
        line++;
    }
    return (line);
}

int longest_line(map_t *map)
{
    int line = 0;
    int col = 0;
    int temp = 0;

    while (map->arr[line] != NULL) {
        while (map->arr[line][col] != '\0') {
            col++;
        }
        if (temp < col) {
            temp = col;
        }
        col = 0;
        line++;
    }
    return (temp);
}