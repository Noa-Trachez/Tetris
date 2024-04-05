/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

void colors(void)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}

void init_ncurses(void)
{
    srand((long)(&init_ncurses));
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    colors();
    curs_set(0);
}
