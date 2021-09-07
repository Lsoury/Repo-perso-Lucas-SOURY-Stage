/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** first_hitboxes_data.c
*/

#include "../../../../include/templates/hitboxes.h"

int first_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress)
{
    if (progress == 0) {
        hitbox->size.x = 100;
        hitbox->size.y = 165;
        hitbox->position.x = 1920 / 2 - 260;
        hitbox->position.y = 1080 / 2 - 129;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    if (progress == 1) {
        hitbox->size.x = 600;
        hitbox->size.y = 200;
        hitbox->position.x = 1920 / 2 - 300;
        hitbox->position.y = 1080 / 2 - 300;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    return (progress);
}

int second_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress)
{
    if (progress == 2) {
        hitbox->size.x = 86;
        hitbox->size.y = 123;
        hitbox->position.x = 1920 / 2 + 105;
        hitbox->position.y = 1080 / 2 - 177;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    if (progress == 3) {
        hitbox->size.x = 86;
        hitbox->size.y = 153;
        hitbox->position.x = 1920 / 2 + 195;
        hitbox->position.y = 1080 / 2 - 150;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    return (progress);
}

int third_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress)
{
    if (progress == 4) {
        hitbox->size.x = 165;
        hitbox->size.y = 100;
        hitbox->position.x = 1920 / 2 + 126;
        hitbox->position.y = 1080 / 2;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    if (progress == 5) {
        hitbox->size.x = 44;
        hitbox->size.y = 70;
        hitbox->position.x = 1920 / 2 + 20;
        hitbox->position.y = 1080 / 2 - 125;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    return (progress);
}

int fourth_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress)
{
    if (progress == 6) {
        hitbox->size.x = 80;
        hitbox->size.y = 50;
        hitbox->position.x = 1920 / 2 - 250;
        hitbox->position.y = 1080 / 2 + 53;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    if (progress == 7) {
        hitbox->size.x = 65;
        hitbox->size.y = 65;
        hitbox->position.x = 1920 / 2 - 130;
        hitbox->position.y = 1080 / 2 - 110;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    return (progress);
}

int fifth_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress)
{
    if (progress == 8) {
        hitbox->size.x = 195;
        hitbox->size.y = 100;
        hitbox->position.x = 1920 / 2 - 55;
        hitbox->position.y = 1080 / 2 + 196;
        create_hitbox(hitbox, window);
        sfRectangleShape_destroy(hitbox->rectangle);
        progress++;
    }
    return (progress);
}