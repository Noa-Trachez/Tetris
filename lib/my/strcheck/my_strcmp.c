/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** Returns deference between two ascii value of the first different character
** between both strings
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;
    for (;str1[i] == str2[i] && str1[i] != '\0'; i++)
        ;
    return (str1[i] - str2[i]);
}
