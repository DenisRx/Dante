/*
** EPITECH PROJECT, 2021
** solver
** File description:
** solver
*/

#include "my.h"
#include "solver.h"
#include <stdio.h>

int print_soluce(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if (i == 0)
            printf("%s", maze[i]);
        else
            printf("\n%s", maze[i]);
    }
    return 0;
}

int case_is_good(solver_t *solver, int x, int y, char **maze)
{
    if (x >= 0 && x < solver->lim_x && y >= 0 && y < solver->lim_y && \
    maze[y][x] == '*') {
        return 1;
    }
    return 0;
}

int check_dir(solver_t *solver, int x, int y, char **maze)
{
    if (y == solver->lim_y - 1 && x == solver->lim_x)
        return 1;
    if (x < 0 || y < 0 || x >= solver->lim_x || y >= solver->lim_y)
        return 0;
    if (case_is_good(solver, x, y, maze) == 1) {
        maze[y][x] = 'o';
        if (check_dir(solver, x + 1, y, maze) == 1)
            return 1;
        if (check_dir(solver, x, y + 1, maze) == 1)
            return 1;
        if (check_dir(solver, x - 1, y, maze) == 1)
            return 1;
        if (check_dir(solver, x, y - 1, maze) == 1)
            return 1;
        maze[y][x] = '*';
    }
    return 0;
}

int start_solver(char *buff, int ac)
{
    char **maze = my_str_to_word_array(buff, '\n');
    solver_t *solver = NULL;
    int exit = 0;

    if (maze == NULL)
        return 84;
    solver = init_struct_sol(maze);
    exit = error_handling(ac, maze, solver);
    if (exit == 1)
        return 0;
    else if (exit != 0)
        return exit;
    if (check_dir(solver, 0, 0 , maze))
        print_soluce(maze);
    else
        printf("no solution found\n");
    free_all(buff, maze, solver);
    return 0;
}