/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_i.c
*/

#include <stdarg.h>
#include "../../include/my_printf_lib.h"

void display_i(va_list list)
{
    int i = va_arg(list, int);
    my_put_nbr(i);
}