/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** count_char_on_line.c
*/

int count_char_on_line(char *str, int s_idx)
{
    while (str[s_idx] != '\n') {
        s_idx++;
    }
    return (s_idx);
}