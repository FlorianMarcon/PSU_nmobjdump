/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** show
*/

#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#include "my.h"
#include "nm.h"
#include "common.h"

void	ELF64_showSymboleValue(Elf64_Sym *symbole)
{
	if (symbole->st_value == 0x00)
		dprintf(1, "                 ");
	else {
		dprintf(1, "%016lx ", symbole->st_value);
	}
}
void	ELF64_showSections(Elf64_Ehdr *elf, linked_list_t *list)
{
	Elf64_Sym *symbole;
	Elf64_Shdr *sections = elf->e_shoff + (void *)elf;
	char *s;
	// int i = 0;

	list = ELF64_sort_list(elf, list);
	while (list != NULL){
		symbole = list->data;
		if (
			symbole != NULL
			&& symbole->st_name != 0
			&& symbole->st_shndx < elf->e_shnum
			&& (s = ELF64_getSymboleName(elf, symbole)) != NULL
			) {
			ELF64_showSymboleValue(symbole);
			dprintf(1, "%c %s\n", getSymbole(&sections[symbole->st_shndx] , symbole), s);
		}
		list = list->next;
	}
}