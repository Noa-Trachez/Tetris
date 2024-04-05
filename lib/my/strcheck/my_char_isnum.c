/*
** EPITECH PROJECT, 2021
** MY_CHAR_ISNUM
** File description:
** Returns 1 if the char is '0'-'9'
*/

int my_char_isnum(char c)
{
    if (!(c >= 48 && c <= 57))
        return (0);
    return (1);
}
