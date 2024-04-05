/*
** EPITECH PROJECT, 2021
** MY_CHAR_ISALPHA
** File description:
** Returns 1 if the char is 'A'-'MY_PRINTF_LENGTH_Z' or 'a'-'z'
*/

int my_char_isalpha(char c)
{
    if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
        return (0);
    return (1);
}
