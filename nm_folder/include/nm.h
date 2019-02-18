/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** nm
*/

#ifndef NM_H_
	#define NM_H_

#include <elf.h>
#include "my.h"

typedef struct	s_flags
{
	unsigned int	x;
	uint32_t	type;
	uint32_t	flags;
	char		ch;
}	flags_t;

typedef struct	s_type
{
	char		ch;
	uint32_t	type;
	uint64_t	flags;
} type_t;

#define isAscii(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x == 0))

char	getSymbole(Elf64_Shdr *shdr, Elf64_Sym *sym);
linked_list_t	*ELF64_getSections(Elf64_Ehdr *elf);
void	ELF64_showSections(Elf64_Ehdr *elf, linked_list_t *list);
char	*ELF64_getSymboleName(Elf64_Ehdr *elf, Elf64_Sym *symbole);
linked_list_t	*ELF64_sort_list(Elf64_Ehdr *elf, linked_list_t *head);

#endif /* !NM_H_ */
