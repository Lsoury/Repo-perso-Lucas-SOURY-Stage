/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** space_handling.c
*/

#include <stdio.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"

static int check_space(minishell_t *minishell)
{
    if (minishell->get_command[0] == '\t' && minishell->get_command[1] == '\n' \
    || minishell->get_command[0] == ' ' && minishell->get_command[1] == '\n') {
        return (-1);
    }
    return (0);
}

int space_handling(minishell_t *minishell)
{
    if (check_space(minishell) == -1)
        return (-1);
    return (0);
}