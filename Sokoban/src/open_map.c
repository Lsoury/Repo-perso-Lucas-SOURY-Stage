/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** open_map.c
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/game_struct.h"
#include "../include/functions.h"

char *open_file(char const *pathfile, game_struct_t game)
{
    struct stat info;
    if (stat(pathfile, &info) == -1) {
        write(2, "stat failed", 12);
    }
    int read_value = 0;
    char *buffer = malloc(sizeof(char) * (info.st_size + 1));
    buffer[info.st_size] = '\0';
    game.fd = open(pathfile, O_RDONLY);

    check_fd(game.fd);
    read_value = read(game.fd, buffer, info.st_size);
    check_read_value(read_value);
    return (buffer);
}