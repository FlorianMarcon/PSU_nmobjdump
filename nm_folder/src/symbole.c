/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** symbol
*/

#include <elf.h>
#include "nm.h"

static flags_t		localflags[] = {
	{ STT_NOTYPE, SHT_PROGBITS, 3, 'd' },
	{ STT_NOTYPE, SHT_PROGBITS, 6, 't' },
	{ STT_OBJECT, SHT_DYNAMIC, 3, 'd' },
	{ STT_OBJECT, SHT_FINI_ARRAY, 3, 't' },
	{ STT_OBJECT, SHT_INIT_ARRAY, 3, 't' },
	{ STT_OBJECT, SHT_PROGBITS, 3, 'd' },
	{ STT_FUNC, SHT_PROGBITS, 6, 't' },
	{ STT_TLS, SHT_PROGBITS, 1027, 'd' }
};

static type_t		types[] = {
	{'B', SHT_NOBITS, SHF_ALLOC | SHF_WRITE},
	{'R', SHT_PROGBITS, SHF_ALLOC},
	{'D', SHT_PROGBITS, SHF_ALLOC | SHF_WRITE},
	{'U', SHT_NULL, 0},
	{'T', SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR},
	{'R', SHT_PROGBITS, 0}
};

#define LOWER(x) (x >= 'A' && x <= 'Z' ? x + 0x20 : x)

char	getSymbole(Elf64_Shdr *shdr, Elf64_Sym *sym)
{
	char type = '?';

	if ((sym->st_shndx != SHN_ABS && sym->st_shndx != SHN_COMMON) &&
	ELF64_ST_BIND(sym->st_info) == STB_LOCAL) {
		for (unsigned int i = 0; i < 8; i++) {
		if (shdr[sym->st_shndx].sh_type == localflags[i].type &&
		shdr[sym->st_shndx].sh_flags == localflags[i].flags)
		return (localflags[i].ch);
			}
		}
	for (unsigned int i = 0; i < 6; i++) {
		if (shdr[sym->st_shndx].sh_type == types[i].type
		&& shdr[sym->st_shndx].sh_flags == types[i].flags)
			type = types[i].ch;
	}
	type = ELF64_ST_BIND(sym->st_info) == STB_LOCAL ? LOWER(type) : type;
	type = ELF64_ST_BIND(sym->st_info) == STB_WEAK ? 'W' : type;
	if (type == 'W' && sym->st_shndx == 0)
		type = LOWER(type);
	type = type == '?' ? 't' : type;
return (type);
}