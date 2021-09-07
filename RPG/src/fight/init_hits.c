/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-lucas.soury
** File description:
** init_hits.c
*/

#include "../../include/myrpg.h"
#include "../../include/templates/fight.h"

void init_create_rect_hit(battle_t *fight)
{
    fight->rect.top = 0;
    fight->rect.left = 0;
    if (fight->which_attack < 3)
        fight->rect.height = sfTexture_getSize(fight->t_attack).y / 2;
    else
        fight->rect.height = sfTexture_getSize(fight->t_attack).y;
    fight->rect.width = sfTexture_getSize(fight->t_attack).x / 5;
}

void create_texture_for_attack(battle_t *fight, int who)
{
    if (who == 1)
        fight->t_attack = \
        sfTexture_createFromFile(fight->filepath[fight->which_attack - 1], \
        NULL);
    else
        fight->t_attack = \
        sfTexture_createFromFile(fight->filepath[fight->which_attack], NULL);
}

int create_sound_attack(game_t *game, battle_t *fight)
{
    if (fight->which_attack == 0 || fight->which_attack == 1)
    MUSIC->attack = \
    sfMusic_createFromFile("ressources/Battle_sounds/Slash1.ogg");
    if (fight->which_attack == 2)
    MUSIC->attack = \
    sfMusic_createFromFile("ressources/Battle_sounds/Blow1.ogg");
    if (fight->which_attack == 3 || fight->which_attack == 4)
    MUSIC->attack = \
    sfMusic_createFromFile("ressources/Battle_sounds/Attack3.ogg");
    if (MUSIC->attack == NULL)
        return (1);
    sfMusic_setVolume(MUSIC->attack, 2.0);
    return (0);
}

int create_hit(game_t *game, battle_t *fight, int who)
{
    sfVector2f en_pos = sfSprite_getPosition(fight->ennemy);
    sfVector2f pl_pos = sfSprite_getPosition(fight->player);
    en_pos = (sfVector2f) {en_pos.x - game->w / 32, pl_pos.y - game->h / 15};
    pl_pos = (sfVector2f) {pl_pos.x - game->w / 32, pl_pos.y - game->h / 15};

    create_texture_for_attack(fight, who);
    if (fight->t_attack == NULL)
        return (1);
    fight->attack = sfSprite_create();
    init_create_rect_hit(fight);
    sfSprite_setTexture(fight->attack, fight->t_attack, sfFalse);
    if (who == 1)
        sfSprite_setPosition(fight->attack, en_pos);
    else
        sfSprite_setPosition(fight->attack, pl_pos);
    sfSprite_setScale(fight->attack, (sfVector2f) {2, 2});
    if (create_sound_attack(game, fight) == 1)
        return (1);
    return (0);
}

int apply_hit(game_t *game, battle_t *fight, int who, sfRenderWindow *window)
{
    if (fight->current_step == -1)
        if (create_hit(game, fight, who) == 1)
            return (1);
        fight->current_step += 1;
        sfMusic_play(MUSIC->attack);
    if (fight->current_step >= 0)
        draw_attack(fight, window);
    if (fight->current_step == -1) {
        destroy_hit(game, fight);
        if (who == 1)
            fight->which_attack = 0;
        else {
            if (game->which_ennemy != 0)
                do_attack(fight, window, 150, 2);
        else if (game->which_ennemy == 0)
                do_attack(fight, window, 249, 2);
            fight->which_attack = -1;
        }
    }
    return (0);
}