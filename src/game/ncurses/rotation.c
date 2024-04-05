/*
** EPITECH PROJECT, 2021
** TETRIS
** File description:
** todo: Description
*/

#include "tetris/tetris.h"

void rotation(int ***tetr, vector2i size, vector2i t_size, tetris_t *tetris)
{
    rotate_tetr(tetr, size, t_size, &tetris->rotation);
}
