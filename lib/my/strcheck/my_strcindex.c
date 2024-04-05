/*
** EPITECH PROJECT, 2021
** MY_STRCINDEX
** File description:
** Returns index in the string of the researched character
** or -1 if nothing was found
*/

int my_strcindex(char const *str, char c)
{
    int index = -1;

    for (int i = 0; str[i]; i++)
        if (str[i] == c) {
            index = i;
            break;
        }
    return (index);
}
