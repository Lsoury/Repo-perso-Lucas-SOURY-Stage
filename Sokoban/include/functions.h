/*
** EPITECH PROJECT, 2020
** my_scripts
** File description:
** header.h
*/

#include "game_struct.h"
#include "player.h"
#include "map_struct.h"
#include <sys/ioctl.h>

#ifndef HEADER_H_
#define HEADER_H

char **fill_tab(char *str);
void reset_map(map_t *map, player_t *player, char *str);
void free_malloc(map_t *map);
void free_mallocs(map_t *map, char *str);

int check_map(char *str, map_t *map);
void reprint_holes(map_t *map);
int print_enlarge_mess(struct winsize win);

int check_fd(int fd);
int check_read_value(int read_value);
int stop_if_map_is_wrong(int verif_map, char *str, map_t *map);
int check_malloc_arr(map_t *map);

void print_map(map_t *map, struct winsize win);
int display_map(map_t *map, player_t *player, char *str);

int get_lines(char *str);
int get_col(char *str, int line);
int get_arr_lines(map_t *map);
int longest_line(map_t *map);

int get_player_origin_pos(map_t *map, player_t *player);
int get_player_coordinates(map_t *map, player_t *player);
void move_player(map_t *map, player_t *player, struct winsize win, char *str);

char *open_file(char const *pathfile, game_struct_t game);

int usage(void);
int check_usage(int ac, char **av);

int winning_condition(map_t *map, struct winsize win);
int count_boxes(map_t *map);
void losing_condition(map_t *map, struct winsize win);

#endif