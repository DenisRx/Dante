##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC			=	main.c \
				error.c \
				free.c \
				gen_base.c \
				generator.c \
				structs.c \
				imperfect.c \
				direction.c

OBJ			=	$(addprefix src/, $(SRC:.c=.o))

CC			=	gcc

CFLAGS		=	-W -Wall -Wextra
CPPFLAGS	=	-I./include

RM			=	rm -rf

NAME		=	generator

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