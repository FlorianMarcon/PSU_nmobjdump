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

symbole_item_t	*create_Item(Elf64_Ehdr *elf, Elf64_Sym *symbole)
{
	symbole_item_t *item = malloc(sizeof(*item));
	char *strtab = find_section(elf, find_section_header_by_name(elf, ".strtab"));
	
	if (item == NULL)
		return (NULL);
	item->symbole_addr = (void *)symbole;
	item->name_addr = (void *)(strtab + symbole->st_name);
	return (item);

}
// symbole_item_t	*create_Item_2(Elf64_Ehdr *elf, Elf64_Dyn *symbole)
// {
// 	symbole_item_t *item = malloc(sizeof(*item));
// 	char *strtab = find_section(elf, find_section_header_by_name(elf, ".strtab"));
	
// 	if (item == NULL)
// 		return (NULL);
// 		printf("%d\n", symbole->d_tag);
// 		printf("%d\n", symbole->d_un.)
// 	// item->symbole_addr = NULL;
// 	// item->name_addr = (void *)(strtab + symbole->st_name);
// 	return (item);

// }
linked_list_t    *nm_executable(Elf64_Ehdr *p)
{
	Elf64_Shdr *symtabheader = find_section_header(p, SHT_SYMTAB);
	Elf64_Sym *s;
	symbole_item_t *item = NULL;
	linked_list_t *list = NULL;

	for (unsigned int i = 0; i < symtabheader->sh_size / symtabheader->sh_entsize; i++) {
		s = (Elf64_Sym *)(symtabheader->sh_offset + (i * symtabheader->sh_entsize) + (void *)p);
		if (s->st_name != 0 && s->st_shndx != SHN_ABS) {
			if ((item = create_Item(p, s)) != NULL && list == NULL) {
				list = create_list(item);
			} else if ((item = create_Item(p, s)) != NULL) {
				create_node(list, item);
			}
		}
		(void)s;
	}
	// symtabheader = find_section_header(p, SHT_SYMTAB_SHNDX);
	// for (unsigned int i = 0; i < symtabheader->sh_size / symtabheader->sh_entsize; i++) {
	// 	s = (Elf64_Sym *)(symtabheader->sh_offset + (i * symtabheader->sh_entsize) + (void *)p);
	// 	if (s->st_name != 0 && s->st_info != STT_NOTYPE) {
	// 		if ((item = create_Item(p, s)) != NULL && list == NULL) {
	// 			list = create_list(item);
	// 		} else if ((item = create_Item(p, s)) != NULL) {
	// 			create_node(list, item);
	// 		}
	// 	}
	// 	(void)s;
	// }
	return (list);
}

void	display_symbole(Elf64_Ehdr *elf, linked_list_t *head)
{
	linked_list_t *list = head;
	symbole_item_t *item;
	char type;


(void)elf;
	while (list != NULL) {
		item = (symbole_item_t *)list->data;
		if (item != NULL) {
			type = getSymbole((Elf64_Shdr *)(elf->e_shoff + (void *) elf) , ((Elf64_Sym *)item->symbole_addr));
			if (((Elf64_Sym *)item->symbole_addr)->st_value == 0 && list != head) {
				printf("                 %c %s\n", type, (char *)item->name_addr);
			} else {
				printf("%016lx %c %s\n", ((Elf64_Sym *)item->symbole_addr)->st_value, type, (char *)item->name_addr);
			}
			// printf("%s\n", (char *)item->name_addr);
			
		}
		list = list->next;
	}
}
int    nm(void *p)
{
	Elf64_Ehdr *header = p;
	linked_list_t *list = NULL;
	if (p == NULL)
		return (1);
	switch (header->e_type)
	{
		case 0x00:
			printf(": 0x00\n");
			break;
		case 0x01:
			// printf("relocatble file : 0x01\n");
			list = nm_executable(p);
			break;
		case 0x02:
			// printf("Executable : 0x02\n");
			list = nm_executable(p);
			break;
		case 0x03:
			printf("shared file : 0x03\n");
			break;
		case 0x04:
			printf(": 0x04\n");
			break;
		case 0xfe00:
			printf(": 0xfe00\n");
			break;
		case 0xfeff:
			printf(" : 0xfeff\n");
			break;
		case 0xff00:
			printf(": 0xff00\n");
			break;
		case 0xffff:
			printf(" : 0xffff\n");
			break;
		default:
		printf("DEFAUL I don't know\n");
			break;
	
	}
	list = sort_list(list);
	display_symbole(p, list);

	// Elf64_Shdr *sec = find_section_header(header, SHT_DYNSYM);
	// // Elf64_Dyn *dyn;
	// for (unsigned int i = 0; i < header->e_shnum; i++) {
	// 	sec = find_section_header_by_index(p, i);
	// 	(void)sec;
	// 	if (sec->sh_entsize != 0)
	// 		printf("%d  Nb Entry %lx\n",sec->sh_type, sec->sh_size / sec->sh_entsize);
	// 	// DT_ADDRNUM;
		
	// }
	return (0);
}