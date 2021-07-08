##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Task01 Day10
##

SRC    	=    	my_strlen.c \
				my_str_wordarray.c \
				my_reader.c

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