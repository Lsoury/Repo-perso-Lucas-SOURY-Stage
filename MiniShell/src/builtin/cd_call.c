/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** cd.c
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/my_printf_lib.h"
#include "../../include/functions.h"

int find_home_in_env(minishell_t *minishell, int line_idx)
{
    while (minishell->envp[line_idx] != NULL) {
        if (my_strcmp("HOME=", minishell->envp[line_idx]) == 0) {
            return (line_idx);
        } else {
            line_idx++;
        }
    }
    return (0);
}

int cd_call(minishell_t *minishell)
{
    int col_idx = 5;
    int line_idx = 0;

    if (minishell->parsed_arg[1] == NULL) {
        if (my_strcmp(minishell->parsed_arg[0], "cd") == 1) {
            my_printf("%s: Not a directory.\n", minishell->parsed_arg[0]);
            return (84);
        } else {
            line_idx = find_home_in_env(minishell, line_idx);
            chdir(&minishell->envp[line_idx][col_idx]);
            return (0);
        }
    }
    if (chdir(minishell->parsed_arg[1]) == -1) {
        my_printf("%s: %s\n", minishell->parsed_arg[1], \
        "Not a directory.");
        return (84);
    }
    return (0);
}