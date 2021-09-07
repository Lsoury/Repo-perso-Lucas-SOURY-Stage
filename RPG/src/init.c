/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init.c
*/

#include "../include/myrpg.h"
#include "../include/templates/image.h"
#include "../include/templates/fight.h"

int init_struct(game_t *game, battle_t *fight)
{
    game->image = malloc(sizeof(image_t));
    LVL2_STRUCT = malloc(sizeof(lvl2_t));
    LVL3_STRUCT = malloc(sizeof(lvl3_t));
    fight->hud = malloc(sizeof(struct buttons));
    game->menu = malloc(sizeof(struct menu));
    game->text = malloc(sizeof(struct text));
    game->ennemy = malloc(sizeof(struct ennemy));
    MUSIC = malloc(sizeof(struct sound));
    QUEST = malloc(sizeof(struct quest));
    if (game->image == NULL || \
    fight->hud == NULL || game->menu == NULL || game->text == NULL || \
    QUEST == NULL || MUSIC == NULL || LVL2_STRUCT == NULL || \
    LVL3_STRUCT == NULL || game->ennemy == NULL)
        return (1);
    else
        return (0);
}

int init_var2(game_t *game, battle_t *fight)
{
    fight->filepath[0] = "ressources/Battle_sprites/Blow.png";
    fight->filepath[1] = "ressources/Battle_sprites/Claw.png";
    fight->filepath[2] = "ressources/Battle_sprites/Slash.png";
    fight->filepath[3] = "ressources/Battle_sprites/Slash.png";
    game->text->police_char = sfFont_createFromFile( \
    "ressources/Font/mplus-1m-regular.ttf");
    if (game->text->police_char == NULL || init_quest(game) == 1 || \
    init_music_start(game) == 1 || init_menu_var(game) == 1 || \
    init_ennemy_pos(game) == 1 || init_end(game) == 1)
        return (1);
    game->which_ennemy = -1;
    game->clock = sfClock_create();
    game->player_choice = 0;
    fight->bonus_attack = 0;
    game->endgame = 0;
    fight->hud->pos.x = (game->w / 5 - ((game->w / 6) / 6));
    fight->hud->pos.y = (game->h - (game->h / 6));
    fight->hud->size.x = (game->w / 8);
    fight->hud->size.y = (game->h / 7);
    game->which_scene = 0;
    return (0);
}

int init_var(game_t *game, battle_t *fight)
{
    game->menu_color.r = 109;
    game->menu_color.g = 7;
    game->menu_color.b = 26;
    game->menu_color.a = 255;
    game->m_menu_color.r = 89;
    game->m_menu_color.g = 7;
    game->m_menu_color.b = 26;
    game->m_menu_color.a = 255;
    fight->pos_background.x = 0;
    fight->pos_background.y = 0;
    fight->pos_player.x = 300;
    fight->pos_player.y = 500;
    fight->pos_ennemy.x = 1300;
    fight->pos_ennemy.y = 500;
    game->w = 1920;
    game->h = 1080;
    fight->life_player = 1000;
    fight->in_fight = 0;
    if (init_var2(game, fight) == 1)
        return (1);
    return (0);
}

int init_all(game_t *game, battle_t *fight)
{
    if (init_struct(game, fight) == 1)
        return (1);
    if (init_var(game, fight) == 1)
        return (1);
    if (create_hud(game, fight) == 1)
        return (1);
    return (0);
}

int init_array(game_t *game, sfRenderWindow *window, sfEvent event)
{
    game->scene_idx = 0;
    window = create_window(window);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (open_window(game, window, event) == 1) {
        return (1);
    }
    return (0);
}