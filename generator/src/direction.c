/*
** EPITECH PROJECT, 2021
** direction
** File description:
** direction
*/

#include "my.h"
#include "generator.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int check_dir_next(gen_t *gen, int lim_x, int lim_y, char **maze)
{
    int star = 0;

    if (gen->y > 0)
        star = (maze[gen->y - 1][gen->x] == '*' ? ++star : star);
    if (gen->x < lim_x - 1)
        star = (maze[gen->y][gen->x + 1] == '*' ? ++star : star);
    if (gen->y < lim_y - 1)
        star = (maze[gen->y + 1][gen->x] == '*' ? ++star : star);
    if (gen->x > 0)
        star = (maze[gen->y][gen->x - 1] == '*' ? ++star : star);
    return star;
}

int check_dir2(gen_t *gen, int lim_x, int lim_y, char **maze)
{
    if (gen->y < lim_y - 1 && maze[gen->y + 1][gen->x] == 'X') {
        gen->y += 1;
        gen->bot = (check_dir_next(gen, lim_x, lim_y, maze) == 1 ? 1 : 0);
        gen->y -= 1;
    } else
        gen->bot = 0;
    if (gen->x > 0 && maze[gen->y][gen->x - 1] == 'X') {
        gen->x -= 1;
        gen->left = (check_dir_next(gen, lim_x, lim_y, maze) == 1 ? 1 : 0);
        gen->x += 1;
    } else
        gen->left = 0;
    return 0;
}

int check_dir(gen_t *gen, int lim_x, int lim_y, char **maze)
{
    if (gen->y > 0 && maze[gen->y - 1][gen->x] == 'X') {
        gen->y -= 1;
        gen->top = (check_dir_next(gen, lim_x, lim_y, maze) == 1 ? 1 : 0);
        gen->y += 1;
    } else
        gen->top = 0;
    if (gen->x < lim_x - 1 && maze[gen->y][gen->x + 1] == 'X') {
        gen->x += 1;
        gen->right = (check_dir_next(gen, lim_x, lim_y, maze) == 1 ? 1 : 0);
        gen->x -= 1;
    } else
        gen->right = 0;
    check_dir2(gen, lim_x, lim_y, maze);
    return 0;
}

int check_block(gen_t *current)
{
    if (BLOCKED) {
        if (current->x == 0 && current->y == 0) {
            return 1;
        }
        current = remove_node(current);
        return 0;
    }
    return 0;
}

int manage_dir(gen_t *current, int val, int *stop)
{
    if (check_block(current) == 1) {
        *stop = 0;
        return 0;
    }
    if (val == 0 && current->top == 1) {
        add_node(current, current->x, current->y - 1);
        current = current->next;
    }
    if (val == 1 && current->right == 1) {
        add_node(current, current->x + 1, current->y);
        current = current->next;
    }
    if (val == 2 && current->bot == 1) {
        add_node(current, current->x, current->y + 1);
        current = current->next;
    }
    if (val == 3 && current->left == 1) {
        add_node(current, current->x - 1, current->y);
        current = current->next;
    }
    return 0;
}