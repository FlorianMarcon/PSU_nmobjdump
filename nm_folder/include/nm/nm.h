/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm
*/

#ifndef NM_H_
	#define NM_H_

#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int    ELF64_nm(void *p);
void	*ELF64_find_name_section(Elf64_Ehdr *elf);

#define isAscii(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x == 0))

typedef struct symbole_value_s
{
	char symbole;
	char type;
	char bind;
}symbole_value_t;

typedef struct symbole_item_s {
	void *symbole_addr;
	void *name_addr;
}symbole_item_t;

Elf64_Shdr	*ELF64_find_section_header(Elf64_Ehdr *header_program, unsigned int type);
void	*ELF64_find_section(Elf64_Ehdr *header_program, Elf64_Shdr *header_section);
Elf64_Shdr	*ELF64_find_section_header_by_name(Elf64_Ehdr *elf, const char *name);


void	*ELF64_find_name_section(Elf64_Ehdr *elf);
Elf64_Shdr	*ELF64_find_section_header_by_index(Elf64_Ehdr *elf, unsigned int index);
Elf64_Shdr	*ELF64_find_section_header(Elf64_Ehdr *elf, unsigned int type);
Elf64_Shdr	*ELF64_find_section_header_by_name(Elf64_Ehdr *elf, const char *name);
void	ELF64_display_information_header(Elf64_Shdr *h);
void	*ELF64_find_section(Elf64_Ehdr *header_program, Elf64_Shdr *header_section);

int	ELF64_compare_name(char *a, char *b);
linked_list_t	*ELF64_sort_list(linked_list_t *head);

char	ELF64_getSymbole(Elf64_Shdr *sh, Elf64_Sym *sym);
#endif /* !NM_H_ */
