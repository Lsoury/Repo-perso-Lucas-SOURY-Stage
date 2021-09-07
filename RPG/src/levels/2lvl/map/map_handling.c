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
#include "../../../../include/level2.h"
#include "../../../../include/myrpg.h"

char *get_size(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    char filepath[] = "src/levels/2lvl/map/map2.txt";
    int size = 2279;
    int read_value = 0;
    LVL2_STRUCT->fd = open(filepath, O_RDONLY);
    char buffer[size];

    if (LVL2_STRUCT->fd < 0)
        return (NULL);
    read_value = read(LVL2_STRUCT->fd, buffer, size);
    if (read_value < 0)
        return (NULL);
    buffer[size] = '\0';
    LVL2_STRUCT->read_buffer = buffer;
    LVL2_STRUCT->map = fill_tab(buffer);
    create_map(game, window, anim);
}

int open_map(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    LVL2_STRUCT->read_buffer = malloc(sizeof(char) * 2279);
    if (LVL2_STRUCT->read_buffer == NULL)
        return (84);
    LVL2_STRUCT->read_buffer = get_size(game, window, anim);
    if (game->scene2_idx == 0) {
        LVL2_STRUCT->x = 12;
        LVL2_STRUCT->y = 1;
        anim->pos.x = LVL2_STRUCT->x * 30;
        anim->pos.y = LVL2_STRUCT->y;
        sprite_display(anim->move, anim->down_texture, anim->rect_down, \
        anim->pos);
        sfRenderWindow_drawSprite(window, anim->move, NULL);
        game->scene2_idx++;
    }
    lv2_sprite_animation(anim, game, window);
    sfRenderWindow_drawSprite(window, anim->move, NULL);
    return (0);
}