/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** getSections
*/

#include <elf.h>
#include "my.h"
#include "common.h"

linked_list_t	*ELF64_getSections(Elf64_Ehdr *elf)
{
	linked_list_t *list = NULL;
	Elf64_Shdr *header = ELF64_getSectionHeader_byType(elf, SHT_SYMTAB);
	Elf64_Sym *symboles;

	if (elf == NULL || (symboles = ELF64_getSectionContent_byType(elf, SHT_SYMTAB)) == NULL)
		return (NULL);
	for (unsigned int i = 0; i < header->sh_size / header->sh_entsize; i++) {
		if (list == NULL) {
			list = create_list(&symboles[i]);
		} else {
			create_node(list, &symboles[i]);
		}
	}
	return (list);
}


char	*ELF64_getSymboleName(Elf64_Ehdr *elf, Elf64_Sym *symbole)
{
	void *content = ELF64_getSectionContent_byName(elf, ".strtab");

	if (content == NULL || symbole == NULL)
		return (NULL);
	// dprintf(1, "%x\n", (unsigned int)(content - (void *)elf));
	return (content + symbole->st_name);
}