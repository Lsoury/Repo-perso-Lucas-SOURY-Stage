/*
** EPITECH PROJECT, 2020
** B-PSU-200-BDX-2-1-mysokoban-lucas.soury
** File description:
** usage.c
*/

#include <stdlib.h>
#include "../include/my_printf_lib.h"

int check_usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h')
        usage();
}

int usage(void)
{
    my_printf("%s\n", "USAGE :");
    my_printf("%s\n", "     ./my_sokoban map");
    my_printf("%s\n", "DESCRIPTION");
    my_printf("%s", "     map file representing the warehouse map, ");
    my_printf("%s", "containing '#' for walls, 'P' for the player, 'X' for");
    my_printf("%s\n", " the boxes and 'O' for storage locations.");
    exit(0);
}