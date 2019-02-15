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
	dprintf(1, "Contenu de la section %s%c%c:\n", (char *)(section->sh_name + stringtable), 0xc2, 0xa0);
	// dprintf(1, "%x %lx\n", section->sh_type, section->sh_flags);
	for (unsigned int i = 0; i < (section->sh_size / 16) + 1; i++) {
		if (i * 16 == section->sh_size)
			break;
		dprintf(1, " %04lx", section->sh_addr + (i * 16));
		ELF_showMemoryBasic(content + (i * 16), section->sh_size - (i * 16));
		ELF_showMemoryAscii(content + (i * 16), section->sh_size - (i * 16));
		dprintf(1, "\n");
	}
}

void	ELF64_showMemoryExecutable(Elf64_Ehdr *elf)
{
	Elf64_Shdr *sections;

	if (elf == NULL)
		return;
	sections = elf->e_shoff + (void *)elf;
	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		if (
			(sections[i].sh_flags != 00 || sections[i].sh_type == 0x01)
			&& sections[i].sh_type != 0x08
			&& sections[i].sh_size != 0x00
			) {
				ELF64_showSectionMemory(elf, &sections[i]);
		}
	}
}

void	ELF64_showMemoryRelocatable(Elf64_Ehdr *elf)
{
	Elf64_Shdr *sections;

	if (elf == NULL)
		return;
	sections = elf->e_shoff + (void *)elf;
	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		if (
			sections[i].sh_flags != 00
			&& sections[i].sh_flags != 0x40
			&& sections[i].sh_flags != 0x03
			&& sections[i].sh_type != 0x08
			&& sections[i].sh_size != 0x00
			) {
				ELF64_showSectionMemory(elf, &sections[i]);
		}
	}
}