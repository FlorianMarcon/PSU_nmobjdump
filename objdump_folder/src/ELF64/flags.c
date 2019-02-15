/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** flags
*/

#include "common.h"
#include "objdump.h"

void	ELF64_setFlags(Elf64_Ehdr *elf, flags_t *flags)
{
	Elf64_Shdr *sections;

	flags_init(flags);
	if (elf == NULL || flags == NULL)
		return;
	if (elf->e_type == ET_EXEC)
		flags->exec_p = true;
	else if (elf->e_type == ET_DYN)
		flags->dynamic = true;
	else if (elf->e_type == ET_REL)
		flags->has_reloc = true;
	
	sections = elf->e_shoff + (void *)elf;
	for (unsigned int i = 0; i < elf->e_shnum; i++) {
		switch (sections[i].sh_type) {
			case SHT_SYMTAB: flags->has_syms = true; break;
			case SHT_DYNAMIC: flags->has_syms = true; break;
			// case SHT_REL: flags->has_reloc = true; break;
			// case SHT_RELA: flags->has_reloc = true; break;
		} 
	}
	if (elf->e_phnum != 0)
		flags->d_paged = true;
}