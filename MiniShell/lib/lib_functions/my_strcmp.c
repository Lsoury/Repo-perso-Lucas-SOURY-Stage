/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;

    while (s1[index] != '\0') {
        if (s2[index] == '\0') {
            return (1);
        }
        if (s1[index] != s2[index]) {
            return (1);
        }
        index++;
    }
    return (0);
}