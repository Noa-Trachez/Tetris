/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

int respawn_tetriminos(int ***new, vector2i size)
{
    int filled = 0;

    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++)
            filled += ((*new)[y][x]) ? 1 : 0;
    if (!filled)
        return (1);
    return (0);
}

int copy_tetriminos(int ***new, char **shape, vector2i *sizes, int color)
{
    vector2i size = sizes[0];
    vector2i t_size = sizes[1];

    attron(COLOR_PAIR(color));
    if (size.x < t_size.x || size.y < t_size.y)
        return (1);
    for (int x = 0; x < t_size.x; x++)
        if (x + size.x / 2 >= size.x)
            return (1);
    for (int y = 0; y < t_size.y && shape[y]; y++)
        for (int x = 0; x < t_size.x && shape[y][x]; x++)
            (*new)[y][x + size.x / 2] = (shape[y][x] == '*') ? color : 0;
    return (0);
}

int check_spawn(int ***game, vector2i size, vector2i t_size)
{
    int err = 0;
    int offset = size.x / 2;

    for (int x = 0; x < t_size.x; x++)
        if (x + size.x / 2 >= size.x)
            offset = 0;
    for (int y = 0; y < t_size.y; y++)
        for (int x = 0; x < t_size.x; x++)
            err += ((*game)[y][x + offset]) ? 1 : 0;
    if (err)
        return (1);
    return (0);
}

int create_next(tetris_t *tetris, int len)
{
    tetriminos_t *head = tetris->tetriminos;
    int tmp = tetris->nextTetriminos;

    tetris->nextTetriminos = (len > 1) ? rand() % (len - 1) : 0;
    if (!tetris->hideNext) {
        for (int count = 0; head && count != tetris->nextTetriminos; count++)
            head = head->next;
        next_tetriminos(head->shape);
        head = tetris->tetriminos;
    }
    return ((tmp == -1) ? 0 : tmp);
}

vector2i spawn_tetriminos(tetris_t *tetris, int ***new, int ***game)
{
    tetriminos_t *head = tetris->tetriminos;
    vector2i sizes[2];
    int len = 0;
    int i;

    for (; head; len++, head = head->next);
    head = tetris->tetriminos;
    i = create_next(tetris, len);
    for (int count = 0; head && count != i; count++)
        head = head->next;
    if (check_spawn(game, tetris->mapSize, head->size)) {
        set_global(&g_ingame, 0);
        return ((vector2i){0, 0});
    }
    sizes[0] = tetris->mapSize;
    sizes[1] = head->size;
    copy_tetriminos(new, head->shape, sizes, head->color);
    tetris->rotation = 0;
    return (head->size);
}
