/*
** EPITECH PROJECT, 2021
** MY_CHAR_ISPRINTABLE
** File description:
** Returns 1 if the char is printable
*/

int my_char_isprintable(char c)
{
    if (!(c >= 32 && c <= 126))
        return (0);
    return (1);
}
