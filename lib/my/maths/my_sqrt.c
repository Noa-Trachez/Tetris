/*
** EPITECH PROJECT, 2021
** MY_SQRT
** File description:
** Computes square root of int nbr
*/

int my_sqrt(int nbr)
{
    unsigned int result = 0;

    if (nbr < 0)
        return (0);
    while ((result * result != (unsigned)nbr) && (result < (unsigned)nbr)) {
        result++;
        if (result > 2147483647)
            return (0);
    }
    if (result == 1)
        return (1);
    else if (result != (unsigned)nbr)
        return (result);
    else
        return (0);
}
