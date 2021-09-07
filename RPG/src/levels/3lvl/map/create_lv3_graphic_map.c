/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** create_graphic_map.c
*/

#include "../../../../include/level3.h"
#include "../../../../include/templates/image.h"
#include "../../../../include/myrpg.h"

void lv3_sprite_call(game_t *game, sfRenderWindow *window, sfVector2f pos)
{
    image_t image;
    char filepath_a[] = "ressources/map_sprite/background/background_tree.png";
    char filepath_b[] = "ressources/map_sprite/background/bottom_tree.png";
    char filepath_z[] = "ressources/map_sprite/background/dirt/basic_dirt.png";
    char filepath_w[] = "ressources/map_sprite/background/dirt/center_dirt.png";

    if (LVL3_STRUCT->map[LVL3_STRUCT->map_x][LVL3_STRUCT->map_y] == 'a') {
        set_image_with_pos(&image, window, filepath_z, pos);
        set_image_with_pos(&image, window, filepath_a, pos);
    }
    if (LVL3_STRUCT->map[LVL3_STRUCT->map_x][LVL3_STRUCT->map_y] == 'b') {
        set_image_with_pos(&image, window, filepath_z, pos);
        set_image_with_pos(&image, window, filepath_b, pos);
    }
    if (LVL3_STRUCT->map[LVL3_STRUCT->map_x][LVL3_STRUCT->map_y] == 'w')
        set_image_with_pos(&image, window, filepath_w, pos);
    if (LVL3_STRUCT->map[LVL3_STRUCT->map_x][LVL3_STRUCT->map_y] == 'z')
        set_image_with_pos(&image, window, filepath_z, pos);
}

int lv3_create_map(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    LVL3_STRUCT->map_x = 1;
    LVL3_STRUCT->map_y = 0;
    sfVector2f pos;
    pos.x = 0;
    pos.y = 0;

    while (LVL3_STRUCT->map[LVL3_STRUCT->map_x] != NULL) {
        while (LVL3_STRUCT->map_y != 65) {
            lv3_sprite_call(game, window, pos);
            pos.x += 30;
            LVL3_STRUCT->map_y++;
        }
        pos.x = 0;
        LVL3_STRUCT->map_y = 0;
        pos.y += 30;
        LVL3_STRUCT->map_x++;
    }
    return (0);
}