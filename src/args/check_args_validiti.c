/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** check_args_validiti.c
*/

#include "my.h"

void not_value(tetris_t **tetris, char *val)
{
    if (!val) {
        free((*tetris)->keys);
        free(*tetris);
        write(2, "Invalid arguments\n", 18);
        exit(84);
    }
    if (val[0] == '\0') {
        val = NULL;
        not_value(tetris, val);
    }
}

void check_string_number(tetris_t **tetris, char *val)
{
    for (int i = 0; val[i]; i++) {
        if (!my_char_isnum(val[i]) && val[i] != ',') {
            val = NULL;
            break;
        }
        if (val[i] == ',' && !val[i + 1]) {
            val = NULL;
            break;
        }
    }
    not_value(tetris, val);
}
