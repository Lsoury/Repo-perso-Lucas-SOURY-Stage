/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** open_map.c
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../../include/level3.h"
#include "../../../../include/myrpg.h"

char *get_lv3_size(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    char filepath[] = "src/levels/3lvl/map/map3.txt";
    int size = 2279;
    int read_value = 0;
    LVL3_STRUCT->fd = open(filepath, O_RDONLY);
    char buffer[size];

    if (LVL3_STRUCT->fd < 0)
        return (NULL);
    read_value = read(LVL3_STRUCT->fd, buffer, size);
    if (read_value < 0)
        return (NULL);
    buffer[size] = '\0';
    LVL3_STRUCT->read_buffer = buffer;
    LVL3_STRUCT->map = fill_tab(buffer);
    lv3_create_map(game, window, anim);
}

int lv3_open_map(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    LVL3_STRUCT->read_buffer = malloc(sizeof(char) * 2279);
    if (LVL3_STRUCT->read_buffer == NULL)
        return (84);
    LVL3_STRUCT->read_buffer = get_lv3_size(game, window, anim);
    if (game->lvl3_scene_idx == 0) {
        LVL3_STRUCT->x = 1;
        LVL3_STRUCT->y = 33;
        anim->pos.x = LVL3_STRUCT->x;
        anim->pos.y = (LVL3_STRUCT->y - 2) * 30;
        sprite_display(anim->move, anim->down_texture, anim->rect_down, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
        game->lvl3_scene_idx++;
    }
    lv3_sprite_animation(anim, game, window);
    sfRenderWindow_drawSprite(window, anim->move, NULL);
}