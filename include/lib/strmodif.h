/*
** EPITECH PROJECT, 2021
** INCLUDE/STRMODIF
** File description:
** Includes "strmodif" functions
*/

#ifndef STRMODIF_H
    #define STRMODIF_H
    #include <stddef.h>

int my_memset(void *dest, int val, size_t len);
int my_memcpy(void *dest, const void *src, size_t len);
char **my_revarr(char **arr);
char *my_revstr(char *str);
char **my_str_to_word_array(char const *str);
char *my_strappend(char *str, char *fill, int free_str);
char **my_strarr(char *str, char *delimiter);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strinsert(char *str, char c, int  n);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase(char *str);
char **dup_double_array(char **env);

#endif/*STRMODIF_H*/
