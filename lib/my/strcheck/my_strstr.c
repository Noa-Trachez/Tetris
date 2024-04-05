/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** Searches for the first occurrence of the researched string
*/

#include "../include/lib/strcheck.h"

char *my_strstr(char *str, char const *to_find)
{
    int to_find_len = my_strlen(to_find);

    if (to_find[0] == '\0')
        return (str);
    for (int i = 0; str[i] != '\0'; i++)
        if (my_strncmp(&str[i], to_find, to_find_len) == 0)
            return (&str[i]);
    return (0);
}
