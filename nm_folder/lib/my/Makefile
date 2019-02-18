##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard *.c)		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I../../include -W -Wall -Wextra -Werror

NAME	=	libmy.a

all:		$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
