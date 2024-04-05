/*
** EPITECH PROJECT, 2021
** MY_SWAP
** File description:
** Swaps int a with int b
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
