/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** check_tetriminos.c
*/

#include "my.h"

tetris_t *invalid_args(char **number)
{
    free_array(number);
    return (NULL);
}

tetris_t *take_width_height_color_code(int *info, char **number,
tetris_t *tetris)
{
    int len;

    for (len = 0; number[len]; len++)
        if (my_strlen(number[len]) <= 0)
            return (NULL);
    if (len != 3)
        return (invalid_args(number));
    for (int i = 0; i < 3; i++) {
        if (!my_str_isnum(number[i]))
            return (invalid_args(number));
        info[i] = my_getnbr(number[i]);
    }
    if ((info[0] <= 0) | (info[2] < 0 || info[2] >= 9) | (info[1] <= 0))
        return (invalid_args(number));
    free_array(number);
    return (tetris);
}

void add_tetriminos(tetris_t *tetris)
{
    DIR *rep = opendir("tetriminos");
    tetris->tetriminos = NULL;
    struct dirent *ent;

    while (rep != NULL && (ent = readdir(rep)) != NULL)
        if (end_by_tetrimino(ent->d_name))
            check_tetriminos(tetris,
            my_strappend("tetriminos/", ent->d_name, 0));
    closedir(rep);
}
