/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** system_command.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "../include/my_printf_lib.h"
#include "../include/functions.h"
#include "../include/struct.h"

static int count_path_words(char *str)
{
    int count = 1;
    int idx = 0;

    while (str[idx] != '\0') {
        if (str[idx] == ':' || str[idx] == '=') {
            count += 1;
        }
        idx++;
    }
    return (count);
}

static int get_path(minishell_t *minishell)
{
    int idx = 0;

    while (minishell->env_cpy[idx] != NULL) {
        if (my_strcmp("PATH", minishell->env_cpy[idx]) == 0) {
            minishell->filepath = malloc(sizeof(char) * \
            (my_strlen(minishell->env_cpy[idx]) + 1));
            my_strcpy(minishell->filepath, minishell->env_cpy[idx]);
            return (0);
        }
        idx++;
    }
    return (1);
}

static int path_parser(minishell_t *minishell)
{
    int idx = 0;
    char delim[4] = "=:";
    minishell->parsed_path = malloc(sizeof(char *) * \
    (count_path_words(minishell->filepath) + 1));
    char *parsed = strtok(minishell->filepath, delim);

    while (parsed) {
        minishell->parsed_path[idx] = \
        my_str_realloc(NULL, (my_strlen(parsed) + \
        my_strlen(minishell->parsed_arg[0]) + 2));
        my_strcpy(minishell->parsed_path[idx], parsed);
        my_strcpy(&minishell->parsed_path[idx] \
        [my_strlen(minishell->parsed_path[idx])], "/");
        my_strcpy(&minishell->parsed_path[idx] \
        [my_strlen(minishell->parsed_path[idx])], minishell->parsed_arg[0]);
        idx++;
        parsed = strtok(NULL, delim);
    }
    minishell->parsed_path[idx] = NULL;
    return (0);
}

static int access_path(minishell_t *minishell)
{
    int idx = 0;

    while (minishell->parsed_path[idx] != NULL) {
        if (access(minishell->parsed_path[idx], X_OK) == 0) {
            minishell->right_path = my_str_realloc(NULL, \
            my_strlen(minishell->parsed_path[idx]) + 1);
            my_strcpy(minishell->right_path, minishell->parsed_path[idx]);
            break;
        }
        idx++;
    }
    return (0);
}

int root_command(minishell_t *minishell)
{
    int pid = fork();
    int status = 0;

    get_path(minishell);
    path_parser(minishell);
    access_path(minishell);
    if (pid < 0)
        return (-1);
    else if (pid == 0) {
        if ((status = execve(minishell->right_path, &minishell->parsed_arg[0], \
            minishell->envp)) == -1) {
            my_printf("%s: %s\n", minishell->parsed_arg[0], \
            "Command not found.");
            kill(pid, SIGCHLD);
        }
    } else {
        wait(&status);
    }
    free_env(minishell->parsed_path);
    free(minishell->right_path);
}