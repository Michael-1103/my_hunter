/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** victory
*/

#include "my_hunter.h"

void display_victory(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    sfSprite_destroy(duck_st->sprite_duck);
    duck_st->sprite_duck = sfSprite_create();
    sfRenderWindow_clear(my_hunter->window, sfBlack);
    sfRenderWindow_drawSprite(my_hunter->window, my_hunter->background, NULL);
    sfRenderWindow_drawText(my_hunter->window, my_hunter->win, NULL);
    sfRenderWindow_display(my_hunter->window);
    if (sfMusic_getVolume(my_hunter->win_sound) == 100) {
        sfMusic_play(my_hunter->win_sound);
        sfSleep(sfSeconds(1.5));
        sfMusic_setVolume(my_hunter->win_sound, 0);
    }
}

void reset_game(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        my_hunter->score_int = 0;
        duck_st->sprite_duck = sfSprite_create();
        sfSprite_setTexture(duck_st->sprite_duck, my_hunter->duck, sfTrue);
        sfSprite_setTextureRect(duck_st->sprite_duck, duck_st->rect);
        int_to_str(my_hunter->score_int, my_hunter->score_str);
        sfText_setString(my_hunter->score, my_hunter->score_str);
        duck_st->x = -110;
        duck_st->y = rand() % 740;
        sfMusic_setVolume(my_hunter->win_sound, 100);
    }
}

void check_victory(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (my_hunter->score_int >= 5000) {
        display_victory(my_hunter, duck_st);
        reset_game(my_hunter, duck_st);
    }
}
