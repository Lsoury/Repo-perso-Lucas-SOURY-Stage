/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** main.c
*/

#include "../include/functions.h"
#include "../include/my_printf_lib.h"
#include <stdlib.h>

static char **malloc_first_env(char **env)
{
    int idx = 0;
    char **arr;
    arr = malloc(sizeof(char *) * (get_lines(env) + 1));

    if (arr == NULL)
        return (NULL);
    while (env[idx] != NULL) {
        arr[idx] = malloc(sizeof(char) * (my_strlen(env[idx]) + 1));
        if (arr[idx] == NULL)
            return (NULL);
        my_strcpy(arr[idx], env[idx]);
        idx++;
    }
    arr[idx] = NULL;
    return (arr);
}

static int minishell(int ac, char **av, char **envp)
{
    minishell_t *minishell = malloc(sizeof(minishell_t));

    minishell->envp = malloc_first_env(envp);
    malloc_env_size(minishell);
    prompt(ac, av, minishell);
    if (minishell->env_cpy != NULL) {
        free_env(minishell->env_cpy);
    }
    if (minishell->envp != NULL)
        free_env(minishell->envp);
    free(minishell->parsed_arg);
    free(minishell->filepath);
    free(minishell);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    return minishell(ac, av, envp);
}