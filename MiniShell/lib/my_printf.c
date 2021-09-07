/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_printf.c
*/

#include <stdio.h>
#include "../include/my_printf_lib.h"

void get_tab(va_list list, char p, void (**ptr_array)(va_list))
{
    int i = 0;
    char stckfun[8] = "cisdbuo\0";

    while (stckfun[i] != '\0') {
        if (p == stckfun[i]) {
            ptr_array[i](list);
        }
        ++i;
    }
}

int my_printf(const char *s, ...)
{
    int pos = 0;
    va_list list;
    void (*ptr_array[8])(va_list) = {&display_c, &display_i, &display_s,
                                    &display_i, &display_bin, &display_u,
                                    &display_oct, NULL};

    va_start (list, s);
    while (s[pos] != '\0') {
        if (s[pos] == '%') {
            get_tab(list, s[pos + 1], ptr_array);
            pos = pos + 2;
        }
        my_putchar(s[pos]);
        pos++;
    }
    va_end(list);
    return (0);
}