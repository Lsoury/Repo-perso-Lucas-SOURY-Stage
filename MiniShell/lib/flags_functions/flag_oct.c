/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_oct.c
*/

#include "../../include/my_printf_lib.h"
#include <stdarg.h>

void display_oct(va_list list)
{
    int o = va_arg(list, int);
    my_put_oct(o);
}