/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** set_args.c
*/

#include "my.h"

void set_default_keys(tetris_t **tetris)
{
    (*tetris)->keys->keyLeft = 260;
    (*tetris)->keys->keyRight = 261;
    (*tetris)->keys->keyTurn = 259;
    (*tetris)->keys->keyDrop = 258;
    (*tetris)->keys->keyQuit = 113;
    (*tetris)->keys->keyPause = 32;
    (*tetris)->level = 1;
    (*tetris)->mapSize = (vector2i){20, 10};
    (*tetris)->hideNext = 0;
    (*tetris)->help = 0;
    (*tetris)->debug = 0;
}

int convert_key(char *value, tetris_t **tetris)
{
    if (!my_str_isnum(value)) {
        free(*tetris);
        write(2, "Invalid arguments\n", 18);
        exit(84);
    }
    return (my_getnbr(value));
}

void set_key(int index, tetris_t **tetris, char *value)
{
    int val = convert_key(value, tetris);
    int index_ptr = (index - 2) * sizeof(int);

    my_memcpy((char *)((*tetris)->keys) + index_ptr, &val, sizeof(int));
}

void set_map_size(tetris_t **tetris, char *val)
{
    int is_colomn = 0;

    for (int i = 0; val[i]; i++)
        if (val[i] == ',')
            is_colomn += 1;
    if (is_colomn != 1) {
        val = NULL;
        not_value(tetris, val);
    }
    check_string_number(tetris, val);
    (*tetris)->mapSize.x = my_getnbr(val);
    while (*val != ',')
        val++;
    val++;
    (*tetris)->mapSize.y = my_getnbr(val);
}

void set_value(char *val, int index, tetris_t **tetris)
{
    if (index == 0)
        (*tetris)->help = 1;
    if (index >= 1 && index <= 8) {
        not_value(tetris, val);
        if (index >= 2 && index <= 7)
            set_key(index, tetris, val);
        else if (index == 1)
            (*tetris)->level = convert_key(val, tetris);
        else
            set_map_size(tetris, val);
    }
    if (index == 9)
        (*tetris)->hideNext = 1;
    if (index == 10)
        (*tetris)->debug = 1;
}
