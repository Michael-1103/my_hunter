/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** menu
*/

#include "my_hunter.h"

int is_button_clicked(sfSprite *button, sfEvent event)
{
    sfFloatRect button_bounds;

    if (event.type == sfEvtMouseButtonPressed) {
        button_bounds = sfSprite_getGlobalBounds(button);
        if (sfFloatRect_contains(&button_bounds, event.mouseButton.x,
            event.mouseButton.y)) {
            return 1;
        }
    }
    return 0;
}

static int menu_event(my_hunter_t *my_hunter)
{
    if (my_hunter->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(my_hunter->window);
        my_hunter->game = -1;
        return 1;
    }
    if (is_button_clicked(my_hunter->sprite_button, my_hunter->event)) {
        my_hunter->game = 0;
        return 1;
    }
    if (is_button_clicked(my_hunter->sprite_button2, my_hunter->event)) {
        my_hunter->game = rand() % 2 + 1;
        return 1;
    }
    return 0;
}

void menu(my_hunter_t *my_hunter)
{
    initialize_menu(my_hunter);
    while (sfRenderWindow_isOpen(my_hunter->window)) {
        while (sfRenderWindow_pollEvent(my_hunter->window,
            &my_hunter->event)) {
        }
        if (menu_event(my_hunter))
            return;
        sfRenderWindow_clear(my_hunter->window, sfBlack);
        sfRenderWindow_drawSprite(my_hunter->window,
        my_hunter->sprite_menu_background, NULL);
        sfRenderWindow_drawSprite(my_hunter->window,
        my_hunter->sprite_menu_plate, NULL);
        sfRenderWindow_drawSprite(my_hunter->window,
        my_hunter->sprite_title, NULL);
        sfRenderWindow_drawSprite(my_hunter->window,
        my_hunter->sprite_button, NULL);
        sfRenderWindow_drawSprite(my_hunter->window,
        my_hunter->sprite_button2, NULL);
        sfRenderWindow_display(my_hunter->window);
    }
}
