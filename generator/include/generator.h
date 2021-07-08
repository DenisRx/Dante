/*
** EPITECH PROJECT, 2021
** generator
** File description:
** generator
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#define BLOCKED current->top == 0 && current->right == 0 && \
current->bot == 0 && current->left == 0

#define END_BLOCKED_ONLY maze[lim_y][lim_x] == 'X' && \
maze[lim_y - 1][lim_x] == '*' && maze[lim_y][lim_x - 1] == '*' && \
maze[lim_y - 1][lim_x - 1] == '*'

#define END_SEMI_BLOCKED maze[lim_y][lim_x] == 'X' && \
maze[lim_y - 1][lim_x] == 'X' && maze[lim_y][lim_x - 1] == 'X' && \
maze[lim_y - 1][lim_x - 1] == '*'

#define END_FULLY_BLOCKED maze[lim_y][lim_x] == 'X' && \
maze[lim_y - 1][lim_x] == 'X' && maze[lim_y][lim_x - 1] == 'X' && \
maze[lim_y - 2][lim_x] == 'X' && maze[lim_y][lim_x - 2] == 'X'

typedef struct gen {
    int x;
    int y;
    int top;
    int bot;
    int left;
    int right;
    struct gen *next;
    struct gen *previous;
}gen_t;

int error_handling(int ac, char **av, int *perfect);
gen_t *init_struct_gen();
int generator(char **av, int perfect);
char **create_map(int x_max, int y_max);
int create_imperfect(char **maze);
int print_maze(char **maze);
void add_node(gen_t *list, int x, int y);
gen_t *remove_node(gen_t *list);
int check_dir_next(gen_t *gen, int lim_x, int lim_y, char **maze);
int check_dir2(gen_t *gen, int lim_x, int lim_y, char **maze);
int check_dir(gen_t *gen, int lim_x, int lim_y, char **maze);
int manage_dir(gen_t *current, int val, int *stop);
void free_all(char **maze, gen_t *head);

#endif /* !GENERATOR_H */
