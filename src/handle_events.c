/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** handle_events
*/

#include "my_hunter.h"

void handle_mouse_events(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (my_hunter->event.mouseButton.y <= duck_st->y + 110) {
        sfSprite_destroy(duck_st->sprite_duck);
        duck_st->sprite_duck = sfSprite_create();
        sfSprite_setTexture(duck_st->sprite_duck, my_hunter->duck, sfTrue);
        sfSprite_setTextureRect(duck_st->sprite_duck, duck_st->rect);
        sfMusic_play(my_hunter->kill_sound);
        duck_st->x = -110;
        duck_st->y = rand() % 914;
        my_hunter->score_int += 100;
        int_to_str(my_hunter->score_int, my_hunter->score_str);
        sfText_setString(my_hunter->score, my_hunter->score_str);
    }
}

void handle_keyboard_events(my_hunter_t *my_hunter)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) && sfKeyboard_isKeyPressed(sfKeyO)) {
        my_hunter->score_int += 100;
        int_to_str(my_hunter->score_int, my_hunter->score_str);
        sfText_setString(my_hunter->score, my_hunter->score_str);
    }
    if (sfKeyboard_isKeyPressed(sfKeyM)) {
        sound(my_hunter->music);
    }
}

void some_event(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (my_hunter->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(my_hunter->window);
        sfMusic_stop(my_hunter->music);
        sfSleep(sfMilliseconds(100));
        main(0, NULL);
        }
    if (my_hunter->event.mouseButton.button == sfMouseLeft) {
        if (my_hunter->event.mouseButton.x >= duck_st->x
            && my_hunter->event.mouseButton.x <= duck_st->x + 110
            && my_hunter->event.mouseButton.y >= duck_st->y
            && my_hunter->event.mouseButton.y <= duck_st->y + 110) {
            handle_mouse_events(my_hunter, duck_st);
        }
    }
}

void handle_arguments(int argc, char **argv,
    my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        my_hunter->game = -1;
    }
    my_hunter->width_window = 1920;
    my_hunter->height_window = 1024;
    duck_st->speed = 2;
}
