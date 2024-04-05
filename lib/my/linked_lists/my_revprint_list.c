/*
** EPITECH PROJECT, 2021
** MY_REVPRINT_LIST
** File description:
** Prints a circular linked list from the end
*/

#include "../include/lib/linked_lists.h"
#include "../include/lib/output.h"

void my_revprint_list(struct linked_list_t *list)
{
    struct linked_list_t *head = list;

    do {
        list = list->prev;
        my_printf("%d", list->data);
    } while (list != head);
}
