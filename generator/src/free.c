/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-denis.roux
** File description:
** free
*/

#include "generator.h"
#include <stdlib.h>

void free_all(char **maze, gen_t *head)
{
    int i = 0;

    while (maze[i] != NULL) {
        free(maze[i]);
        i++;
    }
    free(maze);
    free(head);
}