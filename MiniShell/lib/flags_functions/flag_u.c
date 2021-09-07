/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_u.c
*/

#include <stdarg.h>
#include "../../include/my_printf_lib.h"

void display_u(va_list list)
{
    int u = va_arg(list, int);
    my_unsigned(u);
}