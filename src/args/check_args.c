/*
** EPITECH PROJECT, 2021
** B-PSU-200-LIL-2-1-tetris-clement.vandeville
** File description:
** check_args.c
*/

#include "my.h"

int search_option_index(int c)
{
    char arg[11] = " Llrtdqp wD";

    for (int i = 0; i < 11; i++) {
        if (c == arg[i])
            return (i);
    }
    write(2, "Invalid arguments\n", 18);
    exit (84);
}

void check_this(int argc, char **argv, tetris_t **tetris)
{
    int option_index = 0;
    int c = 0;

    while (1) {
        c = getopt_long (argc, argv, ":L:l:r:t:d:q:p:wD", long_options,
        &option_index);
        if (c == -1)
            break;
        if (c == 0)
            set_value(optarg, option_index, tetris);
        else if (c == ':') {
            write(2, "missing arg\n", 12);
            exit(84);
        } else
            set_value(optarg, search_option_index(c), tetris);
    }
}

tetris_t *check_if_only_args(char **av, tetris_t *tetris)
{
    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-' && av[i - 1][0] != '-')
            return NULL;
        if (av[i][0] != '-' && av[i - 1][0] == '-' && av[i - 1][1] == 'D')
            return (NULL);
        if (av[i][0] != '-' && av[i - 1][0] == '-' && av[i - 1][1] == 'w')
            return (NULL);
    }
    return (tetris);
}

tetris_t *check_argsr(int argc, char **argv)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    tetris = check_if_only_args(argv, tetris);
    if (!tetris)
        return (tetris);
    tetris->keys = malloc(sizeof(keys_t));
    set_default_keys(&tetris);
    check_this(argc, argv, &tetris);
    tetris->nextTetriminos = -1;
    tetris->rotation = 0;
    return (tetris);
}
