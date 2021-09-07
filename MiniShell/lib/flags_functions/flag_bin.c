/*
** EPITECH PROJECT, 2020
** B-CPE-110-BDX-1-1-pushswap-lucas.soury
** File description:
** flag_bin.c
*/

#include "../../include/my_printf_lib.h"
#include <stdarg.h>

void display_bin(va_list list)
{
    int b = va_arg(list, int);
    my_put_nbrbin(b);
}