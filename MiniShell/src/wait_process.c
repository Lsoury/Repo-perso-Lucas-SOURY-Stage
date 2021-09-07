/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** wait_process.c
*/

#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int wait_process(int argc, char **argv, minishell_t *minishell)
{
    size_t n = 0;
    minishell->get_command = NULL;

    if ((getline(&minishell->get_command, &n, stdin) == -1) || \
        (my_strcmp(minishell->get_command, "exit\n") == 0))
        return (84);
    return (0);
}

int prompt(int argc, char **argv, minishell_t *minishell)
{
    int prompt = 0;

    while (1) {
        if (prompt == 0) {
            my_printf("$> ");
            prompt = 1;
        }
        if ((prompt = wait_process(argc, argv, minishell)) == 84) {
            my_printf("%s\n", "Exit.");
            return (0);
        }
        if (space_handling(minishell) == -1)
            prompt = 0;
        else
            function_call(minishell);
        free(minishell->get_command);
    }
    return (1);
}