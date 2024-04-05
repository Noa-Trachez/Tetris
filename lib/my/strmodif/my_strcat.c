/*
** EPITECH PROJECT, 2021
** MY_STRCAT
** File description:
** Concatenates a string(dest) to another (src)
*/

#include "../include/lib/strcheck.h"
#include "../include/lib/strmodif.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return (dest);
}
