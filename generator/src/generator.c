/*
** EPITECH PROJECT, 2021
** generator
** File description:
** generator
*/

#include "my.h"
#include "generator.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int create_path(gen_t *head, char **maze, int x_max, int y_max)
{
    int val = 0;
    int loop = 1;
    int stop = 0;
    gen_t *current = head;

    while (!stop) {
        maze[current->y][current->x] = '*';
        check_dir(current, x_max, y_max, maze);
        while (loop) {
            val = random() % 4;
            if (BLOCKED) {
                if (current->x == 0 && current->y == 0) {
                    stop = 1;
                    break;
                }
                current = remove_node(current);
                break;
            }
            if (val == 0 && current->top == 1) {
                add_node(current, current->x, current->y - 1);
                current = current->next;
                break;
            }
            if (val == 1 && current->right == 1) {
                add_node(current, current->x + 1, current->y);
                current = current->next;
                break;
            }
            if (val == 2 && current->bot == 1) {
                add_node(current, current->x, current->y + 1);
                current = current->next;
                break;
            }
            if (val == 3 && current->left == 1) {
                add_node(current, current->x - 1, current->y);
                current = current->next;
                break;
            }
        }
    }
    return 0;
}

int good_end(char **maze, int lim_x, int lim_y)
{
    if (maze[lim_y][lim_x] == '*')
        return 0;
    if (END_BLOCKED_ONLY) {
        maze[lim_y][lim_x] = '*';
        maze[lim_y - 1][lim_x - 1] = 'X';
        return 0;
    }
    if (END_SEMI_BLOCKED) {
        maze[lim_y][lim_x] = '*';
        maze[lim_y][lim_x - 1] = '*';
        maze[lim_y - 1][lim_x - 2] = 'X';
    }
    if (END_FULLY_BLOCKED) {
        maze[lim_y][lim_x] = '*';
        maze[lim_y][lim_x - 1] = '*';
        maze[lim_y][lim_x - 2] = '*';
        maze[lim_y - 1][lim_x - 3] = 'X';
    }
    return 0;
}

int generator(char **av, int perfect)
{
    gen_t *head = init_struct_gen();
    char **maze = NULL;
    int x_max = my_getnbr(av[1]);
    int y_max = my_getnbr(av[2]);

    if (head == NULL)
        return 84;
    srandom(time(NULL));
    if ((maze = create_map(x_max, y_max)) == NULL)
        return 84;
    create_path(head, maze, x_max, y_max);
    good_end(maze, x_max - 1, y_max - 1);
    if (perfect == 0)
        create_imperfect(maze);
    print_maze(maze);
    free_all(maze, head);
    return 0;
}