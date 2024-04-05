/*
** EPITECH PROJECT, 2021
** MY_STRAPPEND
** File description:
** Appends a string(fill) to another string(str)
*/

#include <stdlib.h>
#include "../include/lib/strmodif.h"
#include "../include/lib/strcheck.h"

char *my_strappend(char *str, char *fill, int free_str)
{
    int len = my_strlen(str) + my_strlen(fill);
    char *new = malloc(len + 1);

    my_memset(new, 0, len + 1);
    my_strcpy(new, str);
    my_strcat(new, fill);
    if (free_str)
        free(str);
    return (new);
}
