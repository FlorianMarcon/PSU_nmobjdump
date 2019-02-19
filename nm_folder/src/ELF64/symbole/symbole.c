/*
** EPITECH PROJECT, 2019
** nm_folder
** File description:
** symbol
*/

#include <elf.h>
#include "nm.h"

#define LOWER(x) (x >= 'A' && x <= 'Z' ? x + 0x20 : x)

char	ELF64_getSymbole(Elf64_Shdr *shdr, Elf64_Sym *sym)
{
char  c;

  if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE)
    c = 'u';
  else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK)
    {
      c = 'W';
      if (sym->st_shndx == SHN_UNDEF)
        c = 'w';
    }
  else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK && ELF64_ST_TYPE(sym->st_info) == STT_OBJECT)
    {
      c = 'V';
      if (sym->st_shndx == SHN_UNDEF)
        c = 'v';
    }
  else if (sym->st_shndx == SHN_UNDEF)
    c = 'U';
  else if (sym->st_shndx == SHN_ABS)
    c = 'A';
  else if (sym->st_shndx == SHN_COMMON)
    c = 'C';
  else if (shdr[sym->st_shndx].sh_type == SHT_NOBITS
       && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'B';
  else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym->st_shndx].sh_flags == SHF_ALLOC)
    c = 'R';
  else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    c = 'D';
  else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
       && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
    c = 'T';
  else if (shdr[sym->st_shndx].sh_type == SHT_DYNAMIC)
    c = 'D';
  else
    c = 't';
  if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL && c != 't')
    c += 32;
  return c;
}