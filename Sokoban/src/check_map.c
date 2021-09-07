/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** check_map.c
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"

int check_map(char *str, map_t *map)
{
    int idx = 0;
    int count_box = 0;
    map->count_hole = 0;

    while (str[idx] != '\0') {
        if (str[idx] != ' ' && str[idx] != '#' && str[idx] != 'P' && \
            str[idx] != 'O' && str[idx] != '\n' && str[idx] != 'X') {
            return (84);
        }
        if (str[idx] == 'O')
            map->count_hole++;
        if (str[idx] == 'X')
            count_box++;
        idx++;
    }
    if (count_box != map->count_hole)
        return (84);
    return (0);
}

void reprint_holes(map_t *map)
{
    int arr_idx = 0;
    int col_idx = 0;

    while (map->arr[arr_idx] != NULL) {
        while (map->arr[arr_idx][col_idx] != '\0') {
            if (map->arr[arr_idx][col_idx] == ' ' && \
                map->arr_save[arr_idx][col_idx] == 'O') {
                map->arr[arr_idx][col_idx] = 'O';
            }
            col_idx++;
        }
        col_idx = 0;
        arr_idx++;
    }
}

int print_enlarge_mess(struct winsize win)
{
    char *str = "The terminal is too small, please enlarge it";

    clear();
    mvprintw((win.ws_row / 2), ((win.ws_col / 2) - (my_strlen(str) / 2)), str);
    usleep(100000);
    refresh();
    return (0);
}