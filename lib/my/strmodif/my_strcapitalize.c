/*
** EPITECH PROJECT, 2021
** MY_STRCAPITALISE
** File description:
** Capitalizes every first letter of a word in the whole str
*/

#include "../include/lib/strmodif.h"

static char capitalize(char *str, int i)
{
    if (i == 0)
        str[i] -= 32;
    else if (str[i - 1] == 32 || str[i - 1] == 43 || str[i - 1] == 45)
        str[i] -= 32;
    return (str[i]);
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 91 && str[i] <= 122) {
            capitalize(str, i);
        }
    }
    return (str);
}
