/*
** EPITECH PROJECT, 2021
** MY_STR_ISPRINTABLE
** File description:
** Returns 1 if the str is printable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 32 && str[i] <= 126))
            return (0);
    }
    return (1);
}
