/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

#include "my.h"

tetriminos_t *tetriminos_set_shape(tetriminos_t *tetriminos, va_list list)
{
    char *shape = va_arg(list, char *);
    int counter = 1;

    while (*shape != '\n') {
        shape++;
        counter++;
    }
    shape++;
    clear_str(shape);
    tetriminos->shape = my_strarr(shape, "\n");
    while (counter) {
        shape--;
        counter--;
    }
    return (tetriminos);
}

tetriminos_t *tetriminos_set_name(tetriminos_t *tetriminos, va_list list)
{
    char *name = va_arg(list, char *);

    tetriminos->name = name;
    return (tetriminos);
}

tetriminos_t *tetriminos_set_size(tetriminos_t *tetriminos, va_list list)
{
    vector2i size = va_arg(list, vector2i);

    tetriminos->size = size;
    return (tetriminos);
}

tetriminos_t *tetriminos_set_color(tetriminos_t *tetriminos, va_list list)
{
    int color = va_arg(list, int);

    tetriminos->color = color;
    return (tetriminos);
}

tetriminos_t *tetriminos_set_error(tetriminos_t *tetriminos, va_list list)
{
    int error = va_arg(list, int);

    tetriminos->error = error;
    return (tetriminos);
}
