/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** level2.h
*/

#ifndef LEVEL2_H_
#define LEVEL2_H_

typedef struct lvl2_s
{
    int fd;
    int x;
    int y;
    int map_x;
    int map_y;

    char *read_buffer;

    char **map;
} lvl2_t;

#endif