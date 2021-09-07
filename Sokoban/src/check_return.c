/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** check_return.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/functions.h"
#include "../include/game_struct.h"

int check_fd(int fd)
{
    if (fd < 0) {
        write(2, "fd < 0, open failed", 20);
        exit(84);
    }
    return (0);
}

int check_read_value(int read_value)
{
    if (read_value < 0) {
        write(2, "read_value < 0, read failed", 28);
        exit(84);
    }
    return (0);
}

int stop_if_map_is_wrong(int verif_map, char *str, map_t *map)
{
    verif_map = check_map(str, map);

    if (verif_map == 84)
        exit(84);
    return (0);
}

int check_malloc_arr(map_t *map)
{
    if (map->arr == NULL) {
        write(2, "malloc failed", 14);
        exit(84);
    }
    return (0);
}