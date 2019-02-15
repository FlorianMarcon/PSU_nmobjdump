/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** common
*/

#ifndef COMMON_H_
	#define COMMON_H_

#include <unistd.h>
#include <elf.h>

int	ELF_verification_magic(Elf64_Ehdr *elf);
void	*stock_file(const char *filename);

/**
 * 64
 */
Elf64_Shdr	*ELF64_getSectionHeader(Elf64_Ehdr *elf);
Elf64_Shdr	*ELF64_getSectionHeader_byType(Elf64_Ehdr *elf, unsigned int type);
Elf64_Shdr	*ELF64_getSectionHeader_byName(Elf64_Ehdr *elf, const char *name);
void	*ELF64_getSectionContent_byType(Elf64_Ehdr *elf, unsigned int type);
void	*ELF64_getSectionContent_byName(Elf64_Ehdr *elf, const char *name);
void	*ELF64_getTableString(Elf64_Ehdr *elf);

#endif /* !COMMON_H_ */
