/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

static tetriminos_t *get_tetriminos_parameter(tetriminos_t *tetriminos, char
parameter, va_list list)
{
    static const char *parameters = "snzlr";

    tetriminos_t *(*setter[])() = {&tetriminos_set_shape,
    &tetriminos_set_name, &tetriminos_set_size, &tetriminos_set_color,
    &tetriminos_set_error};
    int parameter_i = -1;

    for (int i = 0; parameters[i]; i++)
        if (parameters[i] == parameter) {
            parameter_i = i;
            break;
        }
    setter[parameter_i](tetriminos, list);
    return (tetriminos);
}

static tetriminos_t *init_tetriminos_values(void)
{
    tetriminos_t *tetriminos;

    tetriminos = malloc(sizeof(tetriminos_t));
    *tetriminos = (tetriminos_t){NULL, "default",
    (vector2i){0, 0}, 0, 1, NULL};
    return (tetriminos);
}

static tetriminos_t **new_tetriminos(tetriminos_t **tetriminos, char
*parameters, va_list list)
{
    tetriminos_t *head = *tetriminos;
    tetriminos_t *current = NULL;

    if (*tetriminos) {
        while ((*tetriminos)->next != NULL)
            *tetriminos = (*tetriminos)->next;
        (*tetriminos)->next = init_tetriminos_values();
        current = (*tetriminos)->next;
        *tetriminos = head;
    } else {
        *tetriminos = init_tetriminos_values();
        current = *tetriminos;
    }
    for (int i = 0; parameters[i]; i++)
        get_tetriminos_parameter(current, parameters[i], list);
    return (tetriminos);
}

void build_tetriminos(tetriminos_t **tetriminos, char *parameters, ...)
{
    va_list list;

    va_start(list, parameters);
    tetriminos = new_tetriminos(tetriminos, parameters, list);
    va_end(list);
}
