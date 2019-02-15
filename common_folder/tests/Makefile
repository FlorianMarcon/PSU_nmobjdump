##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

C	=	gcc

WAY	=	../src

INCLUDE_WAY	=	../include

SRC	=	$(WAY)/ELF64/getSection.c 	\
		$(WAY)/stock_file.c 	\
		$(WAY)/verification.c 	\

SRC_UT	=	ELF64/tests_utils.1.c \
		ELF64/tests_utils.2.c \

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDES	=	-I$(INCLUDE_WAY) \


CFLAGS	=	-W -Wall -Wextra -Werror --coverage -I../ $(INCLUDES)

LDFLAGS	=	-lcriterion -lgcov

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	$(C) -o $(NAME) $(OBJ) $(OBJ_UT) $(LDFLAGS) $(CFLAGS)
	./units

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	$(RM) $(NAME)

re:	clean all
