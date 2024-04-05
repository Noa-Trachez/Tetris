/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

void print_borders(vector2i mapsize, vector2i pos)
{
    mvaddch(pos.y, pos.x, '+');
    mvhline(pos.y, pos.x + 1, '-', mapsize.x);
    mvaddch(pos.y, pos.x + 1 + mapsize.x, '+');
    mvaddch(pos.y + mapsize.y + 1, pos.x, '+');
    mvhline(pos.y + mapsize.y + 1, pos.x + 1, '-', mapsize.x);
    mvaddch(pos.y + mapsize.y + 1, pos.x + 1 + mapsize.x, '+');
    mvvline(pos.y + 1, pos.x, '|', mapsize.y);
    mvvline(pos.y + 1, pos.x + 1 + mapsize.x, '|', mapsize.y);
}

void print_game(int **arr, vector2i size)
{
    static int x_offset = 39;
    static int y_offset = 5;

    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++) {
            attron(COLOR_PAIR(arr[y][x]));
            mvprintw(y + y_offset, x + x_offset, (arr[y][x]) ? "#" : " ");
        }
}

void print_tetriminos(int **arr, vector2i size)
{
    static int x_offset = 39;
    static int y_offset = 5;

    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++) {
            attron(COLOR_PAIR(arr[y][x]));
            (arr[y][x]) ? mvprintw(y + y_offset, x + x_offset, "#") : 0;
        }
}

void print_timer(clock_t start)
{
    clock_t diff = clock() - start;
    int hour = diff / 40000 % 216000 / 3600;
    int minutes = diff / 40000 % 3600 / 60;
    int seconds = diff / 40000 % 60;

    mvprintw(18, 5, "TIME : %.2d:%.2d:%.2d", hour, minutes, seconds);
}

void print_hud(void)
{
    int x = 0;
    int y = 0;

    attron(COLOR_PAIR(2));
    mvprintw(y++, x, "  _____  ___  _____  ___  ___  ___ ");
    attron(COLOR_PAIR(3));
    mvprintw(y++, x, " |_   _|| __||_   _|| _ \\|_ _|/ __|");
    attron(COLOR_PAIR(4));
    mvprintw(y++, x, "   | |  | _|   | |  |   / | | \\__ \\");
    attron(COLOR_PAIR(5));
    mvprintw(y++, x, "   |_|  |___|  |_|  |_|_\\|___||___/");
    attron(COLOR_PAIR(1));
}
