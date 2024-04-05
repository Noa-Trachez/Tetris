/*
** EPITECH PROJECT, 2021
** MY_STRARR
** File description:
** Stores words delimited by specific character(delimiter) from a string(str)
** into an array.
*/

#include <stdlib.h>
#include "../include/lib/strmodif.h"

static int get_word_length(const char *str, const char *delimiter,
int characters)
{
    int index = 0;

    for (characters = 0; str[index]; index++) {
        if (str[index] == delimiter[0])
            return (characters);
        else
            characters++;
    }
    return (characters);
}

char **my_strarr(char *str, char *delimiter)
{
    char **array;
    char *ptr;
    int words = 0;
    int characters = 0;

    str = my_strappend(str, delimiter, 0);
    ptr = str;
    for (int i = 0; str[i]; i++)
        if (str[i] == delimiter[0])
            words++;
    array = malloc(sizeof(char *) * (words + 1));
    for (int i = 0; i < words; i++) {
        characters = get_word_length(str, delimiter, characters);
        array[i] = malloc(characters + 1);
        my_strncpy(array[i], str, characters);
        str += characters + 1;
    }
    array[words] = NULL;
    free(ptr);
    return (array);
}
