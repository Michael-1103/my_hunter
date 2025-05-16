/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** init
*/

#include "my_hunter.h"

void init_duck(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    duck_st->x = -110;
    duck_st->y = rand() % 740;
    duck_st->rect.top = 0;
    duck_st->rect.left = 0;
    duck_st->rect.width = 110;
    duck_st->rect.height = 110;
    duck_st->sprite_duck = sfSprite_create();
    sfSprite_setTexture(duck_st->sprite_duck, my_hunter->duck, sfTrue);
    sfSprite_setTextureRect(duck_st->sprite_duck, duck_st->rect);
    sfSprite_setPosition(duck_st->sprite_duck, (sfVector2f){-110, 425});
}

void sprite_init(my_hunter_t *my_hunter)
{
    if (my_hunter->game == 0)
        my_hunter->duck = sfTexture_createFromFile
        ("ressources/sprite/duck.png", NULL);
    if (my_hunter->game == 1)
        my_hunter->duck = sfTexture_createFromFile
        ("ressources/sprite/plankton.png", NULL);
    if (my_hunter->game == 2)
        my_hunter->duck = sfTexture_createFromFile
        ("ressources/sprite/bill.png", NULL);
}

void init_window_and_background(my_hunter_t *my_hunter)
{
    sfVideoMode mode = {my_hunter->width_window, my_hunter->height_window, 32};

    my_hunter->window = sfRenderWindow_create(mode,
    "My Hunter", sfResize | sfClose, NULL);
    my_hunter->score_int = 0;
    my_hunter->clocks = sfClock_create();
    if (my_hunter->game == 0)
        my_hunter->texture = sfTexture_createFromFile
        ("ressources/sprite/background.jpg", NULL);
    if (my_hunter->game == 1)
        my_hunter->texture = sfTexture_createFromFile
        ("ressources/sprite/background2.jpg", NULL);
    if (my_hunter->game == 2)
        my_hunter->texture = sfTexture_createFromFile
        ("ressources/sprite/background3.jpg", NULL);
    my_hunter->background = sfSprite_create();
    sfSprite_setTexture(my_hunter->background, my_hunter->texture, sfTrue);
    sprite_init(my_hunter);
}

static void init_font(my_hunter_t *my_hunter)
{
    if (my_hunter->game == 0)
        my_hunter->font = sfFont_createFromFile
        ("ressources/fonts/gomarice_rocks.ttf");
    if (my_hunter->game == 1)
        my_hunter->font = sfFont_createFromFile
        ("ressources/fonts/krabby_patty.ttf");
    if (my_hunter->game == 2)
        my_hunter->font = sfFont_createFromFile
        ("ressources/fonts/gravity_falls.ttf");
}

static void init_text(my_hunter_t *my_hunter)
{
    init_font(my_hunter);
    my_hunter->score = sfText_create();
    sfText_setColor(my_hunter->score, sfBlack);
    int_to_str(my_hunter->score_int, my_hunter->score_str);
    sfText_setString(my_hunter->score, my_hunter->score_str);
    sfText_setFont(my_hunter->score, my_hunter->font);
    sfText_setCharacterSize(my_hunter->score, 50);
    my_hunter->win = sfText_create();
    sfText_setColor(my_hunter->win, sfBlack);
    sfText_setString(my_hunter->win, "   You win !\nPress space\n to restart");
    sfText_setFont(my_hunter->win, my_hunter->font);
    sfText_setCharacterSize(my_hunter->win, 100);
    sfText_setPosition(my_hunter->win, (sfVector2f){700, 400});
}

static void init_sounds(my_hunter_t *my_hunter)
{
    my_hunter->kill_sound = sfMusic_createFromFile
    ("ressources/music/kill.ogg");
    my_hunter->win_sound = sfMusic_createFromFile
    ("ressources/music/win.ogg");
    my_hunter->duck_sound = sfMusic_createFromFile
    ("ressources/music/duck.ogg");
}

static void init_music(my_hunter_t *my_hunter)
{
    if (my_hunter->game == 0)
        my_hunter->music = sfMusic_createFromFile
        ("ressources/music/music.ogg");
    if (my_hunter->game == 1)
        my_hunter->music = sfMusic_createFromFile
        ("ressources/music/music2.ogg");
    if (my_hunter->game == 2)
        my_hunter->music = sfMusic_createFromFile
        ("ressources/music/music3.ogg");
    sfMusic_play(my_hunter->music);
}

void init_text_and_sounds(my_hunter_t *my_hunter)
{
    init_text(my_hunter);
    init_sounds(my_hunter);
    init_music(my_hunter);
}

static void init_game(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    init_window_and_background(my_hunter);
    init_text_and_sounds(my_hunter);
    init_duck(my_hunter, duck_st);
}

void initialize_game(my_hunter_t *my_hunter, duck_st_t *duck_st)
{
    sfMusic_stop(my_hunter->menu_music);
    init_game(my_hunter, duck_st);
}
