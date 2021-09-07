/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** get nbr
*/

#include "../../include/my_printf_lib.h"
#include <limits.h>
#include <stdio.h>

int sign(char const c, int *a, int get_neg)
{
    if (c == 45) {
        *a = *a + 1;
    }
    if (*a % 2 == 1) {
        get_neg = get_neg * (-1);
    }
    return (get_neg);
}

int my_getnbr(char const *str)
{
    int signed_nbr;
    int i = 0;
    int nbr = 0;
    int get_sign = 1;
    int a = 0;

    while (str[i] != '\0') {
        if (str[i] == 45) {
            signed_nbr = sign(str[i], &a, get_sign);
            i++;
        } else {
            nbr = nbr * 10;
            nbr = nbr + (str[i] - 48);
            i++;
            signed_nbr = sign(str[i], &a, get_sign);
        }
    }
    nbr = nbr * signed_nbr;
    return (nbr);
}