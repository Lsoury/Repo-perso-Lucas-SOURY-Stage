/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** malloc_handling.c
*/

#include "../../include/myrpg.h"

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

char **fill_tab(char *str)
{
    int line_idx = 0;
    int col_idx = 0;
    int str_idx = 0;
    char **arr = malloc(sizeof(char *) * get_lines(str));

    arr[line_idx] = malloc(sizeof(char) * get_col(str, str_idx) + 1);
    while (str[str_idx] != '\0') {
        if (str[str_idx] == '\n') {
            arr[line_idx][col_idx] = '\0';
            line_idx++;
            col_idx = 0;
            str_idx++;
            arr[line_idx] = malloc(sizeof(char) * get_col(str, str_idx) + 1);
        }
        arr[line_idx][col_idx] = str[str_idx];
        col_idx++;
        str_idx++;
    }
    arr[line_idx] = NULL;
    return (arr);
}