/*
** EPITECH PROJECT, 2021
** MY_STRDUP
** File description:
** Allocates memory needed to copy a string
*/

#include <stdlib.h>
#include "../include/lib/strcheck.h"
#include "../include/lib/strmodif.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(len + 1);

    my_memset(str, 0, len + 1);
    my_strcpy(str, src);
    return (str);
}
