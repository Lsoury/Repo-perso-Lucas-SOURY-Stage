/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** length
*/

int my_strlen(char const *str)
{
    int z;

    z = 0;
    while (str[z] != '\0') {
        z++;
    }
    return (z);
}