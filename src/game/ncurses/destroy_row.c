/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

int g_destroyed_row(int nb, int mod)
{
    static int destroyed = 0;

    if (mod)
        destroyed = nb;
    return (destroyed);
}

void fall_above(int ***game, int y, vector2i size, int *score)
{
    static int destroyed = 0;

    for (; y >= 0; y--)
        for (int x = 0; x < size.x; x++) {
            ((*game)[y][x]) ? ((*game)[y + 1][x] = (*game)[y][x]) : 0;
            ((*game)[y][x]) ? ((*game)[y][x] = 0) : 0;
        }
    destroyed++;
    set_global(&g_destroyed_row, get_global(&g_destroyed_row) + 1);
    if (destroyed == 10) {
        *score += 1;
        destroyed = 0;
    }
}

void destroy_row(int ***game, vector2i size, int *score)
{
    int full;

    for (int y = size.y - 1; y >= 0; y--) {
        full = 0;
        for (int x = 0; x < size.x; x++)
            full += (*game)[y][x] ? 1 : 0;
        if (full != size.x)
            continue;
        for (int x = 0; x < size.x; x++)
            (*game)[y][x] = 0;
        fall_above(game, y, size, score);
    }
}
