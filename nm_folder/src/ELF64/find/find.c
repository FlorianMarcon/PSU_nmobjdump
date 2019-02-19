/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** find
*/

#include <string.h>
#include "nm.h"

void	*ELF64_find_name_section(Elf64_Ehdr *elf)
{
	Elf64_Shdr *h;
	void	*section;

	h = (Elf64_Shdr *)(elf->e_shoff + (elf->e_shentsize * elf->e_shstrndx) + (long int)elf);
	section = ELF64_find_section(elf, h);
	return (section);
}

Elf64_Shdr	*ELF64_find_section_header_by_index(Elf64_Ehdr *elf, unsigned int index)
{
	Elf64_Shdr *h;
	h = (Elf64_Shdr *)(elf->e_shoff + (elf->e_shentsize * index) + (long int)elf);
	
	return (h);
}


Elf64_Shdr	*ELF64_find_section_header(Elf64_Ehdr *elf, unsigned int type)
{
	Elf64_Shdr *h;

	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		h = (Elf64_Shdr *)(elf->e_shoff + (elf->e_shentsize * i) + (long int)elf);
		if (h->sh_type == type) {
			return (h);
		}
		
	}
	return (NULL);
}
Elf64_Shdr	*ELF64_find_section_header_by_name(Elf64_Ehdr *elf, const char *name)
{
	Elf64_Shdr *h;
	void *nameSection = ELF64_find_name_section(elf);

	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		h = (Elf64_Shdr *)(elf->e_shoff + (elf->e_shentsize * i) + (long int)elf);
		if (strcmp(nameSection + h->sh_name, name) == 0)
			return (h);
	}
	return (NULL);
}

void	*ELF64_find_section(Elf64_Ehdr *header_program, Elf64_Shdr *header_section)
{
	void *address = (void *)header_program + header_section->sh_offset;

	return (address);
}