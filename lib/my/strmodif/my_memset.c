/*
** EPITECH PROJECT, 2021
** MY_MEMSET
** File description:
** Copies the char c to the first n characters of the string
*/

#include <stddef.h>

int my_memset(void *dest, int val, size_t len)
{
    unsigned char *ptr = dest;

    for (int i = 0; i < len; i++) {
        *ptr = val;
        *ptr++;
    }
    return 0;
}

int my_memcpy(void *dest, const void *src, size_t len)
{
    char *d = dest;
    const char *s = src;

    for (int i = 0; i < len; i++) {
        *d = *s;
        *d++;
        *s++;
    }
    return 0;
}
