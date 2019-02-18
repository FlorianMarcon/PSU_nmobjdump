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

int main(int argc, char const *argv[])
{
	void *p;
	int ret = 0;

	if (argc == 1) {
		printf("Try with \"aout\" and if not present return 1\n TO DO\n");
	}
	for (int i = 1; i < argc; i++) {
		if ((p = stock_file(argv[i])) != NULL) {
			nm(p);
		} else
			ret = 1;
	}
	return (ret);
}
