/*
** EPITECH PROJECT, 2021
** MY_SHOW_WORD_ARRAY
** File description:
** Display array's content
*/

#include "../include/lib/output.h"

void my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
