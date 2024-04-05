/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Returns number of characters
*/

int my_strlen(char const *str)
{
    int len;

    for (len = 0; str[len]; len++);
    return (len);
}
