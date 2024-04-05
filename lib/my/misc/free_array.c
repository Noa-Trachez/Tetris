/*
** EPITECH PROJECT, 2021
** FREE_ARRAY
** File description:
** Free array
*/

#include <stdlib.h>

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
