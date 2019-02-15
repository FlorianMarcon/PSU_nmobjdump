##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

CC	=	gcc --std=gnu11

WAY	=	./src

WAY_INCLUDE	=	./include

SRC	=	$(WAY)/main.c 	\
		$(WAY)/common/stock_file.c 	\
		$(WAY)/ELF64/objdump.c 	\
		$(WAY)/ELF64/elf64_get.c 	\
		$(WAY)/ELF64/elf64_flags_handle.c 	\
		$(WAY)/common/show_mem.c \

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	-I$(WAY_INCLUDE)	\
				-I$(WAY_INCLUDE)/ELF64	\
				-I$(WAY_INCLUDE)/ELF32	\
				-I$(WAY_INCLUDE)/common	\

CFLAGS	=	$(INCLUDES) -W -Wall -Wextra -Werror

LDFLAGS	=	-W -Wall -Wextra -Werror

NAME	=	my_objdump

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
