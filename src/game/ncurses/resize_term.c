/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** resize_term.c
*/

#include "tetris/tetris.h"
#include <ncurses.h>

int check_terminal(tetris_t *tetris)
{
    getmaxyx(stdscr, tetris->size_term[1], tetris->size_term[0]);
    if (tetris->size_term[0] < tetris->mapSize.x + 42)
        return (0);
    if (tetris->size_term[1] < tetris->mapSize.y + 8)
        return (0);
    return (1);
}

void my_get_inputs(tetris_t *tetris)
{
    int key;
    keys_t *keys = tetris->keys;

    timeout(10);
    key = getch();
    if (key == keys->keyQuit)
        set_global(&g_ingame, 0);
}

void error_term(tetris_t *tetris)
{
    while (!check_terminal(tetris) && get_global(&g_ingame)) {
        mvprintw(tetris->size_term[1] / 2,
        tetris->size_term[0] / 2, "Too small\n");
        my_get_inputs(tetris);
        refresh();
        clear();
    }
}
