/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** destroy_all.c
*/

#include "../include/myrpg.h"
#include "../include/templates/fight.h"

void destroy_menu(game_t *game)
{
    sfRectangleShape_destroy(game->menu->exit);
    sfRectangleShape_destroy(game->menu->p_exit);
    sfRectangleShape_destroy(game->menu->p_resume);
    sfRectangleShape_destroy(game->menu->play);
    sfText_destroy(game->text->g_exit);
    sfText_destroy(game->text->g_play);
    sfText_destroy(game->text->g_resume);
    sfText_destroy(game->text->p_exit);
    sfFont_destroy(game->text->police_char);
    sfSprite_destroy(game->menu->background);
    sfTexture_destroy(game->menu->t_back);
}

void destroy_quest(game_t *game)
{
    sfSprite_destroy(QUEST->hp_player);
    sfTexture_destroy(QUEST->t_hp[0]);
    sfTexture_destroy(QUEST->t_hp[1]);
    sfTexture_destroy(QUEST->t_hp[2]);
    sfRectangleShape_destroy(QUEST->hud);
}

void free_all(game_t *game, battle_t *fight, anim_t *anim)
{
    destroy_music(game);
    free(fight->hud);
    free(fight);
    free(game->image);
    destroy_menu(game);
    free(game->menu);
    free(game->text);
    destroy_music(game);
    free(MUSIC);
    destroy_quest(game);
    free(QUEST);
}