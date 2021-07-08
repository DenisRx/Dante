/*
** EPITECH PROJECT, 2021
** init
** File description:
** init
*/

#include "solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int height_maze(char **maze)
{
    int len = 0;

    while (maze[len] != NULL) {
        len++;
    }
    return len;
}

solver_t *init_struct_sol(char **maze)
{
    solver_t *solver = malloc(sizeof(solver_t));

    if (maze == NULL || solver == NULL)
        return NULL;
    solver->lim_x = strlen(maze[0]);
    solver->lim_y = height_maze(maze);
    return solver;
}