/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** getSection
*/

#include <string.h>
#include "common.h"

Elf64_Shdr	*ELF64_getSectionHeader(Elf64_Ehdr *elf)
{
	if (elf == NULL)
		return (NULL);
	return ((void *)elf + elf->e_shoff);
}
Elf64_Shdr	*ELF64_getSectionHeader_byType(Elf64_Ehdr *elf, unsigned int type)
{
	Elf64_Shdr *sections = NULL;

	if (elf == NULL || (sections = ELF64_getSectionHeader(elf)) == NULL)
		return (NULL);
	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		if (sections[i].sh_type == type)
			return (&sections[i]);
	}
	return (NULL);
}

Elf64_Shdr	*ELF64_getSectionHeader_byName(Elf64_Ehdr *elf, const char *name)
{
	Elf64_Shdr *sections = NULL;
	char *tablename;

	if (
		elf == NULL
		|| name == NULL
		|| (sections = ELF64_getSectionHeader(elf)) == NULL
	)
		return (NULL);
	tablename = sections[elf->e_shstrndx].sh_offset + (void *)elf;
	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		if (strcmp(name, sections[i].sh_name + tablename) == 0)
			return (&sections[i]);
	}
	return (NULL);
}
void	*ELF64_getSectionContent_byType(Elf64_Ehdr *elf, unsigned int type)
{
	Elf64_Shdr *section = ELF64_getSectionHeader_byType(elf, type);

	if (section != NULL)
		return (section->sh_offset + (void *)elf);
	return (NULL);
}

void	*ELF64_getSectionContent_byName(Elf64_Ehdr *elf, const char *name)
{
	Elf64_Shdr *section = ELF64_getSectionHeader_byName(elf, name);

	if (section != NULL)
		return (section->sh_offset + (void *)elf);
	return (NULL);
}
void	*ELF64_getTableString(Elf64_Ehdr *elf)
{
	Elf64_Shdr *section;
	
	if (elf == NULL)
		return (NULL);
	section = elf->e_shoff + (void *)elf;
	section = &section[elf->e_shstrndx];
	return (section->sh_offset + (void *)elf);
}