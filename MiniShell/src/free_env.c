/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** free.c
*/

#include <stdlib.h>

void free_env(char **env)
{
    for (int idx = 0; env[idx] != NULL; idx += 1) {
        free(env[idx]);
    }
    free(env);
}