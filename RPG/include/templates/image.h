/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** image.h
*/

#ifndef IMAGE_H_
#define IMAGE_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct image_template_s
{
    sfTexture *texture;

    sfSprite *sprite;

    sfVector2f position;
} image_t;

int set_image(image_t *image, sfRenderWindow *window, char const *filepath);
int set_image_with_pos(image_t *image, sfRenderWindow *window, \
                    char const *filepath, sfVector2f pos);

#endif