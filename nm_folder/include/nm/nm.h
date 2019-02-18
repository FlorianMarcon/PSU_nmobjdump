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

int    nm(void *p);
void	*find_name_section(Elf64_Ehdr *elf);

#define isAscii(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x == 0))


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

Elf64_Shdr	*find_section_header(Elf64_Ehdr *header_program, unsigned int type);
void	*find_section(Elf64_Ehdr *header_program, Elf64_Shdr *header_section);
Elf64_Shdr	*find_section_header_by_name(Elf64_Ehdr *elf, const char *name);


void	*find_name_section(Elf64_Ehdr *elf);
Elf64_Shdr	*find_section_header_by_index(Elf64_Ehdr *elf, unsigned int index);
Elf64_Shdr	*find_section_header(Elf64_Ehdr *elf, unsigned int type);
Elf64_Shdr	*find_section_header_by_name(Elf64_Ehdr *elf, const char *name);
void	display_information_header(Elf64_Shdr *h);
void	*find_section(Elf64_Ehdr *header_program, Elf64_Shdr *header_section);


// void	sort_list(linked_list_t *list);
// void	swap_node(linked_list_t **head, linked_list_t *one, linked_list_t *two);
int	compare_name(char *a, char *b);
linked_list_t	*sort_list(linked_list_t *head);

char	getSymbole(Elf64_Shdr *sh, Elf64_Sym *sym);
#endif /* !NM_H_ */
