/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-denis.roux
** File description:
** error
*/

#include "my.h"
#include <string.h>

int error_handling(int ac, char **av, int *perfect)
{
    if (!av)
        return 1;
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        *perfect = 1;
    else if (ac != 3)
        return (1);
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[2]) < 1)
        return 1;
    return 0;
}