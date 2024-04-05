/*
** EPITECH PROJECT, 2021
** MY_FACTORIAL
** File description:
** Computes factorial
*/

int my_factorial(int nb)
{
    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    if (nb > 12)
        return (0);
    return (nb * my_factorial(nb - 1));
}
