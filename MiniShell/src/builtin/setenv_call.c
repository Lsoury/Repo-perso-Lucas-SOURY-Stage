/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** setenv.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my_printf_lib.h"
#include "../../include/functions.h"

static int check_second_arg(minishell_t *minishell, int idx)
{
    if (minishell->parsed_arg[2] == NULL) {
        minishell->env_cpy[idx] = malloc(sizeof(char) * \
        (my_strlen(minishell->parsed_arg[1]) + 2));
        my_strcpy(minishell->env_cpy[idx], minishell->parsed_arg[1]);
        my_strcpy(&minishell->env_cpy[idx] \
        [my_strlen(minishell->env_cpy[idx])], "=");
    } else {
        minishell->env_cpy[idx] = malloc(sizeof(char) * \
        (my_strlen(minishell->parsed_arg[1]) + \
        my_strlen(minishell->parsed_arg[2]) + 2));
        my_strcpy(minishell->env_cpy[idx], minishell->parsed_arg[1]);
        my_strcpy(&minishell->env_cpy[idx] \
        [my_strlen(minishell->env_cpy[idx])], "=");
        my_strcpy(&minishell->env_cpy[idx] \
        [my_strlen(minishell->env_cpy[idx])], minishell->parsed_arg[2]);
    }
    return (0);
}

int modifiy_env(minishell_t *minishell, int line)
{
    int idx = 0;

    minishell->env_cpy = my_realloc(minishell->env_cpy, \
    (get_lines(minishell->env_cpy) + 1));
    while (minishell->envp[idx] != NULL) {
        if (idx == line) {
            check_second_arg(minishell, idx);
        } else {
            minishell->env_cpy[idx] = malloc(sizeof(char) * \
            (my_strlen(minishell->envp[idx]) + 1));
            my_strcpy(minishell->env_cpy[idx], minishell->envp[idx]);
        }
        idx++;
    }
    minishell->env_cpy[idx] = NULL;
    return (0);
}

int set_new_env(minishell_t *minishell)
{
    int idx = 0;

    minishell->env_cpy = my_realloc(minishell->env_cpy, \
    (get_lines(minishell->env_cpy) + 2));
    while (minishell->envp[idx] != NULL) {
        minishell->env_cpy[idx] = malloc(sizeof(char) * \
        (my_strlen(minishell->envp[idx]) + 1));
        my_strcpy(minishell->env_cpy[idx], minishell->envp[idx]);
        idx++;
    }
    check_second_arg(minishell, idx);
    minishell->env_cpy[idx + 1] = NULL;
    return (0);
}

int setenv_call(minishell_t *minishell)
{
    int line = 0;

    if (minishell->parsed_arg[1] == NULL) {
        env_call(minishell);
        return (0);
    }
    if ((line = check_in_env(minishell)) != -1) {
        modifiy_env(minishell, line);
    } else {
        set_new_env(minishell);
        save_env(minishell);
    }
    return (0);
}