/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "my.h"
#include "solver.h"
#include <stdio.h>
#include <string.h>

int check_element(char **map)
{
    int x = 0;
    int y = 0;

    while (map[y] != NULL) {
        if (map[y][x] == '\0') {
            y++;
            x = 0;
            continue;
        }
        if (map[y][x] != '*' && map[y][x] != 'X' && map[y][x] != '\n')
            return 84;
        x++;
    }
    return 0;
}

int error_handling(int ac, char **map, solver_t *solver)
{
    size_t len = strlen(map[0]);

    if (ac != 2)
        return 84;
    if (map[0][0] != '*' || map[solver->lim_y - 1][solver->lim_x - 1] != '*') {
        printf("no solution found\n");
        return 1;
    }
    for (int i = 0; map[i] != NULL; i++) {
        if (len != strlen(map[i]))
            return 84;
    }
    if (check_element(map) == 84)
        return 84;
    return 0;
}