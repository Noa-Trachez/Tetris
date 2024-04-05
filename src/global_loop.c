/*
** EPITECH PROJECT, 2022
** TETRIS
** File description:
** TODO: description
*/

int g_ingame(int value, int mod)
{
    static int ingame = 1;

    if (mod)
        ingame = value;
    return (ingame);
}
