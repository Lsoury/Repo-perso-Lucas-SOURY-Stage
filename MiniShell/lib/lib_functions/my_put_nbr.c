/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** put nbr
*/

#include "../../include/my_printf_lib.h"

int my_put_nbr(int nb);

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb < 0) {
        nb = nb * (- 1);
        my_putchar ('-');
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    return (nb);
}