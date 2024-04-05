/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** compute.c
*/

#include "my.h"

void help(char *name)
{
    my_putstr("Usage: ");
    my_putstr(name);
    my_putstr(" [options]\nOptions:\n");
    my_putstr("    --help               Display this help\n"
    "    -L --level={num}     Start Tetris at level num (def: 1)\n"
    "    -l --key-left={K}    Move the tetrimino LEFT using the K key "
    "(def: left arrow)\n    -r --key-right={K}   Move the tetrimino RIGHT"
    " using the K key (def: right arrow)\n    -t --key-turn={K}    TURN the "
    "tetrimino clockwise 90d using the K key (def: top arrow)\n"
    "    -d --key-drop={K}    DROP the tetrimino using the K key "
    "(def: down arrow)\n    -q --key-quit={K}    QUIT the game using the K "
    "key (def: `q' key)\n    -p --key-pause={K}   PAUSE/RESTART the game "
    "using the K key (def: space bar)\n"
    "    --map-size={row,col} Set the numbers of rows and columns of the "
    "map (def: 20,10)\n    -w --without-next    Hide next tetrimino "
    "(def: false)\n    -D --debug           Debug mode (def: false)\n");
}

void compute_name_tetrimino(char *name)
{
    int i = 0;
    int len;

    for (i = 0; name[i] != '/'; i++);
    i++;
    for (len = 0; name[len]; len++);
    for (; i < len - 10; i++)
        my_putchar(name[i]);
}

void compute_forms(char **shape)
{
    my_putchar('\n');
    for (int i = 0; shape[i]; i++) {
        my_putstr(shape[i]);
        if (shape[i + 1])
            my_putchar('\n');
    }
}
