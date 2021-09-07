/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** create_hitbox.c
*/

#include "../../include/templates/hitboxes.h"

void create_hitbox(hitbox_t *hitbox, sfRenderWindow *window)
{
    hitbox->rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(hitbox->rectangle, hitbox->position);
    sfRectangleShape_setSize(hitbox->rectangle, hitbox->size);
    sfRectangleShape_setFillColor(hitbox->rectangle, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, hitbox->rectangle, NULL);
}