/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create_window.c
*/

#include <stdlib.h>
#include "../../include/myrpg.h"
#include "../../include/templates/hitboxes.h"
#include "../../include/templates/fight.h"

sfRenderWindow *create_window(sfRenderWindow *window)
{
    sfVideoMode video_mode;
    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_rpg", \
                                    sfDefaultStyle, NULL);
    return (window);
}

void close_window(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int init_anim(anim_t *anim)
{
    init_textures(anim);
    anim->rect_left = initRect(anim->left_texture, anim->rect_left, anim);
    anim->rect_right = initRect(anim->right_texture, anim->rect_right, anim);
    anim->rect_up = initRect(anim->up_texture, anim->rect_up, anim);
    anim->rect_down = initRect(anim->down_texture, anim->rect_down, anim);
    anim->pos = (sfVector2f) {990, 540};
    anim->hitbox_pos = (sfVector2f) {997, 600};
    anim->check_stop = 0;
    anim->move = sfSprite_create();
    return (0);
}

int open_window(game_t *game, sfRenderWindow *window, sfEvent event)
{
    anim_t anim;
    battle_t *fight = malloc(sizeof(battle_t));
    if (init_all(game, fight) == 1 || init_anim(&anim))
        return (1);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_window(event, window);
        }
        sfRenderWindow_clear(window, sfBlack);
        if (game_status(game, window) == 2) {
            free_all(game, fight, &anim);
            return (0);
        }
        if (game->player_choice == 1) {
            if (scene_handling(game, window, &anim, fight) == 1)
                return (1);
            if (fight->in_fight == 0)
                move_condition(&anim, window, game);
        }
        sfRenderWindow_display(window);
    }
}

int game_status(game_t *game, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->player_choice = 2;
    if (game->player_choice == 0)
        menu(game, window);
    if (game->player_choice == 2)
        do_pause(game, window);
    if (game->player_choice == -1)
        return (2);
    if (game->player_choice == 1 && game->which_ennemy != -1)
        sfMusic_pause(game->music->theme);
    if (game->endgame == 1 && game->sound == 1) {
        game->player_choice = 3;
        init_music_lose(game);
    }
    if (game->endgame == 2 && game->sound == 1) {
        game->player_choice = 3;
        init_music_win(game);
    }
    if (game->player_choice == 3)
        draw_end(game, window);
    return (0);
}