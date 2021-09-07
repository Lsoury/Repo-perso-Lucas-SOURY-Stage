/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_put_nbrbin.c
*/

#include "../../include/my_printf_lib.h"

int my_put_nbrbin(int nb)
{
    int n;

    if (nb > 1) {
        n = nb % 2;
        nb = nb / 2;
        my_put_nbrbin(nb);
        my_putchar(n + 48);
    } else if (nb < 2) {
        my_putchar(nb + 48);
    }
    return (nb);
}