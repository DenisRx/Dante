/*
** EPITECH PROJECT, 2021
** maze_base
** File description:
** maze_base
*/

#include "generator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char **create_map(int x_max, int y_max)
{
    char **maze = malloc(sizeof(char *) * (y_max + 1));

    if (maze == NULL)
        return NULL;
    for (int i = 0; i != y_max; i++) {
        if ((maze[i] = malloc(sizeof(char) * (x_max + 1))) == NULL)
            return NULL;
        memset(maze[i], 'X', x_max);
        maze[i][x_max] = '\0';
    }
    maze[y_max] = NULL;
    return maze;
}

int print_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if (i == 0)
            printf("%s", maze[i]);
        else
            printf("\n%s", maze[i]);
    }
    return 0;
}