/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-denis.roux
** File description:
** imperfect
*/

#include <stdlib.h>

void add_stars(char **maze, int i)
{
    for (int x = 0; maze[i][x] != '\0'; x++) {
        if ((random() % 3) == 1)
            maze[i][x] = '*';
    }
}

int create_imperfect(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if ((random() % 3) == 1)
            add_stars(maze, i);
    }
    return 0;
}