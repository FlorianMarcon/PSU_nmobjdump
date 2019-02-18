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

WAY_LIB	=	./lib/my

SRC	=	$(WAY)/main.c 	\
		$(WAY)/symbole.c 	\
		$(COMMON_SRC_WAY)/ELF64/getSection.c 	\
		$(COMMON_SRC_WAY)/stock_file.c 	\
		$(COMMON_SRC_WAY)/verification.c 	\
		$(WAY)/ELF64/get.c 				\
		$(WAY)/ELF64/show.c 				\
		$(WAY)/ELF64/sort.c 				\

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I$(WAY_INCLUDE)	\
				-I$(COMMON_INCLUDE_WAY)	\

CFLAGS	=	$(INCLUDES) -W -Wall -Wextra -Werror

LDFLAGS	=	-W -Wall -Wextra -Werror 

LIB 	=	-L$(WAY_LIB) -lmy

NAME	=	my_nm

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(WAY_LIB)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

clean:
	rm -f $(OBJ)
	make clean -C $(WAY_LIB)
	make clean -C ./tests
	rm -f *.o

fclean: clean
	make fclean -C $(WAY_LIB)
	make fclean -C ./tests
	rm -f $(NAME)

re: fclean all

tests_run:
	make -C ./tests
