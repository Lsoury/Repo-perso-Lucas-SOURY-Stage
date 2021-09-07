/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_put_unisgned.c
*/

#include "../../include/my_printf_lib.h"

unsigned int my_unsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_unsigned(nb / 10);
        my_putchar((nb % 10) + 48);
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    return (nb);
}