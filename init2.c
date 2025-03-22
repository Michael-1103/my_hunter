/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** init2
*/

#include "my_hunter.h"

static void initialize_menu_background(my_hunter_t *my_hunter)
{
    my_hunter->menu_background = sfTexture_createFromFile
    ("ressources/sprite/menu_background.jpg", NULL);
    my_hunter->sprite_menu_background = sfSprite_create();
    sfSprite_setTexture(my_hunter->sprite_menu_background,
    my_hunter->menu_background, sfTrue);
}

static void initialize_menu_plate(my_hunter_t *my_hunter)
{
    my_hunter->menu_plate = sfTexture_createFromFile
    ("ressources/sprite/menu_plate.png", NULL);
    my_hunter->sprite_menu_plate = sfSprite_create();
    sfSprite_setTexture(my_hunter->sprite_menu_plate,
    my_hunter->menu_plate, sfTrue);
    sfSprite_setPosition(my_hunter->sprite_menu_plate, (sfVector2f){425, 200});
    sfSprite_setScale(my_hunter->sprite_menu_plate, (sfVector2f){0.8, 0.8});
}

static void initialize_menu_buttons(my_hunter_t *my_hunter)
{
    my_hunter->button = sfTexture_createFromFile
    ("ressources/sprite/button.png", NULL);
    my_hunter->sprite_button = sfSprite_create();
    sfSprite_setTexture(my_hunter->sprite_button,
    my_hunter->button, sfTrue);
    sfSprite_setPosition(my_hunter->sprite_button, (sfVector2f){700, 325});
    my_hunter->button2 = sfTexture_createFromFile
    ("ressources/sprite/button2.png", NULL);
    my_hunter->sprite_button2 = sfSprite_create();
    sfSprite_setTexture(my_hunter->sprite_button2,
    my_hunter->button2, sfTrue);
    sfSprite_setPosition(my_hunter->sprite_button2, (sfVector2f){700, 600});
}

void initialize_menu_title(my_hunter_t *my_hunter)
{
    my_hunter->title = sfTexture_createFromFile
    ("ressources/sprite/title.png", NULL);
    my_hunter->sprite_title = sfSprite_create();
    sfSprite_setTexture(my_hunter->sprite_title, my_hunter->title, sfTrue);
    sfSprite_setPosition(my_hunter->sprite_title, (sfVector2f){650, 125});
}

void initialize_menu_music(my_hunter_t *my_hunter)
{
    my_hunter->menu_music = sfMusic_createFromFile
    ("ressources/music/menu_music.ogg");
    sfMusic_setLoop(my_hunter->menu_music, sfTrue);
    sfMusic_play(my_hunter->menu_music);
}

void initialize_menu(my_hunter_t *my_hunter)
{
    initialize_menu_background(my_hunter);
    initialize_menu_plate(my_hunter);
    initialize_menu_buttons(my_hunter);
    initialize_menu_title(my_hunter);
    initialize_menu_music(my_hunter);
}
