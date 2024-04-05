/*
** EPITECH PROJECT, 2021
** MY_STRNCAT
** File description:
** Concatenates a string(dest) to another (src) for n frist characters
*/

#include "../include/lib/strcheck.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; src[i] && i < n; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}
