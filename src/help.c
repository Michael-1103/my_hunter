/*
** EPITECH PROJECT, 2024
** B-MUL-100-MLN-1-1-myhunter-michael.derrien
** File description:
** help
*/

#include "my_hunter.h"

void help(void)
{
    write(1, "My Hunter is a game where you have to kill ducks.\n", 51);
    write(1, "You have to reach 5000 points to win.\n", 38);
    write(1, "You can pause the music by pressing M.\n", 40);
    write(1, "You can kill a duck by clicking on it.\n", 39);
    write(1, "You can restart the game by pressing space once", 47);
    write(1, " you win.\n", 10);
    write(1, "You can exit the game by pressing escape.\n", 43);
    write(1, "You can add points by pressing P + O(debug only).\n", 48);
}
