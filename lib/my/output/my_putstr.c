/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** Displays a string.
*/

#include "../include/lib/output.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
