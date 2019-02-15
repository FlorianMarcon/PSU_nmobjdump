/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** show_mem
*/

#include <stdio.h>
#include "common.h"
#include "objdump.h"

void	ELF_showMemoryBasic(char *memory, unsigned int size)
{
	for (unsigned int i = 0; i < 16; i++) {
		if (i % 4 == 0)
			dprintf(1, " ");
		if (i >= size) {
			dprintf(1, "  ");
		} else {
			dprintf(1, "%02x", memory[i]);
		}
	}
}

void	ELF_showMemoryAscii(char *memory, unsigned int size)
{
	dprintf(1, " ");
	for (unsigned int i = 0; i < 16; i++) {
		if (i < size && ISASCII(memory[i])) {
			dprintf(1, "%c", memory[i]);
		} else if (i < size) {
			dprintf(1, ".");
		} else {
			dprintf(1, " ");
		}
	}
}