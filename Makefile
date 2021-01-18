##
## EPITECH PROJECT, 2019
## CPE_malloc_2019
## File description:
## __DESCRIPTION__
##

SRC	=	my_malloc.c 	\
		malloc_fct.c 	\
		my_free.c

OBJ	=	$(SRC:.c=.o)

NAME	=	 libmy_malloc.so	\

all:	$(NAME)

CFLAGS = -Wall -fPIC

$(NAME):	$(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
		rm -rf

.PHONY:		all clean fclean re