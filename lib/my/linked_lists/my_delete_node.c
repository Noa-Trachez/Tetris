/*
** EPITECH PROJECT, 2021
** MY_DELETE_NODE
** File description:
** Deletes the n-th node
*/

#include "../include/lib/linked_lists.h"

void my_delete_node(struct linked_list_t **list, int n)
{
    struct linked_list_t *head = *list;

    if (n == 0) {
        *list = (*list)->prev;
        (*list)->next = (*list)->next->next;
        (*list)->next->prev = *list;
        (*list) = (*list)->next;
        return;
    }
    for (int c = 0; c != n - 1; c++)
        *list = (*list)->next;
    (*list)->next = (*list)->next->next;
    (*list)->next->prev = *list;
    (*list) = head;
}
