/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** count_lines.c
*/

int count_lines(char *str)
{
    int idx = 0;
    int line = 1;

    while (str[idx] != '\0') {
        if (str[idx] == '\n')
            line++;
        idx++;
    }
    return (line);
}