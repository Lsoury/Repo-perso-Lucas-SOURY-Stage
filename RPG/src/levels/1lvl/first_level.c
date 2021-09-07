/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** first_level.c
*/

#include "../../../include/templates/hitboxes.h"
#include "../../../include/templates/image.h"
#include "../../../include/myrpg.h"

int level1(game_t *game, sfRenderWindow *window, anim_t *anim)
{
    image_t image;
    hitbox_t hitbox;
    image.position.x = 660;
    image.position.y = 240;
    char const filepath[] = "ressources/first_chamber600x600.jpg";

    set_image(&image, window, filepath);
    set_hitbox(&hitbox, window);
    return (0);
}