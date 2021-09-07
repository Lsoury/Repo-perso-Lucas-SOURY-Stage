/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** sprite_anim.c
*/

#include "../../include/templates/image.h"
#include "../../include/struct.h"

sfIntRect initRect(sfTexture *texture, sfIntRect target, anim_t *anim)
{
    target.top = 0;
    target.left = 0;
    target.height = sfTexture_getSize(texture).y;
    target.width = sfTexture_getSize(texture).x / 3;
    return (target);
}

void next_step(anim_t *anim, sfIntRect *rect, sfSprite *sprite)
{
    if (anim->current_step >= 3) {
        anim->current_step = 0;
        rect->left = 0;
    }
    if (anim->current_step < 3) {
        rect->left = rect->width * anim->current_step;
        anim->current_step += 1;
    }
    sfSprite_setTextureRect(sprite, *rect);
}