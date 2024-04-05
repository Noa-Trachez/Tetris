/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** check_files.c
*/

#include "my.h"

char *check_contain_only(char *map)
{
    int i = 0;

    for (i = 0; map[i] && map[i] != '\n'; i++);
    for (; map[i]; i++)
        if (map[i] != '*' && map[i] != ' ' && map[i] != '\n') {
            free(map);
            map = NULL;
            break;
        }
    return (map);
}

char *load_files(char *file)
{
    struct stat sb;
    char *map;
    int size = 0;
    int fd = open(file, O_RDONLY);

    if (stat(file, &sb) | !fd | !sb.st_size)
        return (NULL);
    size = sb.st_size;
    map = malloc(sizeof(char) * size + 1);
    if (!map)
        return (NULL);
    if (read(fd, map, sb.st_size) != sb.st_size)
        return (NULL);
    map[size] = '\0';
    if (map[size - 1] != '\n')
        map = my_strappend(map, "\n", 1);
    close(fd);
    return (check_contain_only(map));
}

int end_by_tetrimino(char *name)
{
    int last_index;
    char tetr[10] = ".tetrimino";
    int index = 9;

    for (last_index = 0; name[last_index]; last_index++);
    if (last_index <= 10)
        return (0);
    last_index -= 1;
    for (; last_index >= 10; last_index--) {
        if (index > 0 && name[last_index] != tetr[index])
            return (0);
        index--;
    }
    return (1);
}
