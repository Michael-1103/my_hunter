/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** sound
*/
#include "my_hunter.h"

void sound(sfMusic* music)
{
    if (sfMusic_getStatus(music) == sfPaused)
        sfMusic_play(music);
    else
        sfMusic_pause(music);
}

void cleanup(my_hunter_t *my_hunter)
{
    sfClock_destroy(my_hunter->clocks);
    sfRenderWindow_destroy(my_hunter->window);
    sfSprite_destroy(my_hunter->background);
    sfTexture_destroy(my_hunter->texture);
    sfTexture_destroy(my_hunter->duck);
    sfFont_destroy(my_hunter->font);
    sfText_destroy(my_hunter->score);
    sfMusic_destroy(my_hunter->music);
    sfMusic_destroy(my_hunter->kill_sound);
    sfMusic_destroy(my_hunter->win_sound);
    sfMusic_destroy(my_hunter->duck_sound);
    sfMusic_destroy(my_hunter->menu_music);
    sfTexture_destroy(my_hunter->menu_background);
    sfSprite_destroy(my_hunter->sprite_menu_background);
    sfTexture_destroy(my_hunter->button);
    sfSprite_destroy(my_hunter->sprite_button);
    sfTexture_destroy(my_hunter->button2);
    sfSprite_destroy(my_hunter->sprite_button2);
}
