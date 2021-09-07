/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

int char_nbr(char a);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int sign(char const c, int *a, int get_neg);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbrbin(int nb);
unsigned int my_unsigned(unsigned int nb);
int my_put_oct(int nb);
void display_c(va_list list);
void display_i(va_list list);
void display_s(va_list list);
void display_d(va_list list);
void display_bin(va_list list);
void display_u(va_list list);
void display_oct(va_list list);
int my_strlen(char const *str);
int my_printf(const char *s, ...);

#endif /* MY_H_ */