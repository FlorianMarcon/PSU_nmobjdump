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
	if (elf->e_type == ET_REL)
		ELF64_showMemoryRelocatable(elf);
}
void	process32(Elf32_Ehdr *elf)
{
	(void)elf;
	dprintf(1, "process32\n");
}
void	process(char *filename)
{
	char *program = NULL;

	program = stock_file(filename);
	if (
		program == NULL
		|| ELF_verification_magic((Elf64_Ehdr *)program)
	)
		return;
	if (program[0x04] == 0x02) {
		dprintf(1, "\n%s:     format de fichier elf64-x86-64\n", filename);
		process64((void *)program);
	} else if (program[0x04] == 0x01) {
		dprintf(1, "\n%s:     format de fichier elf32-x86\n", filename);
		process32((void *)program);
	}
}
int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		process(av[i]);
	}
}