/*
** EPITECH PROJECT, 2021
** MY_STR_ISNUM
** File description:
** Returns 1 if the str contains only '0'-'9'
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 48 && str[i] <= 57))
            return (0);
    }
    return (1);
}
