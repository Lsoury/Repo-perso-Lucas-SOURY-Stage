/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_d.c
*/

#include <stdarg.h>
#include "../../include/my_printf_lib.h"

void display_d(va_list list)
{
    int d = va_arg(list, int);
    my_putchar(d);
}