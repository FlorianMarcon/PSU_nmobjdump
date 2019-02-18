##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

CC	=	gcc --std=gnu11

WAY	=	./src

WAY_LIB	=	./lib/my

WAY_TEST = ./tests

SRC	=	$(WAY)/main.c 	\
		$(WAY)/nm/nm.c 	\
		$(WAY)/stock_file.c 	\
		$(WAY)/find/find.c 	\
		$(WAY)/list/sort.c 	\
		$(WAY)/symbole/symbole.c 	\

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L./lib/my -lmy 

CFLAGS	=	-I./include -I./include/nm -W -Wall -Wextra -Werror

NAME	=	my_nm

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) 

clean:
	make clean -C $(WAY_LIB)
	rm -f $(OBJ)
	rm -f *.o

fclean: clean
	make fclean -C $(WAY_LIB)
	make fclean -C $(WAY_TEST)
	rm -f $(NAME)

re: fclean all

tests_run:
	make -C $(WAY_TEST)