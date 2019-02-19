/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "nm.h"

symbole_item_t	*ELF64_create_Item(Elf64_Ehdr *elf, Elf64_Sym *symbole)
{
	symbole_item_t *item = malloc(sizeof(*item));
	char *strtab = ELF64_find_section(elf, ELF64_find_section_header_by_name(elf, ".strtab"));
	
	if (item == NULL)
		return (NULL);
	item->symbole_addr = (void *)symbole;
	item->name_addr = (void *)(strtab + symbole->st_name);
	return (item);

}
linked_list_t    *ELF64_nm_executable(Elf64_Ehdr *p)
{
	Elf64_Shdr *symtabheader = ELF64_find_section_header(p, SHT_SYMTAB);
	Elf64_Sym *s;
	symbole_item_t *item = NULL;
	linked_list_t *list = NULL;

	if (symtabheader == NULL) {
		return (NULL);
	}
	for (unsigned int i = 0; i < symtabheader->sh_size / symtabheader->sh_entsize; i++) {
		s = (Elf64_Sym *)(symtabheader->sh_offset + (i * symtabheader->sh_entsize) + (void *)p);
		if (s->st_name != 0 && s->st_shndx != SHN_ABS) {
			if ((item = ELF64_create_Item(p, s)) != NULL && list == NULL) {
				list = create_list(item);
			} else if ((item = ELF64_create_Item(p, s)) != NULL) {
				create_node(list, item);
			}
		}
		(void)s;
	}
	return (list);
}

void	ELF64_display_symbole(Elf64_Ehdr *elf, linked_list_t *head)
{
	linked_list_t *list = head;
	symbole_item_t *item;
	char type;

	while (list != NULL) {
		item = (symbole_item_t *)list->data;
		if (item != NULL) {
			type = ELF64_getSymbole((Elf64_Shdr *)(elf->e_shoff + (void *) elf) , ((Elf64_Sym *)item->symbole_addr));
			if (((Elf64_Sym *)item->symbole_addr)->st_value == 0 && type != 'T') {
				printf("                 %c %s\n", type, (char *)item->name_addr);
			} else {
				printf("%016lx %c %s\n", ((Elf64_Sym *)item->symbole_addr)->st_value, type, (char *)item->name_addr);
			}
			// printf("%s\n", (char *)item->name_addr);
			
		}
		list = list->next;
	}
}
int    ELF64_nm(void *p)
{
	Elf64_Ehdr *header = p;
	linked_list_t *list = NULL;

	if (p == NULL)
		return (1);
	switch (header->e_type)
	{
		case 0x01:
			list = ELF64_nm_executable(p);
			break;
		case 0x02:
			list = ELF64_nm_executable(p);
			break;
		case 0x03:
			list = ELF64_nm_executable(p);
			break;
		default:
		printf("DEFAUL I don't know\n");
			return (1);
			break;
	
	}
	if (list == NULL)
		return (2);
	list = ELF64_sort_list(list);
	ELF64_display_symbole(p, list);
	return (0);
}