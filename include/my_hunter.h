/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** my_hunter
*/


#ifndef MY_HUNTER_H
    #define MY_HUNTER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>


typedef struct duck_st_s {
    sfSprite* sprite_duck;
    sfIntRect rect;
    int x;
    int y;
    int speed;
} duck_st_t;

typedef struct my_hunter_s {
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* duck;
    sfSprite* background;
    sfFont* font;
    sfText* score;
    sfText* win;
    sfMusic* music;
    sfMusic* kill_sound;
    sfMusic* win_sound;
    sfMusic* duck_sound;
    sfEvent event;
    sfClock* clocks;
    sfTime times;
    float seconds;
    int score_int;
    char score_str[12];
    int game;
    int width_window;
    int height_window;
    sfTexture* menu_background;
    sfSprite* sprite_menu_background;
    sfTexture* button;
    sfSprite* sprite_button;
    sfTexture* button2;
    sfSprite* sprite_button2;
    sfMusic* menu_music;
    sfTexture* menu_plate;
    sfSprite* sprite_menu_plate;
    sfTexture* title;
    sfSprite* sprite_title;
} my_hunter_t;

void int_to_str(int num, char *str);
void move_rect(sfIntRect *rect, int offset, int max_value);
void sound(sfMusic *music);
int main(int ac, char **av);
void init_duck(my_hunter_t *my_hunter, duck_st_t *duck_st);
void init_window_and_background(my_hunter_t *my_hunter);
void init_text_and_sounds(my_hunter_t *my_hunter);
void initialize_game(my_hunter_t *my_hunter, duck_st_t *duck_st);
void help(void);
void update_duck_position(duck_st_t *duck_st, my_hunter_t *my_hunter);
void check_victory(my_hunter_t *my_hunter, duck_st_t *duck_st);
void handle_events(my_hunter_t *my_hunter, duck_st_t *duck_st);
void handle_mouse_events(my_hunter_t *my_hunter, duck_st_t *duck_st);
void handle_keyboard_events(my_hunter_t *my_hunter);
void main_part2(my_hunter_t *my_hunter, duck_st_t *duck_st);
void refresh_game(my_hunter_t *my_hunter, duck_st_t *duck_st);
void handle_arguments(int argc, char **argv,
    my_hunter_t *my_hunter, duck_st_t *duck_st);
void game_loop(my_hunter_t *my_hunter, duck_st_t *duck_st);
void some_event(my_hunter_t *my_hunter, duck_st_t *duck_st);
void cleanup(my_hunter_t *my_hunter);
void restart_game(my_hunter_t *my_hunter, duck_st_t *duck_st);
void initialize_menu(my_hunter_t *my_hunter);
void menu(my_hunter_t *my_hunter);
int is_button_clicked(sfSprite *button, sfEvent event);

#endif // MY_HUNTER_H
