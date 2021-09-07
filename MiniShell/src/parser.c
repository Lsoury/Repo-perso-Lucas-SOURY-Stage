/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** parser.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"

int count_words(char *str)
{
    int count = 1;
    int idx = 0;

    while (str[idx] != '\0') {
        if (str[idx] == ' ' || str[idx] == '\t') {
            count += 1;
        }
        idx++;
    }
    return (count);
}

int parser(minishell_t *minishell)
{
    int idx = 0;
    char delim[4] = " \t\n";
    minishell->parsed_arg = malloc(sizeof(char *) * \
    (count_words(minishell->get_command) + 1));
    char *parsed = strtok(minishell->get_command, delim);

    while (parsed) {
        minishell->parsed_arg[idx] = parsed;
        idx++;
        parsed = strtok(NULL, delim);
    }
    minishell->parsed_arg[idx] = NULL;
    if (minishell->parsed_arg[0] == NULL)
        return (-1);
    return (0);
}