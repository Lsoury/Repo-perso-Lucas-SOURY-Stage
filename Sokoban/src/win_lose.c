/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** win_lose.c
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include "../include/map_struct.h"
#include "../include/player.h"

void print_last_frame(map_t *map, struct winsize win)
{
    print_map(map, win);
    usleep(300000);
}

int winning_condition(map_t *map, struct winsize win)
{
    int arr_idx = 0;
    int col_idx = 0;
    int count_to_victory = 0;

    while (map->arr[arr_idx] != NULL) {
        while (map->arr[arr_idx][col_idx] != '\0') {
            if (map->arr[arr_idx][col_idx] == 'X' && \
                map->arr_save[arr_idx][col_idx] == 'O') {
                count_to_victory++;
            }
            col_idx++;
        }
        col_idx = 0;
        arr_idx++;
    }
    if (count_to_victory == map->count_hole) {
        print_last_frame(map, win);
        return (-1);
    } else {
    return (0);
    }
}

int count_boxes(map_t *map)
{
    int arr_idx = 0;
    int col_idx = 0;
    int x_nbr = 0;

    while (map->arr[arr_idx] != NULL) {
        while (map->arr[arr_idx][col_idx] != '\0') {
            if (map->arr[arr_idx][col_idx] == 'X') {
                x_nbr++;
            }
            col_idx++;
        }
        col_idx = 0;
        arr_idx++;
    }
    return (x_nbr);
}

void losing_condition(map_t *map, struct winsize win)
{
    int arr_idx = 0;
    int col_idx = 0;
    int char_x = 0;

    while (map->arr[arr_idx] != NULL) {
        while (map->arr[arr_idx][col_idx] != '\0') {
            if (LOSING_CONDITION) {
                char_x++;
            }
            col_idx++;
        }
        col_idx = 0;
        arr_idx++;
    }
    if (char_x == count_boxes(map)) {
        print_last_frame(map, win);
        endwin();
        exit(1);
    }
}