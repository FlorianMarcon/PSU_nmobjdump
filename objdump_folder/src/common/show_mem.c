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
			printf(" ");
		if (i >= size) {
			printf("  ");
		} else {
			printf("%02hhx", memory[i]);
		}
	}
}

void	ELF_showMemoryAscii(char *memory, unsigned int size)
{
	printf("  ");
	for (unsigned int i = 0; i < 16; i++) {
		if (i < size && ISASCII(memory[i])) {
			printf("%c", memory[i]);
		} else if (i < size) {
			printf(".");
		} else {
			printf(" ");
		}
	}
}