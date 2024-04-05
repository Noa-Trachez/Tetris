/*
** EPITECH PROJECT, 2021
** MY_STRINSERT
** File description:
** Inserts a character(c) after the n-th character of the string
*/

#include <stdlib.h>
#include "../include/lib/strcheck.h"
#include "../include/lib/strmodif.h"

char *my_strinsert(char *str, char c, int  n)
{
    int len = my_strlen(str);
    char *new = malloc(len + 2);

    my_memset(new, 0, len + 2);
    my_strncpy(new, str, n);
    new[n] = c;
    my_strcat(new, str + n);
    return (new);
}
