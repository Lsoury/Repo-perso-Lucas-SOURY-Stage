/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_put_oct.c
*/

#include "../../include/my_printf_lib.h"

int my_put_oct(int nb)
{
    int n;

    if (nb > 7) {
        n = nb % 8;
        nb = nb / 8;
        my_put_oct(nb);
        my_putchar(n + 48);
    } else if (nb < 8) {
        my_putchar(nb + 48);
    }
    return (nb);
}