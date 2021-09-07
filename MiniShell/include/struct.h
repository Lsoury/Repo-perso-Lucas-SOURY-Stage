/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct minishell
{
    char *get_command;
    char *filepath;
    char *right_path;

    char **parsed_arg;
    char **parsed_path;

    char **home_path;

    char **envp;
    char **env_cpy;
} minishell_t;

#endif