/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** rotate.c
*/

#include "my.h"

int **dup_int_array(int max_size)
{
    int **arr = malloc(sizeof(int *) * max_size);

    for (int y = 0; y < max_size; y++)
        arr[y] = malloc(sizeof(int) * max_size);
    for (int y = 0; y < max_size; y++)
        for (int x = 0; x < max_size; x++)
            arr[y][x] = 0;
    return (arr);
}

vector2i get_pos(int **arr, vector2i size)
{
    int y;
    int x;
    vector2i pos = {size.x, size.y};

    for (y = 0; y < size.y; y++)
        for (x = 0; x < size.x; x++)
            pos = (vector2i){(arr[y][x] && x < pos.x) ? x : pos.x, pos.y};
    for (y = 0; y < size.y; y++)
        for (x = 0; x < size.x; x++)
            pos = (vector2i){pos.x, (arr[y][x] && y < pos.y) ? y : pos.y};
    return (pos);
}

void rotate_arr(int ***arr, int max_size)
{
    int tmp;

    for (int i = 0; i < max_size; ++i)
        for (int j = 0; j < i; ++j) {
            tmp = (*arr)[i][j];
            (*arr)[i][j] = (*arr)[j][i];
            (*arr)[j][i] = tmp;
        }
    for (int i = 0; i < max_size; ++i)
        for (int j = 0; j < max_size / 2; ++j) {
            tmp = (*arr)[i][j];
            (*arr)[i][j] = (*arr)[i][max_size - j - 1];
            (*arr)[i][max_size - j - 1] = tmp;
        }
}

void empty_array(int ***arr, vector2i size)
{
    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++)
            (*arr)[y][x] = 0;
}

int **rotate_tetr(int ***arr, vector2i size, vector2i t_size, int *rotation)
{
    int max_size = (size.x > size.y) ? size.x : size.y;
    int **new = dup_int_array(max_size);
    vector2i lpos = get_pos(*arr, size);
    vector2i pos;
    for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++)
            new[y][x] = (*arr)[y][x];
    rotate_arr(&new, max_size);
    t_size = (*rotation == 1) ? (vector2i){t_size.y, t_size.x} : (vector2i)
            {t_size.x, t_size.y};
    if (lpos.x + t_size.x >= size.x || lpos.y + t_size.y >= size.y)
        return (*arr);
    empty_array(arr, size);
    pos = get_pos(new, (vector2i){max_size, max_size});
    for (int y = lpos.y, yp = pos.y; y < lpos.y + t_size.x; y++, yp++)
        for (int x = lpos.x, xp = pos.x; x < lpos.x + t_size.y; x++, xp++)
            (*arr)[y][x] = new[yp][xp];
    *rotation = !(*rotation);
    return (new);
}
