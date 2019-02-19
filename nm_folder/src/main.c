/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include "stock_file.h"
#include "nm.h"

int	process(const char *filename)
{
	char *p = stock_file(filename);
	int ret = 0;

	if (p == NULL)
		return (1);
	if (p[4] == 0x02)
		ret =  (ELF64_nm((void *)p));
	else if (p[4] == 0x02)
		printf("proccess 32\n");
	else
		printf("nm: %s: File format not recognized\n", filename);
	
	if (ret == 2) {
		dprintf(2, "nm: %s: no symbols\n", filename);
		return (0);
	}
	return (ret);
}

int main(int argc, char const *argv[])
{
	// void *p;
	int ret = 0;

	if (argc == 1) {
		printf("Try with \"aout\" and if not present return 1\n TO DO\n");
	}
	for (int i = 1; i < argc; i++) {
		ret += process(argv[i]);
	}
	return (ret);
}
