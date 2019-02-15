/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

#include <stdbool.h>
#include <string.h>
#include "common.h"

#define ISASCII(x) (x >= ' ' && x <= '~')

typedef struct keyvalue_s
{
	int key;
	char *value;
}keyvalue_t;

typedef struct flags_s
{
	bool has_reloc;
	bool exec_p;
	bool has_lineno;
	bool has_debug;
	bool has_syms;
	bool has_locals;
	bool dynamic;
	bool wp_text;
	bool d_paged;
}flags_t;

void	ELF_showMemoryBasic(char *memory, unsigned int size);
void	ELF_showMemoryAscii(char *memory, unsigned int size);

void	flags_init(flags_t *flags);
char	*flags_getString(int key);
void	flags_display(flags_t *flags);
unsigned int	flags_sum(flags_t *flags);

/**
 * 64
 */
void	ELF64_showSectionMemory(Elf64_Ehdr *elf, Elf64_Shdr *section);
void	ELF64_setFlags(Elf64_Ehdr *elf, flags_t *flags);
void	ELF64_showHeader(Elf64_Ehdr *elf);
void	ELF64_showMemoryRelocatable(Elf64_Ehdr *elf);
void	ELF64_showMemoryExecutable(Elf64_Ehdr *elf);

#endif /* !OBJDUMP_H_ */
