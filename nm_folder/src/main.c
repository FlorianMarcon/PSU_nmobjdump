/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#include "nm.h"
#include "common.h"

void	process64(Elf64_Ehdr *elf)
{
	linked_list_t *list = ELF64_getSections(elf);

	ELF64_showSections(elf, list);
	// dprintf(1, "64\n");
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
		process64((void *)program);
	} else if (program[0x04] == 0x01) {
		process32((void *)program);
	}
}
int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++) {
		process(av[i]);
	}
}