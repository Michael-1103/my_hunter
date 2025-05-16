/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** my_hunter
*/

#include "my_hunter.h"

void update_duck_position(duck_st_t *duck_st, my_hunter_t *my_hunter)
{
    if (duck_st->x >= my_hunter->width_window) {
        duck_st->x = -110;
    }
}

void main_part2(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    if (my_hunter->seconds > 0.2) {
        move_rect(&duck_st->rect, 110, 330);
        sfSprite_setTextureRect(duck_st->sprite_duck, duck_st->rect);
        sfClock_restart(my_hunter->clocks);
    }
    some_event(my_hunter, duck_st);
    sfSprite_setPosition(duck_st->sprite_duck,
    (sfVector2f){duck_st->x += duck_st->speed, duck_st->y});
    handle_keyboard_events(my_hunter);
    if (sfMusic_getStatus(my_hunter->music) == sfStopped)
        sfMusic_play(my_hunter->music);
    update_duck_position(duck_st, my_hunter);
    check_victory(my_hunter, duck_st);
}

void refresh_game(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    sfRenderWindow_clear(my_hunter->window, sfBlack);
    sfRenderWindow_drawSprite(my_hunter->window,
    my_hunter->background, NULL);
    sfRenderWindow_drawSprite(my_hunter->window,
    duck_st->sprite_duck, NULL);
    sfRenderWindow_drawText(my_hunter->window, my_hunter->score, NULL);
    sfRenderWindow_display(my_hunter->window);
}

void game_loop(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    initialize_game(my_hunter, duck_st);
    while (sfRenderWindow_isOpen(my_hunter->window)){
        while (sfRenderWindow_pollEvent(my_hunter->window, &my_hunter->event)){
        }
        my_hunter->times = sfClock_getElapsedTime(my_hunter->clocks);
        my_hunter->seconds = my_hunter->times.microseconds / 1000000.0;
        main_part2(my_hunter, duck_st);
        if (my_hunter->score_int >= 5000)
            continue;
        refresh_game(my_hunter, duck_st);
    }
}

static void clean(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    cleanup(my_hunter);
    free(duck_st);
    free(my_hunter);
}

int main(int argc, char **argv)
{
    duck_st_t *duck_st = malloc(sizeof(duck_st_t));
    my_hunter_t *my_hunter = malloc(sizeof(my_hunter_t));
    sfVideoMode mode = {1920, 1024, 32};

    my_hunter->game = 0;
    while (my_hunter->game != -1) {
        handle_arguments(argc, argv, my_hunter, duck_st);
        if (my_hunter->game != -1)
            my_hunter->window = sfRenderWindow_create(mode,
            "My Hunter", sfResize | sfClose, NULL);
        if (my_hunter->game == -1)
            return 0;
        menu(my_hunter);
        if (my_hunter->game == -1)
            return 0;
        sfRenderWindow_close(my_hunter->window);
        game_loop(my_hunter, duck_st);
        clean(my_hunter, duck_st);
        return 0;
    }
}
