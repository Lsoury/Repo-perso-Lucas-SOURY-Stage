/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_s.c
*/

#include <stdarg.h>
#include "../../include/my_printf_lib.h"

void display_s(va_list list)
{
    char *s = va_arg(list, char *);
    my_putstr(s);
}