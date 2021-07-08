/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "generator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void usage(void)
{
    printf("USAGE\n"\
            "    ./generator x y [perfect]\n"\
            "DESCRIPTION\n"\
            "    x\t\tnumber of colums of the maze\n"\
            "    y\t\tnumber of lines of the maze\n"\
            "    perfect\tgeneration mode, imperfect by default (optional)\n");
    return;
}

int main(int ac, char **av)
{
    int perfect = 0;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    if (error_handling(ac, av, &perfect) == 1)
        return 84;
    return generator(av, perfect);
}