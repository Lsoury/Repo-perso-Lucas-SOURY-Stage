/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** set_image.c
*/

#include "../../include/struct.h"
#include "../../include/templates/image.h"

int set_image(image_t *image, sfRenderWindow *window, \
                    char const *filepath)
{
    image->texture = sfTexture_createFromFile(filepath, NULL);
    if (image->texture == NULL) {
        return (84);
    }
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, \
        image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, \
        image->position);
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    return (0);
}

int set_image_with_pos(image_t *image, sfRenderWindow *window, \
                    char const *filepath, sfVector2f pos)
{
    image->texture = sfTexture_createFromFile(filepath, NULL);
    if (image->texture == NULL) {
        return (84);
    }
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, \
        image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, \
        pos);
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    return (0);
}