/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** move_player.c
*/

#include <ncurses.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include "../include/map_struct.h"
#include "../include/player.h"

void move_to_left(map_t *map, player_t *player)
{
    if (map->arr[player->x][player->y - 1] == ' ' || \
        map->arr[player->x][player->y - 1] == 'O') {
        map->arr[player->x][player->y - 1] = 'P';
        map->arr[player->x][player->y] = ' ';
        player->y -= 1;
    } else if (map->arr[player->x][player->y - 1] == 'X') {
        if (map->arr[player->x][player->y - 2] == ' ' || \
            map->arr[player->x][player->y - 2] == 'O') {
            map->arr[player->x][player->y - 2] = 'X';
            map->arr[player->x][player->y - 1] = 'P';
            map->arr[player->x][player->y] = ' ';
            player->y -= 1;
        }
    }
}

void move_to_right(map_t *map, player_t *player)
{
    if (map->arr[player->x][player->y + 1] == ' ' || \
    map->arr[player->x][player->y + 1] == 'O') {
        map->arr[player->x][player->y + 1] = 'P';
        map->arr[player->x][player->y] = ' ';
        player->y += 1;
    } else if (map->arr[player->x][player->y + 1] == 'X') {
        if (map->arr[player->x][player->y + 2] == ' ' || \
            map->arr[player->x][player->y + 2] == 'O') {
            map->arr[player->x][player->y + 2] = 'X';
            map->arr[player->x][player->y + 1] = 'P';
            map->arr[player->x][player->y] = ' ';
            player->y += 1;
        }
    }
}

void move_up(map_t *map, player_t *player)
{
    if (map->arr[player->x - 1][player->y] == ' ' || \
        map->arr[player->x - 1][player->y] == 'O') {
        map->arr[player->x - 1][player->y] = 'P';
        map->arr[player->x][player->y] = ' ';
        player->x -= 1;
    } else if (map->arr[player->x - 1][player->y] == 'X') {
        if (map->arr[player->x - 2][player->y] == ' ' || \
            map->arr[player->x - 2][player->y] == 'O') {
            map->arr[player->x - 2][player->y] = 'X';
            map->arr[player->x - 1][player->y] = 'P';
            map->arr[player->x][player->y] = ' ';
            player->x -= 1;
        }
    }
}

void move_down(map_t *map, player_t *player)
{
    if (map->arr[player->x + 1][player->y] == ' ' || \
        map->arr[player->x + 1][player->y] == 'O') {
        map->arr[player->x + 1][player->y] = 'P';
        map->arr[player->x][player->y] = ' ';
        player->x += 1;
    } else if (map->arr[player->x + 1][player->y] == 'X') {
        if (map->arr[player->x + 2][player->y] == ' ' || \
            map->arr[player->x + 2][player->y] == 'O') {
            map->arr[player->x + 2][player->y] = 'X';
            map->arr[player->x + 1][player->y] = 'P';
            map->arr[player->x][player->y] = ' ';
            player->x += 1;
        }
    }
}

void move_player(map_t *map, player_t *player, struct winsize win, char *str)
{
    int key = getch();

    if (key == KEY_LEFT && map->arr[player->x][player->y - 1] != '#' && \
        player->y - 1 != 0)
        move_to_left(map, player);
    if (key == KEY_RIGHT && map->arr[player->x][player->y + 1] != '#' && \
        player->y + 1 != win.ws_col)
        move_to_right(map, player);
    if (key == KEY_UP && map->arr[player->x - 1][player->y] != '#' && \
        player->x - 1 != 0)
        move_up(map, player);
    if (key == KEY_DOWN && map->arr[player->x + 1][player->y] != '#' && \
        player->x + 1 != win.ws_row && map->arr[player->x + 2] != NULL)
        move_down(map, player);
    if (key == ' ')
        reset_map(map, player, str);
}