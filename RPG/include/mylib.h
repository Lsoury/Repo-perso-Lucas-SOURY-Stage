/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** mylib.h
*/

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(char *str);
int count_lines(char *str);
int count_char_on_line(char *str, int s_idx);
int my_getnbr(char const *str);

#endif /* MYLIB_H_ */