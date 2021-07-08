##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	my_getnbr.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc ../$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean	all

.PHONY: all $(NAME) clean fclean re