/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** lv_2_sprite_anim.c
*/

#include "../../../../include/struct.h"
#include "../../../../include/level2.h"

int lv3_move_left(anim_t *anim, game_t *game, sfRenderWindow *window)
{
    if (LVL3_STRUCT->map[LVL3_STRUCT->y][LVL3_STRUCT->x - 1] == 'w' || \
    LVL3_STRUCT->map[LVL3_STRUCT->y][LVL3_STRUCT->x - 1] == 'z') {
        LVL3_STRUCT->x--;
        anim->pos.x -= 30;
        sprite_display(anim->move, anim->left_texture, anim->rect_left, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    anim->check_stop = 0;
    return (0);
}

int lv3_move_right(anim_t *anim, game_t *game, sfRenderWindow *window)
{
    if (LVL3_STRUCT->map[LVL3_STRUCT->y][LVL3_STRUCT->x + 1] == 'w' || \
    LVL3_STRUCT->map[LVL3_STRUCT->y][LVL3_STRUCT->x + 1] == 'z') {
        LVL3_STRUCT->x++;
        anim->pos.x += 30;
        sprite_display(anim->move, anim->right_texture, anim->rect_right, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    anim->check_stop = 1;
    return (0);
}

int lv3_move_up(anim_t *anim, game_t *game, sfRenderWindow *window)
{
    if (LVL3_STRUCT->map[LVL3_STRUCT->y - 1][LVL3_STRUCT->x] == 'z' || \
    LVL3_STRUCT->map[LVL3_STRUCT->y - 1][LVL3_STRUCT->x] == 'w') {
        LVL3_STRUCT->y--;
        anim->pos.y -= 30;
        sprite_display(anim->move, anim->up_texture, anim->rect_up, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    anim->check_stop = 2;
    return (0);
}

int lv3_move_down(anim_t *anim, game_t *game, sfRenderWindow *window)
{
    if (LVL3_STRUCT->map[LVL3_STRUCT->y + 1][LVL3_STRUCT->x] == 'z' || \
    LVL3_STRUCT->map[LVL3_STRUCT->y + 1][LVL3_STRUCT->x] == 'w') {
        LVL3_STRUCT->y++;
        anim->pos.y += 30;
        sprite_display(anim->move, anim->down_texture, anim->rect_down, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
    }
    anim->check_stop = 3;
    return (0);
}

int lv3_sprite_animation(anim_t *anim, game_t *game, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        lv3_move_left(anim, game, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        lv3_move_right(anim, game, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        lv3_move_up(anim, game, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        lv3_move_down(anim, game, window);
    }
    return (0);
}