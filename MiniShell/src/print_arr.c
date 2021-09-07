/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** print_arr.c
*/

#include <stdio.h>
#include "../include/my_printf_lib.h"

void print_arr(char **arr)
{
    for (int idx = 0; arr[idx] != NULL; idx++) {
        my_printf("%s\n", arr[idx]);
    }
}