/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** set_first_level_hitboxes.c
*/

#include "../../../../include/templates/hitboxes.h"

void set_hitbox(hitbox_t *hitbox, sfRenderWindow *window)
{
    int progress = 0;

    if (progress < 2) {
        progress = first_hitboxes(hitbox, window, progress);
    }
    if (progress < 4) {
        progress = second_hitboxes(hitbox, window, progress);
    }
    if (progress < 6) {
        progress = third_hitboxes(hitbox, window, progress);
    }
    if (progress < 8) {
        progress = fourth_hitboxes(hitbox, window, progress);
    }
    if (progress < 9) {
        progress = fifth_hitboxes(hitbox, window, progress);
    }
    set_border_hitboxes(hitbox, window);
}