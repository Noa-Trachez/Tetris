/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** This function will display a int
*/

#include "../include/lib/output.h"

static int nb_length(int nb)
{
    int i = 0;

    for (; nb > 0; i++) {
        nb /= 10;
    }
    return (i);
}

static int division(int *divisibility, unsigned int *nbr)
{
    int nb_len;

    nb_len = nb_length(*nbr);
    for (int i = 0; i < nb_len - 1; i++) {
        *divisibility *= 10;
    }
}

static int exception(int *nb, int *neg)
{
    if (*nb < 0) {
        *nb *= -1;
        *neg = 1;
    }
    if (*nb == -2147483648) {
        my_putstr("-2147483648");
        *neg += 1;
        return (0);
    }
}

int my_put_nbr(int nb)
{
    unsigned int nbr;
    int divisibility = 1;
    int temp;
    int neg = 0;

    if (nb < 0)
        exception (&nb, &neg);
    if (neg == 2)
        return (0);
    nbr = nb;
    division (&divisibility, &nbr);
    if (neg == 1)
        my_putchar ('-');
    for (; divisibility > 0;) {
        temp = nbr / divisibility;
        nbr -= temp * divisibility;
        divisibility /= 10;
        my_putchar(temp + 48);
    }
}
