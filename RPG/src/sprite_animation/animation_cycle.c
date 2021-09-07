/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** animation_cycle.c
*/

#include "../../include/struct.h"

int animation_cycle(anim_t *anim)
{
    if (anim->check_stop == 0)
        next_step(anim, &anim->rect_left, anim->move);
    if (anim->check_stop == 1)
        next_step(anim, &anim->rect_right, anim->move);
    if (anim->check_stop == 2)
        next_step(anim, &anim->rect_up, anim->move);
    if (anim->check_stop == 3)
        next_step(anim, &anim->rect_down, anim->move);
    return (0);
}
