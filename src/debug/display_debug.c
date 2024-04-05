/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** display_debug.c
*/

#include "my.h"

void debug_key(tetris_t *tetris)
{
    char *name[6] = {"Key left: ", "Key right: ", "Key turn: ", "Key drop: ",
    "Key quit: ", "Key pause: "};
    int nbr_key[6] = {tetris->keys->keyLeft, tetris->keys->keyRight,
    tetris->keys->keyTurn, tetris->keys->keyDrop, tetris->keys->keyQuit,
    tetris->keys->keyPause};

    for (int i = 0; i < 6; i++) {
        my_putstr(name[i]);
        what_key_is_it(nbr_key[i]);
        my_putstr(" (");
        my_put_nbr(nbr_key[i]);
        my_putstr(")\n");
    }
}

void debug_info_game(tetris_t *tetris)
{
    tetriminos_t *save = tetris->tetriminos;
    int len;

    my_putstr("Next: ");
    my_putstr(tetris->hideNext ? "No\n" : "Yes\n");
    my_putstr("Level: ");
    my_put_nbr(tetris->level);
    my_putstr("\nSize: ");
    my_put_nbr(tetris->mapSize.x);
    my_putchar('*');
    my_put_nbr(tetris->mapSize.y);
    my_putstr("\n\n");
    for (len = 0; tetris->tetriminos; len++)
        tetris->tetriminos = tetris->tetriminos->next;
    tetris->tetriminos = save;
    my_putstr("Number of tetriminos: ");
    my_put_nbr(len);
    my_putchar('\n');
}

void debug_tetris(tetris_t *tetris)
{
    tetriminos_t *save = tetris->tetriminos;
    while (tetris->tetriminos) {
        my_putstr("Tetriminos '");
        compute_name_tetrimino(tetris->tetriminos->name);
        my_putstr("': ");
        if (tetris->tetriminos->error)
            my_putstr("error\n");
        else {
            my_putstr("size ");
            my_put_nbr(tetris->tetriminos->size.x);
            my_putchar('*');
            my_put_nbr(tetris->tetriminos->size.y);
            my_putstr(", color ");
            my_put_nbr(tetris->tetriminos->color);
            compute_forms(tetris->tetriminos->shape);
        }
        tetris->tetriminos = tetris->tetriminos->next;
    }
    tetris->tetriminos = save;
}

void display_debug(tetris_t *tetris)
{
    debug_key(tetris);
    debug_info_game(tetris);
    debug_tetris(tetris);
}
