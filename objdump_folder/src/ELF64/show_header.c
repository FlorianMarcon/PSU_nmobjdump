/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** show_header
*/

#include <stdio.h>
#include "common.h"
#include "objdump.h"

void	ELF64_showHeader(Elf64_Ehdr *elf)
{
	flags_t flags;

	ELF64_setFlags(elf, &flags);
	dprintf(1, "architecture: i386:x86-64, fanions 0x%08x:\n", flags_sum(&flags));
	flags_display(&flags);
	dprintf(1, "adresse de départ 0x%016x\n", (unsigned int)elf->e_entry);
}