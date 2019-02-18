##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## corewar
##

C	=	gcc

WAY	=	../src

COMMON_SRC_WAY = ../../common_folder/src

COMMON_INCLUDE_WAY	= ../../common_folder/include

INCLUDE_WAY	=	../include 	\


SRC	=	$(COMMON_SRC_WAY)/ELF64/getSection.c 	\
		$(COMMON_SRC_WAY)/stock_file.c 	\
		$(COMMON_SRC_WAY)/verification.c 	\

SRC_UT	=	ELF64/tests_utils.1.c \
			ELF64/tests_utils.2.c \
			common/tests_utils.1.c \
			common/tests_utils.2.c \

OBJ	=	$(SRC:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDES	=	-I$(INCLUDE_WAY) \
				-I$(COMMON_INCLUDE_WAY)	\


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
