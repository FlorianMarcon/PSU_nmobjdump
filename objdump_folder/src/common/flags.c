/*
** EPITECH PROJECT, 2019
** PSU_nmobjdump
** File description:
** flags
*/

#include <stdio.h>
#include "common.h"
#include "objdump.h"

static const keyvalue_t flagsString[] = {
	{0x01, "HAS_RELOC"},
	{0x02, "EXEC_P"},
	{0x04, "HAS_LINENO"},
	{0x08, "HAS_DEBUG"},
	{0x10, "HAS_SYMS"},
	{0x20, "HAS_LOCALS"},
	{0x40, "DYNAMIC"},
	{0x80, "WP_TEXT"},
	{0x100, "D_PAGED"}
};
void	flags_init(flags_t *flags)
{
	if (flags == NULL)
		return;
	memset(flags, 0, sizeof(flags_t));
}
char	*flags_getString(int key)
{
	for (unsigned int i = 0; i < sizeof(flagsString) / sizeof(flagsString[0]); i++) {
		if (flagsString[i].key == key)
			return (flagsString[i].value);
	}
	return (NULL);
}

void	flags_display(flags_t *flags)
{
	bool *tmp = (bool *)flags;
	bool isfirst = true;

	if (flags == NULL)
		return;
	for (unsigned int i = 0; i <= sizeof(flags) / sizeof(bool); i++) {
		if (tmp[i] == true) {
			if (!isfirst)
				printf(", ");
			printf("%s", flags_getString(flagsString[i].key));
			isfirst = false;
		}
	}
	if (isfirst) {
		printf("BFD_NO_FLAGS");
	}
	printf("\n");
	//ADD NO FLAGS
}

unsigned int	flags_sum(flags_t *flags)
{
	bool *tmp = (bool *)flags;
	unsigned int total = 0;

	if (flags == NULL)
		return (0);
	for (unsigned int i = 0; i <= (sizeof(flags) / sizeof(tmp[0])); i++) {
		if (tmp[i] == true) {
			total += flagsString[i].key;
		}
	}
	return (total);
}