/*
** EPITECH PROJECT, 2019
** objdump_folder
** File description:
** show_mem
*/

#include <unistd.h>
#include <stdio.h>
#include "common.h"
#include "objdump.h"

void	ELF64_showSectionMemory(Elf64_Ehdr *elf, Elf64_Shdr *section)
{
	void *stringtable;
	void *content;

	if (
		elf == NULL
		|| section == NULL
		|| (stringtable = ELF64_getTableString(elf)) == NULL
		)
		return ;
	content = section->sh_offset + (void *)elf;
	dprintf(1, "Contenu de la section %s :\n", (char *)(section->sh_name + stringtable));
	for (unsigned int i = 0; i < (section->sh_size / 16) + 1; i++) {
		dprintf(1, " %04lx", section->sh_addr + (i * 16));
		ELF_showMemoryBasic(content + (i * 16), section->sh_size - (i * 16));
		ELF_showMemoryAscii(content + (i * 16), section->sh_size - (i * 16));
		dprintf(1, "\n");
	}
}