/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** unsetenv.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my_printf_lib.h"
#include "../../include/functions.h"

int too_few_args(minishell_t *minishell)
{
    if (minishell->parsed_arg[1] == NULL) {
        my_printf("%s\n", "unsetenv: Too few arguments.");
        return (84);
    }
    return (0);
}

int unsetenv_call(minishell_t *minishell)
{
    int idx = 0;
    int idx2 = 0;
    int line = 0;

    too_few_args(minishell);
    if ((line = check_in_env(minishell)) == -1)
        return (0);
    minishell->env_cpy = my_realloc(minishell->env_cpy, \
    get_lines(minishell->envp));
    while (minishell->envp[idx] != NULL) {
        if (my_strcmp(minishell->parsed_arg[1], minishell->envp[idx]) == 1) {
            minishell->env_cpy[idx2] = malloc(sizeof(char) * \
            (my_strlen(minishell->envp[idx]) + 1));
            my_strcpy(minishell->env_cpy[idx2], minishell->envp[idx]);
            idx2 += 1;
        }
        idx++;
    }
    minishell->env_cpy[idx2] = NULL;
    save_env(minishell);
    return (0);
}