/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** info_on_tetr.c
*/

#include "my.h"

void move_str_to_left(int index, char *shape)
{
    for (int j = index + 1; shape[j]; j++)
        shape[j] = shape[j + 1];
}

void clear_str(char *shape)
{
    int index = -1;
    int is_moving = 0;

    for (int i = 0; shape[i]; i++) {
        index = shape[i] == '*' ? i : index;
        if (shape[i] == '*')
            index = i;
        if (shape[i] == '\n' && index != -1 && shape[i - 1] != '*') {
            move_str_to_left(index, shape);
            is_moving = 1;
            break;
        }
    }
    if (is_moving)
        clear_str(shape);
}

void print_special_key(int key)
{
    char *str[32] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2",
    "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS",
    "RS", "US"};

    my_putstr(str[key]);
}

void what_key_is_it(int key)
{
    char *str[4] = {"KEY_DOWN", "KEY_UP", "KEY_LEFT", "KEY_RIGHT"};

    if (key >= 258 && key <= 261)
        my_putstr(str[key - 258]);
    else if (key <= 31)
        print_special_key(key);
    else
        my_putchar(key);
}
