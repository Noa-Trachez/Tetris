/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** check_shape.c
*/

#include "my.h"

char **invalid_tetrimino(char **map, tetris_t *tetris, char *file)
{
    free_array(map);
    build_tetriminos(&tetris->tetriminos, "nr", file, 1);
    return (NULL);
}

char **continue_check_tetriminos(char *tetrimino, tetris_t *tetris,
char *file, int *info)
{
    char **map = NULL;
    tetris_t *tmp;

    clear_str(tetrimino);
    map = my_strarr(tetrimino, "\n");
    if (!map) {
        build_tetriminos(&tetris->tetriminos, "nr", file, 1);
        return (NULL);
    }
    tmp = take_width_height_color_code(info, my_strarr(map[0], " "), tetris);
    if (!tmp)
        return (invalid_tetrimino(map, tetris, file));
    tmp = check_form(map, info[0], info[1] , tetris);
    if (!tmp)
        return (invalid_tetrimino(map, tetris, file));
    return (map);
}

tetris_t *check_tetriminos(tetris_t *tetris, char *file)
{
    char *tetrimino = load_files(file);
    char **map = NULL;
    int info[3] = {0, 0, 0};

    if (!tetrimino) {
        build_tetriminos(&tetris->tetriminos, "nr", file, 1);
        return (NULL);
    }
    map = continue_check_tetriminos(tetrimino, tetris, file, info);
    if (!map) {
        free(tetrimino);
        return (NULL);
    }
    build_tetriminos(&tetris->tetriminos, "snzlr", tetrimino, file,
    (vector2i){info[0], info[1]}, info[2], 0);
    free_array(map);
    free(tetrimino);
    return (tetris);
}

tetris_t *check_form(char **map, int width, int height, tetris_t *tetris)
{
    int len;

    for (len = 1; map[len]; len++);
    if (len - 2 != height)
        return (NULL);
    for (int i = 1; map[i + 1]; i++)
        if (my_strlen(map[i]) > width)
            return (NULL);
    return (tetris);
}
