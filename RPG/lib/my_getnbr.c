/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int idx = 0;
    int neg = 1;
    int nbr = 0;

    if (str[idx] == '-')
        neg = -1;
    while (str[idx] != '\0') {
        nbr *= 10;
        nbr += (str[idx] - '0');
        idx++;
    }
    nbr *= neg;
    return (nbr);
}