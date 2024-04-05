/*
** EPITECH PROJECT, 2021
** new_mysh
** File description:
** dup_double_array.c
*/

#include "../include/lib/strmodif.h"
#include <unistd.h>
#include <stdlib.h>

char **dup_double_array(char **env)
{
    char **my_env;
    int len = 0;
    int i = 0;

    for (; env[len]; len++);
    my_env = malloc(sizeof(char *) * (len + 1));
    if (my_env == NULL) {
        write(2, "Impossible malloc\n", 19);
        exit(84);
    }
    for (i = 0; env[i]; i++)
        my_env[i] = my_strdup(env[i]);
    my_env[i] = NULL;
    return (my_env);
}
