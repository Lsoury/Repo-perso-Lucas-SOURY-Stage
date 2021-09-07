/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** set_base_sprite.c
*/

#include "../../include/struct.h"

int set_base_lr_sprite(anim_t *ani, sfRenderWindow *window)
{
    if (ani->check_stop == 0) {
        sprite_display(ani->move, ani->left_texture, ani->rect_left, \
        ani->pos);
        sfRenderWindow_drawSprite(window, ani->move, NULL);
    }
    if (ani->check_stop == 1) {
        sprite_display(ani->move, ani->right_texture, ani->rect_right, \
        ani->pos);
        sfRenderWindow_drawSprite(window, ani->move, NULL);
    }
    return (0);
}

int set_base_ud_sprite(anim_t *anim, sfRenderWindow *window)
{
    if (anim->check_stop == 2) {
        sprite_display(anim->move, anim->up_texture, anim->rect_up, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    if (anim->check_stop == 3) {
        sprite_display(anim->move, anim->down_texture, anim->rect_down, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    return (0);
}