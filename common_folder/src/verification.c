/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** verification
*/

#include <string.h>
#include "common.h"

int	ELF_verification_magic(Elf64_Ehdr *elf)
{
	char magic[] = {0x7F, 0x45, 0x4c, 0x46};

	if (elf == NULL)
		return (1);
	if (memcmp(elf, magic, 4) != 0)
		return (1);
	return (0);
}