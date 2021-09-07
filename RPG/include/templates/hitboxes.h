/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** hitboxes.h
*/

#ifndef HITBOXES_H_
#define HITBOXES_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct hitbox_template_s
{
    sfRectangleShape *rectangle;

    sfVector2f size;
    sfVector2f position;
} hitbox_t;

void create_hitbox(hitbox_t *hitbox, sfRenderWindow *window);
void set_hitbox(hitbox_t *hitbox, sfRenderWindow *window);
int first_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress);
int second_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress);
int third_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress);
int fourth_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress);
int fifth_hitboxes(hitbox_t *hitbox, sfRenderWindow *window, int progress);
int set_border_hitboxes(hitbox_t *hitbox, sfRenderWindow *window);

#endif