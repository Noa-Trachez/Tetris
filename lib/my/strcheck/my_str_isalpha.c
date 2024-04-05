/*
** EPITECH PROJECT, 2021
** MY_STR_ISALPHA
** File description:
** Returns 1 if the str contains only 'A'-'MY_PRINTF_LENGTH_Z' or 'a'-'z'
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122)))
            return (0);
    }
    return (1);
}
