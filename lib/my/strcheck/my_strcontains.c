/*
** EPITECH PROJECT, 2021
** MY_STRCONTAINS
** File description:
** Checks if the string contains at least one character(c)
*/

int my_strcontains(char const *str, char c)
{
    int counter = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            counter++;
    return (counter);
}
