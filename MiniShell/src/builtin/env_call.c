/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** env.c
*/

#include "../../include/my_printf_lib.h"
#include "../../include/functions.h"
#include <stdio.h>
#include <stdlib.h>

int get_lines(char **arr)
{
    int idx = 0;

    while (arr[idx] != NULL) {
        idx++;
    }
    return (idx);
}

int malloc_env_size(minishell_t *mysh)
{
    int idx = 0;
    mysh->env_cpy = malloc(sizeof(char *) * (get_lines(mysh->envp) + 1));

    if (mysh->env_cpy == NULL)
        return (84);
    while (mysh->envp[idx] != NULL) {
        mysh->env_cpy[idx] = malloc(sizeof(char) * (my_strlen(mysh->envp[idx]) \
        + 1));
        if (mysh->env_cpy[idx] == NULL)
            return (84);
        my_strcpy(mysh->env_cpy[idx], mysh->envp[idx]);
        idx++;
    }
    mysh->env_cpy[idx] = NULL;
    return (0);
}

int env_call(minishell_t *minishell)
{
    print_arr(minishell->env_cpy);
    return (0);
}