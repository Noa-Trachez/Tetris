/*
** EPITECH PROJECT, 2021
** MY_STR_ISUPPER
** File description:
** Returns 1 if the str contains only 'A'-'MY_PRINTF_LENGTH_Z'
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 65 && str[i] <= 90))
            return (0);
    }
    return (1);
}
