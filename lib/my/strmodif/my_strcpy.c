/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** Copies a string(src) into another(dest) and overwrite the destination one
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    return (dest);
}
