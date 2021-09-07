/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** first_screen_mvt.c
*/

#include <stdlib.h>
#include "../../include/struct.h"
#include "../../include/myrpg.h"

int left_movement(anim_t *ani, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        sprite_display(ani->move, ani->left_texture, ani->rect_left, \
        ani->pos);
        sfRenderWindow_drawSprite(window, ani->move, NULL);
        if (checktime(game, time_set) == sfTrue)
            next_step(ani, &ani->rect_left, ani->move);
        if (ani->hitbox_pos.x - 5 < 660)
            return (0);
        ani->pos.x -= 5;
        ani->hitbox_pos.x -= 5;
        ani->check_stop = 0;
    }
    return (0);
}

int right_movement(anim_t *ani, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        sprite_display(ani->move, ani->right_texture, ani->rect_right, \
        ani->pos);
        sfRenderWindow_drawSprite(window, ani->move, NULL);
        if (checktime(game, time_set) == sfTrue)
            next_step(ani, &ani->rect_right, ani->move);
        if (ani->hitbox_pos.x + 5 > 1210)
            return (0);
        ani->pos.x += 5;
        ani->hitbox_pos.x += 5;
        ani->check_stop = 1;
    }
    return (0);
}

int up_movement(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        sprite_display(anim->move, anim->up_texture, anim->rect_up, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
        if (checktime(game, time_set) == sfTrue)
            next_step(anim, &anim->rect_up, anim->move);
        if (anim->hitbox_pos.y - 5 < 490)
            return (0);
        anim->pos.y -= 5;
        anim->hitbox_pos.y -= 5;
        anim->check_stop = 2;
    }
}

int down_movement(anim_t *anim, sfRenderWindow *window, game_t *game, \
int time_set)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        sprite_display(anim->move, anim->down_texture, anim->rect_down, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
        if (checktime(game, time_set) == sfTrue)
            next_step(anim, &anim->rect_down, anim->move);
        if (anim->hitbox_pos.y - 5 > 790 && anim->hitbox_pos.x > 1100) {
            game->scene_idx = 1;
            destroy_music(game);
            init_music_field(game);
            return (0);
        }
        if (anim->hitbox_pos.y - 5 > 815)
            return (0);
        anim->pos.y += 5;
        anim->hitbox_pos.y += 5;
        anim->check_stop = 3;
    }
}
