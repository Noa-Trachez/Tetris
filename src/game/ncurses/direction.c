/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

int move_left(int ***new, int x, vector2i size)
{
    int err = 0;

    for (int y = 0; y < size.y; y++) {
        if (!x && (*new)[y][x])
            err++;
        if (err)
            return (1);
        if (x > 0 && !(*new)[y][x - 1] && (*new)[y][x]) {
            (*new)[y][x - 1] = (*new)[y][x];
            (*new)[y][x] = 0;
        }
    }
    return (0);
}

void go_left(int ***new, int ***game, vector2i size)
{
    int err = 0;

    for (int x = 1; x < size.x; x++)
        for (int y = 0; y < size.y; y++) {
            err += ((*new)[y][x] && (*game)[y][x - 1]) ? 1 : 0;
            (*new)[y][x] = (*new)[y][x];
            (*game)[y][x - 1] = (*game)[y][x - 1];
        }
    for (int x = 0; x < size.x; x++) {
        if (err)
            return;
        err = move_left(new, x, size);
    }
}

int move_right(int ***new, int x, vector2i size)
{
    int err = 0;

    for (int y = 0; y < size.y; y++) {
        if (x == size.x - 1 && (*new)[y][x])
            err++;
        if (err)
            return (1);
        if (x < size.x - 1 && !(*new)[y][x + 1] && (*new)[y][x]) {
            (*new)[y][x + 1] = (*new)[y][x];
            (*new)[y][x] = 0;
        }
    }
    return (0);
}

void go_right(int ***new, int ***game, vector2i size)
{
    int err = 0;

    for (int x = size.x - 2; x >= 0; x--)
        for (int y = 0; y < size.y; y++)
            err += ((*new)[y][x] && (*game)[y][x + 1]) ? 1 : 0;
    for (int x = size.x - 1; x >= 0; x--) {
        if (err)
            return;
        err = move_right(new, x, size);
    }
}
