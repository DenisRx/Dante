##
## EPITECH PROJECT, 2021
## make
## File description:
## Makefile
##

SRC			=	main.c \
				free.c \
				solver.c \
				init_solver.c \
				error.c

OBJ			=	$(addprefix src/, $(SRC:.c=.o))

CC			=	gcc

CFLAGS		=	-W -Wall -Wextra
CPPFLAGS	=	-I./include

RM			=	rm -rf

NAME		=	solver

all:	$(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	$(CC) -o $@ $^ -L./lib -lmy

clean:
	$(RM) $(OBJ)
	make -C lib/my clean

fclean: clean
	$(RM) $(NAME)
	make -C lib/my fclean
	rm -f *.gc*

re:		fclean 	all

.PHONY: all $(NAME) clean fclean re