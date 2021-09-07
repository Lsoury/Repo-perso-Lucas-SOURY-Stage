/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** env_handling.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"

char **my_realloc(char **tab, int size)
{
    int idx = 0;
    if (tab == NULL || size < 1)
        return (malloc(sizeof(char *) * size));
    else {
        while (tab[idx] != NULL) {
            free(tab[idx]);
            idx += 1;
        }
        free(tab);
        return (malloc(sizeof(char *) * size));
    }
}

char *my_str_realloc(char *str, int size)
{
    if (str == NULL || size < 1)
        return (malloc(sizeof(char) * size));
    else {
        free(str);
        return (malloc(sizeof(char) * size));
    }
}

int check_in_env(minishell_t *minishell)
{
    for (int idx = 0; minishell->env_cpy[idx] != NULL; idx += 1) {
        if (my_strcmp(minishell->parsed_arg[1], minishell->env_cpy[idx]) == 0)
            return (idx);
    }
    return (-1);
}

int save_env(minishell_t *minishell)
{
    for (int idx = 0; minishell->envp[idx] != NULL; idx += 1) {
        free(minishell->envp[idx]);
    }
    free(minishell->envp);
    minishell->envp = malloc(sizeof(char *) * (get_lines(minishell->env_cpy) \
    + 1));
    for (int idx = 0; minishell->env_cpy[idx] != NULL; idx += 1) {
        minishell->envp[idx] = malloc(sizeof(char) * \
        (my_strlen(minishell->env_cpy[idx]) + 1));
        my_strcpy(minishell->envp[idx], minishell->env_cpy[idx]);
    }
    minishell->envp[get_lines(minishell->env_cpy)] = NULL;
    return (0);
}