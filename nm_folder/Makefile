##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

CC	=	gcc --std=gnu11

WAY	=	./src

COMMON_SRC_WAY = ../common_folder/src

COMMON_INCLUDE_WAY	= ../common_folder/include

WAY_INCLUDE	=	./include

SRC	=	$(WAY)/main.c 	\
		$(COMMON_SRC_WAY)/ELF64/getSection.c 	\
		$(COMMON_SRC_WAY)/stock_file.c 	\
		$(COMMON_SRC_WAY)/verification.c 	\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I$(WAY_INCLUDE)	\
			-I$(COMMON_INCLUDE_WAY)	\

CFLAGS	=	$(INCLUDES) -W -Wall -Wextra -Werror

LDFLAGS	=	-W -Wall -Wextra -Werror

NAME	=	my_nm

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o
	make clean -C ./tests

fclean: clean
	rm -f $(NAME)
	make fclean -C ./tests

re: fclean all

tests_run:
	make -C ./tests
