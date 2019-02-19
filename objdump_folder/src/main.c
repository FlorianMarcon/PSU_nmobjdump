/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** main
*/

#include <stdio.h>
#include "common.h"
#include "objdump.h"


void	process64(Elf64_Ehdr *elf)
{
	ELF64_showHeader(elf);
	if (elf->e_type == ET_EXEC)
		ELF64_showMemoryExecutable(elf);
	else if (elf->e_type == ET_REL)
		ELF64_showMemoryRelocatable(elf);
	else if (elf->e_type == ET_DYN)
		ELF64_showMemoryDynamic(elf);

		// printf("0x%x\n", elf->e_type);
	
}
void	process32(Elf32_Ehdr *elf)
{
	(void)elf;
	printf("process32\n");
}
int	process(char *filename)
{
	char *program = NULL;

	program = stock_file(filename);
	if (
		program == NULL
		|| ELF_verification_magic((Elf64_Ehdr *)program)
	)
		return (1);
	if (program[0x04] == 0x02) {
		printf("\n%s:     file format elf64-x86-64\n", filename);
		process64((void *)program);
	} else if (program[0x04] == 0x01) {
		printf("\n%s:     file format elf32-x86\n", filename);
		process32((void *)program);
	}
	return (0);
}
int	main(int ac, char **av)
{
	int sum = 0;

	for (int i = 1; i < ac; i++) {
		sum += process(av[i]);
	}
	if (sum > 0)
		return (84);
}