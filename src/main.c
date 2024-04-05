/*
** EPITECH PROJECT, 2021
** TETRIS
** File description:
** todo: Description
*/

#include "my.h"

void free_a_tetris(tetriminos_t *save)
{
    free_array(save->shape);
    free(save->name);
    free(save);
}

void destroy_tetris(tetriminos_t **tetriminos)
{
    tetriminos_t *head = *tetriminos;
    tetriminos_t *save;

    if (head && head->error) {
        save = head;
        head = save->next;
        *tetriminos = head;
        free_a_tetris(save);
    }
    while (head) {
        if (head->next && head->next->error) {
            save = head->next;
            head->next = save->next;
            free_a_tetris(save);
        }
        head = head->next;
    }
}

int number_of_tetriminos(tetriminos_t **tetriminos)
{
    tetriminos_t *save = *tetriminos;
    int len;

    for (len = 0; *tetriminos; len++)
        *tetriminos = (*tetriminos)->next;
    *tetriminos = save;
    return (len);
}

void free_all_tetr_struct(tetris_t *tetris)
{
    tetriminos_t *save = tetris->tetriminos;
    tetriminos_t *tmp;

    while (save) {
        tmp = save;
        save = save->next;
        if (!tmp->error)
            free_array(tmp->shape);
        free(tmp->name);
        free(tmp);
        tmp = NULL;
    }
    free(tetris->keys);
    free(tetris);
}

int main(int ac, char **av)
{
    tetris_t *tetris = check_argsr(ac, av);

    if (tetris)
        add_tetriminos(tetris);
    if (!tetris)
        return (84);
    if (tetris->help)
        help(av[0]);
    if (tetris->debug && !tetris->help)
        display_debug(tetris);
    destroy_tetris(&tetris->tetriminos);
    if (!number_of_tetriminos(&tetris->tetriminos))
        return (84);
    if (!tetris->debug && !tetris->help)
        ncurse(tetris);
    free_all_tetr_struct(tetris);
    return (0);
}
