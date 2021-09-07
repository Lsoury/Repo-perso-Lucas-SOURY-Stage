/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** put string
*/

#include <string.h>
#include "../../include/my_printf_lib.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return (84);
    }
    while (i != my_strlen(str)) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
