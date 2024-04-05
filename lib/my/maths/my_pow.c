/*
** EPITECH PROJECT, 2021
** MY_POW
** File description:
** Raises int nbr to the power p
*/

int my_pow(int nbr, int p)
{
    unsigned int result;
    int sign = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (nbr < 0) {
        nbr *= -1;
        if (p % 2 == 1)
            sign = -1;
    }
    result = nbr;
    result = (result * my_pow(nbr, p - 1));
    if (result > 2147483647)
        return (0);
    return (result * sign);
}
