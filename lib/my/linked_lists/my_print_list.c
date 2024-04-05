/*
** EPITECH PROJECT, 2021
** MY_PRINT_LIST
** File description:
** Prints a circular linked list from the beginning
*/

#include "../include/lib/linked_lists.h"
#include "../include/lib/output.h"

void my_print_list(struct linked_list_t *list)
{
    struct linked_list_t *head = list;

    do {
        my_printf("%d", list->data);
        list = list->next;
    } while (list != head);
}
