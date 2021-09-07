/*
** EPITECH PROJECT, 2020
** B-PSU-210-BDX-2-1-minishell2-lucas.soury
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}