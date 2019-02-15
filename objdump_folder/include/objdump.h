/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

#include "common.h"

#define ISASCII(x) (x >= ' ' && x <= '~')


void	ELF_showMemoryBasic(char *memory, unsigned int size);
void	ELF_showMemoryAscii(char *memory, unsigned int size);

/**
 * 64
 */
void	ELF64_showSectionMemory(Elf64_Ehdr *elf, Elf64_Shdr *section);

#endif /* !OBJDUMP_H_ */
