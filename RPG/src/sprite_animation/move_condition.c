/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** move_condition.c
*/

#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/struct.h"

int init_textures(anim_t *anim)
{
    anim->left_texture = sfTexture_createFromFile("ressources/move_left.png", \
    NULL);
    anim->right_texture = sfTexture_createFromFile(\
    "ressources/move_right.png", NULL);
    anim->up_texture = sfTexture_createFromFile("ressources/move_up.png", NULL);
    anim->down_texture = sfTexture_createFromFile("ressources/move_down.png", \
    NULL);
    return (0);
}

void sprite_display(sfSprite *sprite, sfTexture *texture, sfIntRect rect, \
sfVector2f pos)
{
    sfVector2f scale = (sfVector2f) {1.5, 1.5};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
}

static int set_base_sprite(anim_t *anim, sfRenderWindow *window, game_t *game)
{
    set_base_lr_sprite(anim, window);
    set_base_ud_sprite(anim, window);
    return (0);
}

int set_sprite_hitbox(anim_t *anim, sfRenderWindow *window)
{
    anim->hitbox_size.x = 50;
    anim->hitbox_size.y = 10;
    anim->sprite_hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(anim->sprite_hitbox, anim->hitbox_pos);
    sfRectangleShape_setSize(anim->sprite_hitbox, anim->hitbox_size);
    sfRectangleShape_setFillColor(anim->sprite_hitbox, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, anim->sprite_hitbox, NULL);
    sfRectangleShape_destroy(anim->sprite_hitbox);
}

void move_condition(anim_t *anim, sfRenderWindow *window, game_t *game)
{
    int time_set = 300;

    if (game->scene_idx == 0) {
        set_sprite_hitbox(anim, window);
        set_base_sprite(anim, window, game);
        move_lr_sprite(anim, window, game, time_set);
        move_ud_sprite(anim, window, game, time_set);
    }
}