##
## EPITECH PROJECT, 2017
## Makefile pour compresser lib
## File description:
## Makefile
##

WAY_OBJDUMP	=	./objdump_folder

WAY_NM		=	./nm_folder

all: objdump nm

nm:
	make -C $(WAY_NM)
	cp $(WAY_NM)/my_nm ./

objdump:
	make -C $(WAY_OBJDUMP)
	cp $(WAY_OBJDUMP)/my_objdump ./

clean:
	make clean -C $(WAY_NM)
	make clean -C $(WAY_OBJDUMP)

fclean:
	make fclean -C $(WAY_NM)
	make fclean -C $(WAY_OBJDUMP)
	rm my_nm my_objdump

re: fclean all

tests_run:
	make tests_run -C $(WAY_NM)
	make tests_run -C $(WAY_OBJDUMP)
