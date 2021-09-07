/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int idx = 0;

    while (str[idx] != '\0') {
        idx++;
    }
    return (idx);
}