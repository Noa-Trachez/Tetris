/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

void collide(int ***new, int ***game, vector2i size)
{
    int collide = 0;

    for (int y = 0; y < size.y && !collide; y++)
        for (int x = 0; x < size.x && !collide; x++)
            collide = ((*new)[y][x] && y == size.y - 1) ? 1 : 0;
    for (int y = 0; y < size.y - 1 && !collide; y++)
        for (int x = 0; x < size.x && !collide; x++)
            collide = ((*new)[y][x] && (*game)[y + 1][x]) ? 1 : 0;
    if (!collide)
        return;
    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++) {
            (*new)[y][x] ? ((*game)[y][x] = (*new)[y][x]) : 0;
            (*new)[y][x] = 0;
        }
}

void down_char(int ***new, int y, vector2i size)
{
    for (int x = 0; x < size.x; x++)
        if (y < size.y - 1 && !(*new)[y + 1][x] &&
        (*new)[y][x]) {
            (*new)[y + 1][x] = (*new)[y][x];
            (*new)[y][x] = 0;
        }
}

void fall(int ***new, int ***game, vector2i size)
{
    collide(new, game, size);
    for (int y = size.y - 1; y >= 0; y--)
        down_char(new, y, size);
}

void physic(int ***game, int ***new, vector2i size, int *score)
{
    static float elapsed_time = 0;

    elapsed_time = elapsed_time + *score;
    collide(new, game, size);
    destroy_row(game, size, score);
    if (elapsed_time < 120)
        return;
    fall(new, game, size);
    elapsed_time = 0;
}
