/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** ptr_functions_arr.c
*/

#include <stdio.h>
#include "../include/functions.h"
#include "../include/my_printf_lib.h"

int function_call(minishell_t *minishell)
{
    char *check[4] = {"cd\0", "setenv\0", "unsetenv\0", "env\0"};

    if (parser(minishell) == -1)
        return (-1);
    if (go_in_farr(minishell, check) == -1)
        return (-1);
    return (0);
}

int go_in_farr(minishell_t *minishell, char **check)
{
    int (*farr[])(minishell_t *minishell) = {&cd_call, &setenv_call, \
    &unsetenv_call, &env_call};

    for (int idx = 0; idx != 4; idx++) {
        if (my_strcmp(check[idx], minishell->parsed_arg[0]) == 0)
            return (farr[idx](minishell));
    }
    root_command(minishell);
    return (0);
}