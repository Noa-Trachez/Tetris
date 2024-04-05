/*
** EPITECH PROJECT, 2021
** MY_STRNCPY
** File description:
** Copies a string(src) into another(dest) for the n first characters
** and overwrite the destination one if n > to the length of src string
*/

#include "../include/lib/strcheck.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    if (i >= n)
        dest[i] = '\0';
    dest[i] = '\0';
    return (dest);
}
