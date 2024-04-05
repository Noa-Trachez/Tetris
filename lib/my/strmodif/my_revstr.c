/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** Reverses a string
*/

#include "../include/lib/strcheck.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int tmp_len = len - 1;
    char tmp;

    for (int i = 0; i < (len / 2); i++, tmp_len--) {
        tmp = str[i];
        str[i] = str[tmp_len];
        str[tmp_len] = tmp;
    }
    str[len] = '\0';
    return (str);
}
