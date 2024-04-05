/*
** EPITECH PROJECT, 2021
** MY_APPEND_NODE
** File description:
** Appends a node in a circular linked list
*/

#include "../include/lib/linked_lists.h"
#include <stdlib.h>

void my_append_node(struct linked_list_t **list, int data)
{
    struct linked_list_t *head = (*list);

    if (*list) {
        while ((*list)->next != head)
            (*list) = (*list)->next;
        (*list)->next = malloc(sizeof(struct linked_list_t));
        (*list)->next->data = data;
        (*list)->next->next = head;
        (*list)->next->prev = (*list);
        head->prev = (*list)->next;
        (*list) = head;
    } else {
        (*list) = malloc(sizeof(struct linked_list_t));
        (*list)->data = data;
        (*list)->prev = (*list);
        (*list)->next = (*list);
    }
}
