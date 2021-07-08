/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char *buff = NULL;

    if ((buff = read_file(av[1], buff)) == NULL)
        return 84;
    if (start_solver(buff, ac) == 84)
        return 84;
    return 0;
}