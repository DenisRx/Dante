/*
** EPITECH PROJECT, 2021
** SOLVER_H
** File description:
** SOLVER_H
*/

#ifndef Solver
#define Solver

typedef struct solver {
    int lim_x;
    int lim_y;
}solver_t;

solver_t *init_struct_sol(char **maze);
int start_solver(char *buff, int ac);
int error_handling(int ac, char **map, solver_t *solver);
void free_all(char *buff, char **maze, solver_t *solver);

#endif /* !Solver */
