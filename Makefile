##
## EPITECH PROJECT, 2021
## B-CPE-200-BDX-2-1-dante-denis.roux
## File description:
## Makefile
##

all:
	make -C ./generator
	make -C ./solver

clean:
		make -C ./generator $@
		make -C ./solver $@

fclean: clean
		make -C ./generator $@
		make -C ./solver $@

re:		fclean 	all

.PHONY: all $(NAME) clean fclean re