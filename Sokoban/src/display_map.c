/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** display_map.c
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include "../include/map_struct.h"
#include "../include/player.h"

void print_map(map_t *map, struct winsize win)
{
    clear();
    while (map->arr[map->line] != NULL) {
        mvprintw(((win.ws_row / 2) - (map->line_nb / 2) + map->line), \
                    ((win.ws_col / 2) - (map->long_line / 2)), \
                    map->arr[map->line]);
        map->line++;
        refresh();
    }
}

void init(map_t *map, player_t *player)
{
    map->line = 0;
    map->line_nb = get_arr_lines(map);
    map->long_line = longest_line(map);
    player->x = 0;
    player->y = 0;
}

void get_player_position(map_t *map, player_t *player)
{
    get_player_origin_pos(map, player);
    get_player_coordinates(map, player);
}

void map_handling(map_t *map, player_t *player, char *str, struct winsize wn) {
    print_map(map, wn);
    move_player(map, player, wn, str);
    reprint_holes(map);
    losing_condition(map, wn);
}

int display_map(map_t *map, player_t *player, char *str)
{
    struct winsize win;
    int check = 1;
    init(map, player);

    get_player_position(map, player);
    initscr();
    keypad(stdscr, TRUE);
    while (check = winning_condition(map, win) != -1) {
        if (ioctl(0, TIOCGWINSZ, &win) == -1)
            return (84);
        if (map->line_nb > win.ws_row || map->long_line > win.ws_col) {
            print_enlarge_mess(win);
        } else {
            map_handling(map, player, str, win);
        }
        map->line = 0;
    }
    endwin();
    return (0);
}