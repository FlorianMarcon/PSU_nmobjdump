##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

C	=	gcc

WAY	=	../src

WAY_LIB	=	../lib/my

INCLUDE_WAY	=	../include

SRC	=		$(WAY)/stock_file.c 	\
			$(WAY)/nm/nm.c 		\
			$(WAY)/find/find.c 	\
			$(WAY)/list/sort.c 	\
			$(WAY)/symbole/symbole.c 	\

SRC_UT	=	stock_file/tests_utils.1.c 	\
			nm/tests_utils.1.c 	\
			list/tests_utils.1.c 	\
			symbole/tests_utils.1.c 	\

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDES	=	-I./$(INCLUDE_WAY)		\
				-I./$(INCLUDE_WAY)/nm		\

CFLAGS	=	-W -Wall -Wextra -Werror --coverage -I../ $(INCLUDES)

LDFLAGS	=	-lcriterion -lgcov -L$(WAY_LIB) -lmy

NAME	=	units

all:	$(OBJ) $(OBJ_UT)
	make -C $(WAY_LIB)
	$(C) -o $(NAME) $(OBJ) $(OBJ_UT) $(LDFLAGS) $(CFLAGS)
	./units

clean:
	make clean -C $(WAY_LIB)
	$(RM) $(OBJ)
	$(RM) $(OBJ_UT)
	$(RM) $(OBJ:.o=.gcda)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ_UT:.o=.gcda)
	$(RM) $(OBJ_UT:.o=.gcno)

fclean:	clean
	make fclean -C $(WAY_LIB)
	$(RM) $(NAME)

re:	clean all
