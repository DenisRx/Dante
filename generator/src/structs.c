/*
** EPITECH PROJECT, 2021
** init
** File description:
** init
*/

#include "generator.h"
#include <stdlib.h>

gen_t *init_struct_gen(void)
{
    gen_t *head = malloc(sizeof(gen_t));

    if (head == NULL)
        return NULL;
    head->x = 0;
    head->y = 0;
    head->top = 0;
    head->bot = 1;
    head->left = 0;
    head->right = 1;
    head->next = NULL;
    head->previous = NULL;
    return head;
}

void add_node(gen_t *list, int x, int y)
{
    gen_t *tmp = list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    list->next = malloc(sizeof(gen_t));
    list->next->x = x;
    list->next->y = y;
    list->next->top = 0;
    list->next->bot = 0;
    list->next->left = 0;
    list->next->right = 0;
    list->next->next = NULL;
    list->next->previous = list;
}

gen_t *remove_node(gen_t *list)
{
    gen_t *tmp = list->previous;

    tmp->next = NULL;
    free(list);
    return (tmp);
}