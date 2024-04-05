/*
** EPITECH PROJECT, 2021
** MY_REVARR
** File description:
** Reverses the content of the array
*/

char **my_revarr(char **arr)
{
    int len = 0;
    char *tmp_str;

    for (; arr[len]; len++);
    for (int i = 0; i < len / 2; i++) {
        tmp_str = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = tmp_str;
    }
    return (arr);
}
