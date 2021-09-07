/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** functions.h
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "struct.h"

int prompt(int argc, char **argv, minishell_t *minishell);
int space_handling(minishell_t *minishell);
int parser(minishell_t *minishell);

void print_arr(char **arr);
int function_call(minishell_t *minishell);
int go_in_farr(minishell_t *minishell, char **check);
int get_lines(char **arr);
int malloc_env_size(minishell_t *mysh);
int check_in_env(minishell_t *minishell);
char **my_realloc(char **tab, int size);
char *my_str_realloc(char *str, int size);
void free_env(char **env);
int save_env(minishell_t *minishell);
int root_command(minishell_t *minishell);

int cd_call(minishell_t *minishell);
int env_call(minishell_t *minishell);
int exit_call(minishell_t *minishell);
int setenv_call(minishell_t *minishell);
int unsetenv_call(minishell_t *minishell);

#endif