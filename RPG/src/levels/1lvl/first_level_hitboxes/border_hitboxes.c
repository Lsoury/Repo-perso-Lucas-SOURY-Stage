/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** border_hitboxes.c
*/

#include "../../../../include/templates/hitboxes.h"

static int set_left_border(hitbox_t *hitbox, sfRenderWindow *window, int idx)
{
    if (idx == 0) {
        hitbox->size.x = 100;
        hitbox->size.y = 600;
        hitbox->position.x = 1920 / 2 - 400;
        hitbox->position.y = 1080 / 2 - 300;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        idx++;
    }
    return (idx);
}

static int set_right_border(hitbox_t *hitbox, sfRenderWindow *window, int idx)
{
    if (idx == 1) {
        hitbox->size.x = 100;
        hitbox->size.y = 600;
        hitbox->position.x = 1920 / 2 + 300;
        hitbox->position.y = 1080 / 2 - 300;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        idx++;
    }
    return (idx);
}

static int set_bottom_border(hitbox_t *hitbox, sfRenderWindow *window, int idx)
{
    if (idx == 2) {
        hitbox->size.x = 543;
        hitbox->size.y = 100;
        hitbox->position.x = 1920 / 2 - 400;
        hitbox->position.y = 1080 / 2 + 300;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        idx++;
    }
    return (0);
}

int set_border_hitboxes(hitbox_t *hitbox, sfRenderWindow *window)
{
    int count = 0;

    if (count == 0) {
        count = set_left_border(hitbox, window, count);
    }
    if (count < 2) {
        count = set_right_border(hitbox, window, count);
    }
    if (count < 4) {
        count = set_bottom_border(hitbox, window, count);
    }
    return (0);
}