/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_c.c
*/

#include <stdarg.h>
#include "../../include/my_printf_lib.h"

void display_c(va_list list)
{
    int c = va_arg(list, int);
    my_putchar(c);
}