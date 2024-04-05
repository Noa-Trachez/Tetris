/*
** EPITECH PROJECT, 2021
** INCLUDE/STRCHECK
** File description:
** Includes "strcheck" functions
*/

#ifndef STRCHECK_H
    #define STRCHECK_H

int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_strlen(char const *str);
int my_strncmp(char const *str1, char const *str2, int n);
char *my_strstr(char *str, char const *to_find);

#endif/*STRCHECK_H*/
