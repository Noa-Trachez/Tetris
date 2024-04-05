/*
** EPITECH PROJECT, 2021
** MY_STR_ISLOWER
** File description:
** Returns 1 if the str contains only 'a'-'z'
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 97 && str[i] <= 122))
            return (0);
    }
    return (1);
}
