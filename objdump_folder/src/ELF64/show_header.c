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
	printf("architecture: i386:x86-64, flags 0x%08x:\n", flags_sum(&flags));
	flags_display(&flags);
	printf("start address 0x%016x\n\n", (unsigned int)elf->e_entry);
}