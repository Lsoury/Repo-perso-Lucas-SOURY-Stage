/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** level3.h
*/

#ifndef LEVEL3_H_
#define LEVEL3_H_

typedef struct lvl3_s
{
    int fd;
    int x;
    int y;
    int map_x;
    int map_y;

    char *read_buffer;

    char **map;
} lvl3_t;

#endif