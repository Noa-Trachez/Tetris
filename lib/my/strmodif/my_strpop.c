/*
** EPITECH PROJECT, 2021
** MY_STRPOP
** File description:
** Pops off the n-th first characters of a string
*/

#include "../include/lib/strmodif.h"
#include "../include/lib/strcheck.h"
#include <stdlib.h>

char *my_strpop(char *str, int index, int free_str)
{
    int len = my_strlen(str) - index + 1;
    char *new = malloc(len);

    my_memset(new, 0, len);
    my_strcpy(new, str + index);
    if (free_str)
        free(str);
    return (new);
}
