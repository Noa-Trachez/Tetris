/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

#include "tetris/tetris.h"

void get_inputs(tetris_t *tetris, int ***new, int ***game, vector2i size[2])
{
    int key;
    keys_t *keys = tetris->keys;

    timeout(10);
    key = getch();
    if (key == keys->keyQuit)
        set_global(&g_ingame, 0);
    if (key == keys->keyLeft)
        go_left(new, game, size[0]);
    if (key == keys->keyRight)
        go_right(new, game, size[0]);
    if (key == keys->keyDrop)
        fall(new, game, size[0]);
    if (key == keys->keyTurn)
        rotation(new, size[0], size[1], tetris);
}
