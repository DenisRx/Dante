/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-denis.roux
** File description:
** free
*/

#include "solver.h"
#include <stdlib.h>

void free_all(char *buff, char **maze, solver_t *solver)
{
    int i = 0;

    free(buff);
    while (maze[i] != NULL) {
        free(maze[i]);
        i++;
    }
    free(maze);
    free(solver);
}